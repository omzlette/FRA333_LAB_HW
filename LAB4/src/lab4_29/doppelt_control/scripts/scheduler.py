#!/usr/bin/python3
import sys
import os
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile

from std_msgs.msg import Float64MultiArray, Bool
from doppelt_interfaces.srv import Enabler
import yaml

class X2Scheduler(Node):
    def __init__(self):
        super().__init__('doppelt_scheduler')

        QoS = QoSProfile(depth=10)

        # Receive via points
        via_point_path = '/home/valdeus1151/Y3T1/FRA333_LAB_HW/LAB4/src/lab4_29/doppelt_control/config/via_points.yaml'
        with open(via_point_path, 'r') as f:
            self.allviaPts = yaml.load(f, Loader=yaml.FullLoader)

        self.enabler = self.create_client(Enabler, 'enabler')
        self.viaPtsPub = self.create_publisher(Float64MultiArray, 'via_points', QoS)

        self.reached = self.create_subscription(Bool, 'hasReached', self.reachedCallback, QoS)
        self.idxCount = 0
        self.finidx = len(self.allviaPts) - 1

        self.hasReachedFlag = False

        self.viaPtsInit = [0,0,0]

    def reachedCallback(self, msg):
        
        if self.idxCount <= self.finidx:
            if msg.data and self.hasReachedFlag:
                self.allviaPts.pop(0)
                self.idxCount += 1
                self.hasReachedFlag = False

            elif not msg.data and not self.hasReachedFlag:
                viaPtsInit = self.allviaPts[self.idxCount]['coords']
                viaPtsFinal = self.allviaPts[self.idxCount+1]['coords']
                timeFinal = self.computeTime(viaPtsInit, viaPtsFinal)
                
                self.viaPts = viaPtsInit + viaPtsFinal + [timeFinal]
                self.viaPtsPub.publish(Float64MultiArray(data=self.viaPts))
                self.enabler.call_async(Bool(data=True))

                self.hasReachedFlag = True
        else:
            #stop
            viaPtsInit = viaPtsFinal
            viaPtsFinal = self.viaPtsInit
            timeFinal = self.computeTime(viaPtsInit, viaPtsFinal)
            self.viaPts = viaPtsInit + viaPtsFinal + [timeFinal]
            self.viaPtsPub.publish(Float64MultiArray(data=self.viaPts))
            
            if msg.data:
                self.enabler.call_async(Bool(data=False))

    def computeTime(self, viaPtsInit, viaPtsFinal):
        Vmax = 1.0
        Amax = 0.5
        Jmax = 0.5

        relativeDist = np.linalg.norm(np.array(viaPtsFinal) - np.array(viaPtsInit))

        time = (Amax/Jmax) + (Vmax/Amax) + (relativeDist/Vmax)
        return time

def main(args=None):
    rclpy.init(args=args)
    node = X2Scheduler()
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