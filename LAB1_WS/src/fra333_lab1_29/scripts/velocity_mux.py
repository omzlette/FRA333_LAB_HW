#!/usr/bin/python3
import rclpy
from rclpy.node import Node

from std_msgs.msg import Float64
from geometry_msgs.msg import Twist

import sys

class VelocityMux(Node):
    def __init__(self):
        super().__init__('velocity_multiplexer')
        if len(sys.argv) > 2:
            self.rate = float(sys.argv[1])
        else:
            self.rate = 5.0

        self.linear_sub = self.create_subscription(
            Float64,
            '/linear/noise',
            self.linear_vel_sub_callback,
            10)

        self.angular_sub = self.create_subscription(
            Float64,
            '/angular/noise',
            self.angular_vel_sub_callback,
            10)

        self.vel_pub = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.timer = self.create_timer(1/self.rate, self.timer_callback)

        self.cmd_vel = Twist()

    def linear_vel_sub_callback(self,msg:Float64):
        self.cmd_vel.linear.x = msg.data
    
    def angular_vel_sub_callback(self,msg:Float64):
        self.cmd_vel.angular.z = msg.data
    
    def timer_callback(self):
        self.vel_pub.publish(self.cmd_vel)
        self.get_logger().info(f'Linear: {self.cmd_vel.linear.x}, Angular: {self.cmd_vel.angular.z}')

def main(args=None):
    rclpy.init(args=args)
    velMux = VelocityMux()
    rclpy.spin(velMux)
    velMux.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()