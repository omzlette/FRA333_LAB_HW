#!/usr/bin/python3

# import all other neccesary libraries
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64
from geometry_msgs.msg import Twist
import sys

class VelocityMux(Node):
    def __init__(self):
        super().__init__('velocity_mux')
        # get the rate from argument or default
        if sys.argv[1]:
            self.rate = float(sys.argv[1])
        else:
            self.rate = 5.0
        # add codes here

        # Create Subscriber
        self.linear_subscription = self.create_subscription(Float64, '/linear/noise', self.linear_vel_sub_callback, 10)
        self.angular_subscription = self.create_subscription(Float64, '/angular/noise', self.angular_vel_sub_callback, 10)

        # Create Publisher
        self.publisher = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)

        #Create Timer
        self.timer = self.create_timer(1/self.rate, self.timer_callback)

        # additional attributes
        self.cmd_vel = Twist()
        self.get_logger().info(f'Starting {self.get_name()}')

    def linear_vel_sub_callback(self,msg:Float64):
        self.linear_vel = msg.data
    
    def angular_vel_sub_callback(self,msg:Float64):
        self.angular_vel = msg.data
    
    def timer_callback(self):
        turtlemsg = Twist()
        turtlemsg.linear.x = self.linear_vel
        turtlemsg.angular.z = self.angular_vel
        self.publisher.publish(turtlemsg)

def main(args=None):
    rclpy.init(args=args)
    scheduler = VelocityMux()
    rclpy.spin(scheduler)
    scheduler.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()
