#!/usr/bin/python3

import sys
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from geometry_msgs.msg import Point
from sensor_msgs.msg import JointState
from sandevistan_kinematics.robot_module import dummy_function, dummy_var

from sandevistan_kinematics_interfaces.srv import GetPosition

class SandeStatePub(Node):
    def __init__(self):
        super().__init__('kinematics_server')
        
        rate = 10
        
        qos_profile = QoSProfile(depth=10)
        self.jointPub = self.create_publisher(JointState, 'joint_states', qos_profile)
        self.jointPubTimer = self.create_timer(1/rate, self.jointPubTimerCallback)
        
        self.jointState = JointState()
        self.jointState.position = [0., 0., 0., 0., 0., 0.]
        
        self.linkLengths = [0.4, 0.15, 0.2]
        self.degree = np.pi / 180.0
        
        self.setJoint = self.create_service(GetPosition, 'set_joints', self.setJointCallback)
        
        self.get_logger().info("SandeStatePub started")
        
    def jointPubTimerCallback(self):
        self.jointState.header.stamp = self.get_clock().now().to_msg()
        self.jointState.name = ['joint_base_0', 'joint_0_1', 'joint_1_2',
                                'joint_2_3', 'joint_3_4', 'joint_4_neff']
        self.jointPub.publish(self.jointState)

    # def posMat(self, q1, q2, q3, q4):
    #     positionMat = np.array([[(-self.linkLengths[1] - self.linkLengths[2] - q4)*np.sin(q1)*np.cos(q2)],
    #                             [(self.linkLengths[1] + self.linkLengths[2] + q4)*np.cos(q1)*np.cos(q2)],
    #                             [self.linkLengths[0] + self.linkLengths[1]*np.sin(q2) + self.linkLengths[2]*np.sin(q2) + q4*np.sin(q2)]])
    #     return Point(x=positionMat[0, 0], y=positionMat[1, 0], z=positionMat[2, 0])
    
    def setJointCallback(self, request:GetPosition.Request, response:GetPosition.Response):
        # request.joint.header.stamp = self.get_clock().now().to_msg()
        request.joint.name = self.jointState.name
        [q1, q2, q3, q4] = request.joint.position[0:4]
        [q1, q2, q3] = [i*self.degree for i in [q1, q2, q3]]
        self.jointState.position = [0., q1, q2, q3, q4, 0.]
        self.get_logger().info('Incoming request\nPosition: ' + str(request.joint.position[0:4]))
        positionMat = np.array([[(-self.linkLengths[1] - self.linkLengths[2] - q4)*np.sin(q1)*np.cos(q2)],
                                [(self.linkLengths[1] + self.linkLengths[2] + q4)*np.cos(q1)*np.cos(q2)],
                                [self.linkLengths[0] + self.linkLengths[1]*np.sin(q2) + self.linkLengths[2]*np.sin(q2) + q4*np.sin(q2)]])
        self.get_logger().info('Position X: %.3f\nPosition Y: %.3f\nPosition Z: %.3f' % (positionMat[0, 0], positionMat[1, 0], positionMat[2, 0]))
        response.position.x = positionMat[0,0]
        response.position.y = positionMat[1,0]
        response.position.z = positionMat[2,0]
        return response

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
