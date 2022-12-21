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

        if len(sys.argv) > 2: 
            self.get_logger().info(f"Kp: {sys.argv[1],type(sys.argv[1])} Ki: {sys.argv[2],type(sys.argv[2])}")
            self.get_logger().info(str(sys.argv))
            self.Kp = float(sys.argv[1])
            self.Ki = float(sys.argv[2])
        else:
            self.get_logger().info("No Kp and Ki values given, using default values")
            self.Kp = 1
            self.Ki = 0

        self.QoS = QoSProfile(depth=10)
        self.rate = 10

        self.jointState = JointState()
        self.jointState.position = [0., 0., 0.]
        self.enable = True
        self.sentEnableFlag = False

        self.trackerEnabler = self.create_service(Enabler, 'enabler', self.enable_callback)
        self.enable_pub =  self.create_publisher(Bool, 'enable_debug', self.QoS)

        self.publishEnable = self.create_publisher(Float64MultiArray, '/joint_group_velocity_controller/commands', self.QoS)
        # self.pubTimer = self.create_timer(1/self.rate, self.pubTimerCallback)

        self.jointSsub = self.create_subscription(JointState, 'joint_states', self.jointStateCallback, self.QoS)
        self.refPosSub = self.create_subscription(Float64MultiArray, 'reference/joint_states', self.refPosVelCallback, self.QoS)

        self.clock = self.create_subscription(Int64, 'doppelt_clock', self.clockCallback, self.QoS)
        self.currTime = 0

        self.refpos, self.refvel = [0, 0, 0], [0, 0, 0]

        self.I = np.array([0., 0., 0.])
        self.prevOut = [0, 0, 0]

    def enable_callback(self, request:Enabler.Request, response:Enabler.Response):
        if request.enable:
            PI = Float64MultiArray()
            PI.data = self.PIControl(self.refpos, self.refvel, self.jointState.position, self.Kp, self.Ki)

            self.publishEnable.publish(PI)
        else:
            self.publishEnable.publish(Float64MultiArray(data=[0, 0, 0]))
        
        self.enable_pub.publish(Bool(data=request.enable))
        return response

    def jointStateCallback(self, msg):
        self.jointState = msg
        
    def refPosVelCallback(self, msg):
        self.refpos, self.refvel = msg.data[0:3], msg.data[3:6]

    def PIControl(self, refpos, refvel, curpos, Kp, Ki, limitOut=None):
        error = np.array(refpos) - np.array(curpos)

        P = Kp * error
        self.I += Ki * error
        
        output = list(np.array(refvel) + P + self.I)
        if limitOut:
            output = np.clip(output, -limitOut, limitOut)

        self.prevOut = output

        return output

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