#!/usr/bin/python3
import sys
import os
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile

from std_msgs.msg import Float64MultiArray
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from doppelt_interfaces.srv import Enabler

class X2TrajGen(Node):
    def __init__(self):
        super().__init__('doppelt_generator')

        self.QoS = QoSProfile(depth=10)
        self.rate = 10

        self.refPosVel = self.create_publisher(JointTrajectory, 'ref_pos_vel', self.QoS)
        self.refPosVelTimer = self.create_timer(1/self.rate, self.refPosVelTimerCallback)

    def QuinticTrajGen(self, t0, tf, q, v):
        quinticTrajMat = np.array([[1, t0, t0**2, t0**3, t0**4, t0**5],
                                   [0, 1, 2*t0, 3*t0**2, 4*t0**3, 5*t0**4],
                                   [0, 0, 2, 6*t0, 12*t0**2, 20*t0**3],
                                   [1, tf, tf**2, tf**3, tf**4, tf**5],
                                   [0, 1, 2*tf, 3*tf**2, 4*tf**3, 5*tf**4],
                                   [0, 0, 2, 6*tf, 12*tf**2, 20*tf**3]])
        inputParam = np.array([[q[0]],
                               [v[0]],
                               [0],
                               [q[1]],
                               [v[1]],
                               [0]])
        outputParam = np.linalg.inv(quinticTrajMat) @ inputParam
        return outputParam

    def QuinticEval(self, t, param):
        return param[0] + param[1]*t + param[2]*t**2 + param[3]*t**3 + param[4]*t**4 + param[5]*t**5

    def refPosVelTimerCallback(self):
        jointTraj = JointTrajectory()
        jointTraj.header.stamp = self.get_clock().now().to_msg()
        jointTraj.joint_names = ['joint_1', 'joint_2', 'joint_3']

        point = JointTrajectoryPoint()
        point.positions = [self.QuinticEval(self.get_clock().now().to_msg().sec, self.QuinticTrajGen(0, 5, [0, 1.57], [0, 0])),
                            self.QuinticEval(self.get_clock().now().to_msg().sec, self.QuinticTrajGen(0, 5, [0, 0], [0, 0])),
                            self.QuinticEval(self.get_clock().now().to_msg().sec, self.QuinticTrajGen(0, 5, [0, 0], [0, 0]))]


def main(args=None):
    rclpy.init(args=args)
    node = X2TrajGen()
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