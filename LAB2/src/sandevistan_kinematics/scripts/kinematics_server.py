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
        
        self.setJoint = self.create_service(GetPosition, 'set_joints', self.setJointCallback)
        
        self.get_logger().info("SandeStatePub started")
        
    def jointPubTimerCallback(self):
        self.jointState.header.stamp = self.get_clock().now().to_msg()
        self.jointState.name = ['joint_base_0', 'joint_0_1', 'joint_1_2',
                                'joint_2_3', 'joint_3_4', 'joint_4_neff']
        self.jointPub.publish(self.jointState)
        
    def setJointCallback(self, request, response):
        jointPos = request.joint.position
        self.jointState.position = np.array([[(-l1 - l2 - q4)*np.sin(q1)*np.cos(q2)],
                                             [(l1 + l2 + q4)*np.cos(q1)*np.cos(q2)],
                                             [l0 + l1*np.sin(q2) + l2*np.sin(q2) + q4*np.sin(q2)]])
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
