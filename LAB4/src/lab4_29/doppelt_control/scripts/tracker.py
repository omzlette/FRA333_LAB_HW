#!/usr/bin/python3
import sys
import os
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile

from sensor_msgs.msg import JointState
from trajectory_msgs.msg import JointTrajectory
from std_msgs.msg import Bool, Float64MultiArray, Int64
from doppelt_interfaces.srv import Enabler

import yaml
import numpy as np

class X2Tracker(Node):
    def __init__(self):
        super().__init__('doppelt_tracker')

        self.QoS = QoSProfile(depth=10)
        self.rate = 10

        self.jointState = JointState()
        self.jointState.position = [0., 0., 0.]
        self.enable = True
        self.sentEnableFlag = False

        self.trackerEnabler = self.create_service(Enabler, 'enabler', self.enable_callback)

        self.publishEnable = self.create_publisher(Float64MultiArray, '/joint_group_velocity_controller/commands', self.QoS)
        # self.pubTimer = self.create_timer(1/self.rate, self.pubTimerCallback)

        self.jointSsub = self.create_subscription(JointState, 'joint_states', self.jointStateCallback, self.QoS)
        self.refPosSub = self.create_subscription(Float64MultiArray, 'reference/joint_states', self.refPosVelCallback, self.QoS)

        self.clock = self.create_subscription(Int64, 'doppelt_clock', self.clockCallback, self.QoS)
        self.currTime = 0

        self.refpos, self.refvel = [0, 0, 0], [0, 0, 0]

        self.Kp = self.get_parameter('Kp')
        self.Ki = self.get_parameter('Ki')

    def enable_callback(self, request:Enabler.Request):
        self.enable = request.enable

    # def pubTimerCallback(self):
    #     if not self.sentEnableFlag and self.enable:
    #         self.sentEnableFlag = True
    #         self.get_logger().info(f"pos: {self.refpos} cur: {type(self.jointState.position)}")

    #         PI = Float64MultiArray()
    #         PI = self.PIControl(self.refpos, self.refvel, self.jointState.position, self.Kp, self.Ki, self.currTime)
    #         self.publishEnable.publish(PI)

    #     elif self.enable:
    #         self.sentEnableFlag = False

    def jointStateCallback(self, msg):
        self.jointState = msg
        # self.get_logger().info(f"Joint State Received: {self.jointState}")

        
    def refPosVelCallback(self, msg):
        self.refpos, self.refvel = msg.data[0:3], msg.data[3:6]
        # self.get_logger().info(f"Pos: {self.refpos} Vel: {self.refvel}")

        # if self.enable:
        # self.get_logger().info(f"pos: {self.refpos} cur: {type(self.jointState.position)}")
        PI = Float64MultiArray()
        PI.data = self.PIControl(self.refpos, self.refvel, self.jointState.position, self.Kp, self.Ki, self.currTime)
        # self.get_logger().info(f"PI: {PI}")
        self.publishEnable.publish(PI)

    def PIControl(self, refpos, refvel, curpos, Kp, Ki, time, limitInt=None):
        init = False
        if not init:
            I = np.array([0, 0, 0])
            prevError = np.array([0, 0, 0])
            init = True
        error = np.array(refpos) - np.array(curpos)
        P = Kp * error
        I = I + Ki * (error + prevError) * time

        if limitInt is not None:
            if I > limitInt[1]:
                I = limitInt[1]
            if I < limitInt[0]:
                I = limitInt[0]

        prevError = error

        return list(np.array(refvel) + P + I)

    def clockCallback(self, msg):
        self.currTime = msg.data/1000

def main(args=None):
    rclpy.init(args=args)
    node = X2Tracker()
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