#!/usr/bin/python3

# import all other neccesary libraries here
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64
import sys

class NoiseGenerator(Node):

    def __init__(self):
        # get the rate from argument or default
        if len(sys.argv)>2: 
            self.rate = float(sys.argv[1])
        else:
            self.rate = 5.0
        # add codes here


        # additional attributes
        self.mean = 0.0
        self.variance = 1.0
        self.get_logger().info(f'Starting {self.get_namespace()}/{self.get_name()} with the default parameter. mean: {self.mean}, variance: {self.variance}')
    
    def set_noise_callback(self,request:SetNoise.Request,response:SetNoise.Response):
        # add codes here
        return response
    
    def timer_callback(self):
        # remove pass and add codes here
        pass

def main(args=None):
    # remove pass and add codes here
    pass

if __name__=='__main__':
    main()
