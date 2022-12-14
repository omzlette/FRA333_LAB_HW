#!/usr/bin/python3
import sys
import os
import rclpy
import numpy as np
from rclpy.node import Node
from rclpy.qos import QoSProfile
from builtin_interfaces.msg import Duration

from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray, Int64

class X2ProximityServer(Node):
    def __init__(self):
        super().__init__('proximity_server')
        self.rate = 10
        qos_profile = QoSProfile(depth=10)
        if len(sys.argv) > 2:
            self.choice = float(sys.argv[1])
        else:
            self.choice = 'forward'

        # Forward Kinematics
        # Subscriber
        self.FK_joint_sub = self.create_subscription(JointState, 'joint_states', self.FK_sub_callback, 50)
        # Publisher
        self.FK_end_pub = self.create_publisher(Float64MultiArray, 'task_states', qos_profile)
        self.FK_pub_timer = self.create_timer(1/self.rate, self.FK_pub_timer_callback)

        # Inverse Kinematics
        # Subscriber
        self.IK_end_sub = self.create_subscription(Float64MultiArray, 'via_points', self.IK_sub_callback, 50)
        # Publisher
        self.IK_joint_pub = self.create_publisher(JointState, 'via_joint_states', qos_profile)
        self.IK_pub_timer = self.create_timer(1/self.rate, self.IK_pub_timer_callback)

        self.clock = self.create_publisher(Int64, 'clock', qos_profile)
        self.clock_timer = self.create_timer(1/1000, self.clock_timer_callback)

        # Variable Declaration
        self.FK_q = [0, 0, 0]

    # FORWARD KINEMATICS ----------------------------------------------------------------------------

    def FK_sub_callback(self, msg:JointState):
        self.FK_q = msg.position
    
    def FK(self, qin):
        # Calculate the position of the end effector
        q = qin
        l1 = l3 = 0.15
        le = 0.2
        x = (l3*np.cos(q[1]) + le*np.cos(q[1] + q[2]))*np.cos(q[0])
        y = (l3*np.cos(q[1]) + le*np.cos(q[1] + q[2]))*np.sin(q[0])
        z = l1 + l3*np.sin(q[1]) + le*np.sin(q[1] + q[2])
        end_pos = [x, y, z]
        return end_pos

    def FK_pub_timer_callback(self):
        end_pos = Float64MultiArray()
        end_pos.data = self.FK(self.FK_q)
        self.FK_end_pub.publish(end_pos)

    # INVERSE KINEMATICS ----------------------------------------------------------------------------

    def IK_sub_callback(self, msg:Float64MultiArray):
        self.IK_via_point = msg.data[0][1]

    def IK_pos(self, x, y, z):
        # Calculate the joint angles

        # Define the lengths of the links
        l1 = l3 = 0.15
        le = 0.2

        # Calculate the joint angles q1
        q1 = np.arctan2(y, x)

        # Calculate the joint angles q3
        c3 = ((z-l1)**2 + x**2 + y**2 - l3**2 - le**2)/(2*l3*le)
        s3 = np.sqrt(1-c3**2)
        q3 = np.arctan2(s3, c3)

        # Calculate the joint angles q2
        s2 = (-le*s3)*np.sqrt(x**2 + y**2) + (l3 + le*c3)*(z-l1)
        c2 = (l3 + le*c3)*np.sqrt(x**2 + y**2) + (le*s3)*(z-l1)
        q2 = np.arctan2(s2, c2)

        q = [q1, q2, q3]
        
        return q
    
    def IK_pub_timer_callback(self):
        joint_state = JointState()
        joint_state.header.stamp = self.get_clock().now().to_msg()
        joint_state.name = ['joint1', 'joint2', 'joint3']
        joint_state.position = self.IK(self.IK_via_point) # Get q from IK 

    def clock_timer_callback(self):
        clock = Int64()
        clock.data += 1
        self.clock.publish(clock)

def main(args=None):
    rclpy.init(args=args)
    node = X2ProximityServer()
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