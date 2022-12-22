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
        self.rate = 50
        qos_profile = QoSProfile(depth=10)       

        # Create Subscriber
        self.ref_task_sub = self.create_subscription(Float64MultiArray, 'reference/task_states', self.ref_task_sub_callback, qos_profile)

        # Create publisher
        self.ref_joint_pub = self.create_publisher(Float64MultiArray, 'reference/joint_states', qos_profile)

        # Variable Declaration
        self.end_pos = [0, 0, 0]
        self.end_vel = [0, 0, 0]
        self.old_q = [0, 0, 0]
        self.old_vel = [0, 0, 0]
        self.old_qdot = [0, 0, 0]

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
            self.end_vel = self.old_vel
            return self.old_q

        s3 = np.sqrt(1-c3**2)
        q3 = np.arctan2(s3, c3)

        # Calculate the joint angles q2
        s2 = (-le*s3)*np.sqrt(x**2 + y**2) + (l3 + le*c3)*(z-l1)
        c2 = (l3 + le*c3)*np.sqrt(x**2 + y**2) + (le*s3)*(z-l1)
        q2 = np.arctan2(s2, c2)

        q = [q1, q2, q3]
        self.old_q = q
        self.old_vel = self.end_vel

        return q

    def Jacobian_Matrix(self,q):
        q1 = q[0]
        q2 = q[1]
        q3 = q[2]
        r01 = np.array([[np.cos(q1), -np.sin(q1), 0],
                        [np.sin(q1),  np.cos(q1), 0],
                        [      0,        0,       1]])
        r02 = np.array([[np.cos(q1)*np.cos(q2), -np.sin(q2)*np.cos(q1),  np.sin(q1)],
                        [np.sin(q1)*np.cos(q2), -np.sin(q1)*np.sin(q2), -np.cos(q1)],
                        [        np.sin(q2),          np.cos(q2),           0     ]])

        r03 = np.array([[-np.sin(q2)*np.sin(q3)*np.cos(q1) + np.cos(q1)*np.cos(q2)*np.cos(q3), -np.sin(q2)*np.cos(q1)*np.cos(q3) - np.sin(q3)*np.cos(q1)*np.cos(q2),  np.sin(q1)],
                        [-np.sin(q1)*np.sin(q2)*np.sin(q3) + np.sin(q1)*np.cos(q2)*np.cos(q3), -np.sin(q1)*np.sin(q2)*np.cos(q3) - np.sin(q1)*np.sin(q3)*np.cos(q2), -np.cos(q1)],
                        [                 np.sin(q2)*np.cos(q3) + np.sin(q3)*np.cos(q2),                 -np.sin(q2)*np.sin(q3) + np.cos(q2)*np.cos(q3),                    0   ]])
        rotateZ = np.array([0, 0, 1]).reshape(3, 1)

        angular_J01 = r01 @ rotateZ
        angular_J02 = r02 @ rotateZ
        angular_J03 = r03 @ rotateZ

        l1 = l3 = 0.15
        le = 0.2

        p01 = np.array([0, 0, l1])
        p02 = np.array([0, 0, l1])
        p03 = np.array([l3*np.cos(q1)*np.cos(q2), l3*np.sin(q1)*np.cos(q2), l1 + l3*np.sin(q2)])
        p_e = np.array([(l3*np.cos(q2) + le*np.cos(q2 + q3))*np.cos(q1), (l3*np.cos(q2) + le*np.cos(q2 + q3))*np.sin(q1), l1 + l3*np.sin(q2) + le*np.sin(q2 + q3)])

        linear_J01 = np.cross(angular_J01.reshape(1, 3), (p_e - p01)).reshape(3, 1)
        linear_J02 = np.cross(angular_J02.reshape(1, 3), (p_e - p02)).reshape(3, 1)
        linear_J03 = np.cross(angular_J03.reshape(1, 3), (p_e - p03)).reshape(3, 1)

        linear_Jacobian = np.concatenate((linear_J01, linear_J02, linear_J03), axis=1)
        # if np.abs(np.linalg.det(linear_jacobian)) < 0.001:
        #     self.end_vel = self.old_vel
        #     return self.old_qdot


        self.old_qdot = linear_Jacobian
        return linear_Jacobian

    def IK_vel(self, vx, vy, vz,q):
        lin_jacobian = self.Jacobian_Matrix(q)
        q_dot = np.linalg.pinv(lin_jacobian) @ np.array([vx, vy, vz]).reshape(3, 1)

        return list(q_dot.reshape(3,))

    def ref_task_sub_callback(self, msg):
        self.end_pos = list(msg.data[0:3])
        self.end_vel = list(msg.data[3:6])

        # Publish Clock and Joint State
        joint_state = Float64MultiArray()

        q = self.IK_pos(self.end_pos[0], self.end_pos[1], self.end_pos[2])

        q_dot = self.IK_vel(self.end_vel[0], self.end_vel[1], self.end_vel[2],q)
        joint_state.data = q + q_dot

        self.ref_joint_pub.publish(joint_state)
        

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