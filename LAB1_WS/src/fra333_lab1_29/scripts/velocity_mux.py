#!/usr/bin/python3
import rclpy
from rclpy.node import Node

from std_msgs.msg import Float64
from geometry_msgs.msg import Twist

import sys

class VelocityMux(Node):
    def __init__(self):
        super().__init__('velocity_multiplexer')
        self.declare_parameter('turtlename','turtle')
        self.turtlename = self.get_parameter(
            'turtlename').get_parameter_value().string_value
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

        self.vel_pub = self.create_publisher(Twist, f'/{self.turtlename}/cmd_vel', 10)
        self.timer = self.create_timer(1/self.rate, self.timer_callback)

        self.linear_vel = 0.0
        self.angular_vel = 0.0

        self.cmd_vel = Twist()

    def linear_vel_sub_callback(self,msg:Float64):
        self.cmd_vel.linear.x = msg.data
    
    def angular_vel_sub_callback(self,msg:Float64):
        self.cmd_vel.angular.z = msg.data
    
    def timer_callback(self):
        msg = Twist()
        msg.linear.x = self.cmd_vel.linear.x
        msg.angular.z = self.cmd_vel.angular.z
        self.vel_pub.publish(msg)
        self.get_logger().info(f'Turtle Name: {self.turtlename} Linear: {msg.linear.x}, Angular: {msg.angular.z}')

def main(args=None):
    rclpy.init(args=args)
    velMux = VelocityMux()
    rclpy.spin(velMux)
    velMux.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()
