#!/usr/bin/python3
import sys
import os
import rclpy
import numpy as np
from rclpy.node import Node
from rclpy.qos import QoSProfile
from builtin_interfaces.msg import Duration

from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray

class X2TrajectTrack(Node):
    def __init__(self):
        super().__init__('traject_tracking_server')
        self.rate = 10
        qos_profile = QoSProfile(depth=10)       

        # Create Subscriber
        self.ref_task_sub = self.create_subscription(Float64MultiArray, 'reference/task_states', self.ref_task_sub_callback, 50)

        # Create publisher
        self.ref_joint_pub = self.create_publisher(JointState, 'reference/joint_states', qos_profile)
        self.ref_joint_pub_timer = self.create_timer(1/self.rate, self.ref_joint_pub_timer_callback)

        # Variable Declaration
        self.end_pos = [0, 0, 0]
        self.end_vel = [0, 0, 0]

    def IK(self, x, y, z):
        # Calculate the joint angles
        # q = [q1, q2, q3, q4]
        # q = IKEq(x, y, z, linkLengths)
        # return q
        pass

    def ref_task_sub_callback(self, msg:JointState):
        self.end_pos = msg.data[0:3]
        self.end_vel = msg.data[3:6]

    def ref_joint_pub_timer_callback(self):
        # Publish Clock and Joint State
        joint_state = JointState()
        joint_state.header.stamp = self.get_clock().now().to_msg()
        joint_state.name = ['joint1', 'joint2', 'joint3']
        joint_state.position = [] # Get q from IK 

def main(args=None):
    rclpy.init(args=args)
    node = X2TrajectTrack()
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