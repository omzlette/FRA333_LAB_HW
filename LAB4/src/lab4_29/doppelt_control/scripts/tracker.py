#!/usr/bin/python3
import sys
import os
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile

from sensor_msgs.msg import JointState
from trajectory_msgs.msg import JointTrajectory
from std_msgs.msg import Bool, Float64MultiArray
from doppelt_interfaces.srv import Enabler

class X2Tracker(Node):
    def __init__(self):
        super().__init__('doppelt_tracker')

        self.QoS = QoSProfile(depth=10)
        self.rate = 10

        self.jointState = JointState()
        self.enable = False
        self.sentEnableFlag = False

        self.trackerEnabler = self.create_service(Enabler, 'enable', self.enable_callback)

        self.publishEnable = self.create_publisher(Bool, 'joint_group_velocity_controller/commands', self.QoS)
        self.pubTimer = self.create_timer(1/self.rate, self.pubTimerCallback)

        self.jointSsub = self.create_subscription(JointState, 'joint_states', self.jointStateCallback, self.QoS)
        self.refPosSub = self.create_subscription(Float64MultiArray, 'ref_pos_vel', self.refPosVelCallback, self.QoS)

        self.refpos, self.refvel = [0, 0, 0], [0, 0, 0]

    def enable_callback(self, request:Enabler.Request):
        self.enable = request.enable

    def pubTimerCallback(self):
        if not self.sentEnableFlag and not self.enable:
            self.publishEnable.publish(Bool(data=self.enable))
            self.sentEnableFlag = True
        elif self.enable:
            self.publishEnable.publish(Bool(data=self.enable))
            self.sentEnableFlag = False

    def jointStateCallback(self, msg):
        self.jointState.header.stamp = self.get_clock().now().to_msg()
        self.jointState.name = msg.name
        self.get_logger().info(f"Joint State Received: {self.jointState}")

    def refPosVelCallback(self, msg):
        self.refpos, self.refvel = msg.data[0:3], msg.data[3:6]
        self.get_logger().info(f"Ref Pos Vel Received: {msg}")

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