#!/usr/bin/python3

# import all other neccesary libraries here
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64
from lab1_interfaces.srv import SetNoise
import numpy as np
import sys

class NoiseGenerator(Node):

    def __init__(self):
        super().__init__('noise_generator')
        # get the rate from argument or default
        if len(sys.argv)>2: 
            self.rate = float(sys.argv[1])
        else:
            self.rate = 5.0
        # add codes here

        # Declare Parameters
        self.declare_parameters(namespace = '', parameters = [('para', None)])
        
        # Create Publisher
        self.publisher = self.create_publisher(Float64, f'{self.get_namespace()}/noise', 10)

        # Create Service
        self.srv = self.create_service(SetNoise, f'{self.get_namespace()}/set_noise' , self.set_noise_callback)

        #Create Timer
        self.timer = self.create_timer(1/self.rate, self.timer_callback)

        # additional attributes
        # Set Mean and Variance
        self.mean = 0.0
        self.variance = 1.0

        self.get_logger().info(f'Starting {self.get_namespace()}/{self.get_name()} with the default parameter. mean: {self.mean}, variance: {self.variance}')
    
    def set_noise_callback(self,request:SetNoise.Request,response:SetNoise.Response):
        self.mean = request.mean.data
        self.variance = request.variance.data
        return response
    
    def timer_callback(self):
        msg = Float64()
        # Adding Random Generator
        msg.data = np.random.normalize(self.mean, np.sqrt(self.variance))
        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    scheduler = NoiseGenerator()
    rclpy.spin(scheduler)
    scheduler.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()
