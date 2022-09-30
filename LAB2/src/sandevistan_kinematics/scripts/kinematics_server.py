#!/usr/bin/python3

import sys
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from geometry_msgs.msg import Point
from sensor_msgs.msg import JointState
from sandevistan_kinematics.robot_module import dummy_function, dummy_var

from sandevistan_kinematics_interfaces.srv import GetPosition, SolveIK

class SandeStatePub(Node):
    def __init__(self):
        super().__init__('kinematics_server')
        
        rate = 10
        
        qos_profile = QoSProfile(depth=10)
        self.jointPub = self.create_publisher(JointState, 'joint_states', qos_profile)
        self.jointPubTimer = self.create_timer(1/rate, self.jointPubTimerCallback)
        
        self.jointState = JointState()
        self.jointState.position = [0., 0., 0., 0.]
        
        self.linkLengths = [0.4, 0.15, 0.2]
        self.degree = np.pi / 180.0
        
        self.setJoint = self.create_service(GetPosition, 'set_joints', self.setJointCallback)
        self.inverseKine = self.create_service(SolveIK, 'solve_ik', self.solveIKCallback)
        
        self.get_logger().info("SandeStatePub started")
        
    def jointPubTimerCallback(self):
        self.jointState.header.stamp = self.get_clock().now().to_msg()
        self.jointState.name = ['joint_0_1', 'joint_1_2',
                                'joint_2_3', 'joint_3_4']
        self.jointPub.publish(self.jointState)
    
    def setJointCallback(self, request:GetPosition.Request, response:GetPosition.Response):
        [q1, q2, q3, q4] = request.joint.position[0:4]
        [q1, q2, q3] = [i*self.degree for i in [q1, q2, q3]]
        self.jointState.position = [q1, q2, q3, q4]
        self.get_logger().info('Incoming request\nPosition: ' + str(request.joint.position[0:4]))
        positionMat = np.array([[(-self.linkLengths[1] - self.linkLengths[2] - q4)*np.sin(q1)*np.cos(q2)],
                                [(self.linkLengths[1] + self.linkLengths[2] + q4)*np.cos(q1)*np.cos(q2)],
                                [self.linkLengths[0] + self.linkLengths[1]*np.sin(q2) + self.linkLengths[2]*np.sin(q2) + q4*np.sin(q2)]])
        self.get_logger().info('Position X: %.3f\nPosition Y: %.3f\nPosition Z: %.3f' % (positionMat[0, 0], positionMat[1, 0], positionMat[2, 0]))
        response.position.x = positionMat[0,0]
        response.position.y = positionMat[1,0]
        response.position.z = positionMat[2,0]
        return response
    
    def solveIKCallback(self, request:SolveIK.Request, response:SolveIK.Response):
        pos = [x, y, z] = [request.position.x, request.position.y, request.position.z]
        gamma = request.armconfig
        q3 = request.jointconfig*self.degree
        self.get_logger().info('Incoming request\nPosition X: %.3f\nPosition Y: %.3f\nPosition Z: %.3f' % (x, y, z))
        IKEq = np.array([[-np.arctan2(x/gamma, y/gamma)],
                         [np.arcsin(np.sqrt(1-((x**2+y**2)/((np.sqrt(((z-self.linkLengths[0])**2)+x**2+y**2))**2))))],
                         [-self.linkLengths[1] - self.linkLengths[2] + (np.sqrt(((z-self.linkLengths[0])**2)+x**2+y**2))]])
        jointConfig = [IKEq[0, 0], IKEq[1, 0], q3, IKEq[2, 0]]
        IKSuccess = response.success = self.checkIK(pos)
        self.jointState.position = response.joint.position = jointConfig if IKSuccess else [0., 0., 0., 0.]
        self.get_logger().info('Joint 1: %.3f\nJoint 2: %.3f\nJoint 3: %.3f\nJoint 4: %.3f' % (IKEq[0, 0], IKEq[1, 0], q3, IKEq[2, 0]))
        return response
    
    def checkIK(self, pos):
        ptInWS = np.sqrt(pos[0]**2 + pos[1]**2 + (pos[2] - self.linkLengths[0])**2)
        if((ptInWS >= 0.35 and ptInWS <= 0.45) and (pos[2] >= 0.4 and pos[2] <= 0.85)):
            return True
        return False
    
def main(args=None):
    rclpy.init(args=args)
    node = SandeStatePub()
    try:
        while rclpy.ok():
            rclpy.spin_once(node)
    except KeyboardInterrupt:
        print('repeater stopped cleanly')
    except BaseException:
        print('exception in repeater:', file=sys.stderr)
        raise
    finally:
        node.destroy_node()
        rclpy.shutdown() 

if __name__=='__main__':
    main()
