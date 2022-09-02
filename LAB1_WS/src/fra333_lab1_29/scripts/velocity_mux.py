#!/usr/bin/python3

# import all other neccesary libraries
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64
from geometry_msgs.msg import Twist
import sys

class VelocityMux(Node):
    def __init__(self):
        # get the rate from argument or default
        super().__init__('velocity_multiplexer')
        if len(sys.argv) > 2:
            self.rate = float(sys.argv[1])
            # self.rate = 5.0
        else:
            self.rate = 5.0
        # add codes here
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

        self.vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.timer = self.create_timer(1/self.rate, self.timer_callback)

        # additional attributes
        self.linear_vel = 0.0
        self.angular_vel = 0.0

        # additional attributes
        self.cmd_vel = Twist()
        self.get_logger().info(f'Starting {self.get_name()}')

    def linear_vel_sub_callback(self,msg:Float64):
        self.cmd_vel.linear.x = msg.data
        self.get_logger().info(f'This is linear;;;cmd_vel: {self.cmd_vel}, msg: {msg.data}\n\n')
    
    def angular_vel_sub_callback(self,msg:Float64):
        self.cmd_vel.angular.z = msg.data
        self.get_logger().info(f'This is angular;;;cmd_vel: {self.cmd_vel}, msg: {msg.data}\n\n')
    
    def timer_callback(self):
        msg = Twist()
        msg.linear.x = self.cmd_vel.linear.x
        msg.angular.z = self.cmd_vel.angular.z
        self.vel_pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    velMux = VelocityMux()
    rclpy.spin(velMux)
    velMux.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()
