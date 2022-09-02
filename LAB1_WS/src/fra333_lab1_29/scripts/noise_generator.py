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
        # get the rate from argument or default
        super().__init__('noise_generator')
        self.declare_parameters(namespace='',parameters=[('rate','mean')])
        if len(sys.argv)>2: 
            self.rate = float(sys.argv[1])
        else:
            self.rate = 5.0
        # add codes here
        self.noise_pub = self.create_publisher(Float64, f'{self.get_namespace()}/noise', 10)
        self.timer = self.create_timer(1/self.rate, self.timer_callback)

        self.set_noise_service = self.create_service(SetNoise, f'{self.get_namespace()}/set_noise', self.set_noise_callback)

        # additional attributes
        self.mean = 1.0
        self.variance = 0.1
    
    def set_noise_callback(self,request:SetNoise.Request,response:SetNoise.Response):
        self.mean = request.mean.data
        self.variance = request.variance.data
        return response
    
    def timer_callback(self):
        noise = Float64()
        noise.data = np.random.normal(self.mean,np.sqrt(self.variance))
        self.noise_pub.publish(noise)
        # self.get_logger().info(f'Starting {self.get_namespace()}/{self.get_name()} with the default parameter. mean: {self.mean}, variance: {self.variance}')
        # self.get_logger().info('Publishing: "%s"' % noise.data)
        self.get_logger().info(f'Arguments: {sys.argv}')

def main(args=None):
    rclpy.init(args=args)
    noiseGen = NoiseGenerator()
    rclpy.spin(noiseGen)
    noiseGen.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()
