#!/usr/bin/python3
import sys
import os
import rclpy
import numpy as np
from rclpy.node import Node
from rclpy.qos import QoSProfile
from builtin_interfaces.msg import Duration

from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray, Int64, Bool

class X2ProximityServer(Node):
    def __init__(self):
        super().__init__('proximity_server')
        self.rate = 10
        qos_profile = QoSProfile(depth=10)
        if len(sys.argv) > 0:
            self.choice = sys.argv[0]
        else:
            self.choice = 'forward'

        # Forward Kinematics
        # Subscriber
        self.joint_sub = self.create_subscription(JointState, 'joint_states', self.joint_sub_callback, 50)

        # Inverse Kinematics
        # Subscriber
        self.pos_sub = self.create_subscription(Float64MultiArray, 'via_points', self.pos_sub_callback, 50)

        # Publisher
        self.has_reach = self.create_publisher(Bool, 'hasReached', qos_profile)
        self.has_reach_timer = self.create_timer(1/self.rate, self.has_reach_timer_callback)

        self.clock = self.create_publisher(Int64, 'doppelt_clock', qos_profile)
        self.clock_timer = self.create_timer(1/1000, self.clock_timer_callback)
        self.clock_now = 0

        # Variable Declaration
        self.joint_q = np.array([0, 0, 0])
        self.old_q = [0, 0, 0]

    # FORWARD KINEMATICS ----------------------------------------------------------------------------
    def joint_sub_callback(self, msg:JointState):
        self.joint_q = msg.position
    
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

    # INVERSE KINEMATICS ----------------------------------------------------------------------------
    def pos_sub_callback(self, msg:Float64MultiArray):
        self.via_point = msg.data[3:6]

    def IK_pos(self, x, y, z):
        # Calculate the joint angles

        # Define the lengths of the links
        l1 = l3 = 0.15
        le = 0.2

        # Calculate the joint angles q1
        q1 = np.arctan2(y, x)

        # Calculate the joint angles q3
        c3 = ((z-l1)**2 + x**2 + y**2 - l3**2 - le**2)/(2*l3*le)

        # Check if the solution is impossible
        if c3**2 > 1:
            return self.old_q

        s3 = np.sqrt(1-c3**2)
        q3 = np.arctan2(s3, c3)

        # Calculate the joint angles q2
        s2 = (-le*s3)*np.sqrt(x**2 + y**2) + (l3 + le*c3)*(z-l1)
        c2 = (l3 + le*c3)*np.sqrt(x**2 + y**2) + (le*s3)*(z-l1)
        q2 = np.arctan2(s2, c2)

        q = [q1, q2, q3]
        self.old_q = q

        return q
            
    def has_reach_timer_callback(self):
        reach = Bool()
        reachflag = False
        if self.choice == "forward":
            pos_FK = self.FK(self.joint_q)
            pos_tolerance = [self.via_point[0]-pos_FK[0], self.via_point[1]-pos_FK[1], self.via_point[2]-pos_FK[2]]
            if np.linalg.norm(pos_tolerance) < 0.001:
                reachflag = True
            else:
                reachflag = False
                
        
        elif self.choice == "inverse":
            q_IK = self.IK_pos(self.via_point)
            q_tolerance = [q_IK[0]-self.joint_q[0], q_IK[1]-self.joint_q[1], q_IK[2]-self.joint_q[2]]
            if np.linalg.norm(q_tolerance) < 0.001:
                reachflag = True
            else:
                reachflag = False
        
        reach.data = reachflag
        self.has_reach.publish(reach)

    def clock_timer_callback(self):
        clock = Int64()
        self.clock_now += 1
        clock.data = self.clock_now
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