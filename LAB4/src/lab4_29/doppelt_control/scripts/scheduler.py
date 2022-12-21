#!/usr/bin/python3
import sys
import os
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile

from std_msgs.msg import Float64MultiArray, Bool, Int64
from doppelt_interfaces.srv import Enabler
import yaml

class X2Scheduler(Node):
    def __init__(self):
        super().__init__('doppelt_scheduler')
        self.node_starttime = self.get_clock().now().to_msg().sec
        self.currtime = self.get_clock().now().to_msg().sec

        QoS = QoSProfile(depth=10)


        # Receive via points
        # via_point_path = '/home/valdeus1151/Y3T1/FRA333_LAB_HW/LAB4/src/lab4_29/doppelt_control/config/via_points.yaml'
        # with open(via_point_path, 'r') as f:
        #     self.allviaPts = yaml.load(f, Loader=yaml.FullLoader)

        self.enabler = self.create_client(Enabler, 'enabler')

        self.viaPtsPub = self.create_publisher(Float64MultiArray, 'via_points', QoS)

        self.reached = self.create_subscription(Bool, 'hasReached', self.reachedCallback, QoS)

        self.clock = self.create_subscription(Int64, 'doppelt_clock', self.clockCallback, QoS)
        self.currTime = 0

        self.hasReachedFlag = False

        self.viaPtsInit = [0,0,0]

        self.startX, self.startY, self.startZ = 0.25, 0, 0.15
        self.step = 0.1
        
        self.allviaPts = [{'coords': [0.35, 0, 0.15], 'marker': True}, # HOME
                            {'coords': [0, 0, 0.3], 'marker': False},
                            {'coords': [0.25, 0, 0.15], 'marker':True}] # STARTING POS

        # self.allviaPts = self.get_parameter('viaPts')

    def reachedCallback(self, msg):
        self.currtime = self.get_clock().now().to_msg().sec
        if self.currtime - self.node_starttime > 10:
        
            if len(self.allviaPts) >= 2:
                if msg.data and self.hasReachedFlag:
                    self.allviaPts.pop(0)
                    self.hasReachedFlag = False

                # elif not msg.data and not self.hasReachedFlag:
                viaPtsInit = self.allviaPts[0]['coords']
                viaPtsFinal = self.allviaPts[1]['coords']
                timeFinal = self.computeTime(viaPtsInit, viaPtsFinal)
                
                self.viaPts = viaPtsInit + viaPtsFinal + [timeFinal]
                self.viaPtsPub.publish(Float64MultiArray(data=self.viaPts))
                self.enabler.call_async(Enabler.Request(enable=True))

                self.hasReachedFlag = True
            else:
                #stop
                viaPtsInit = viaPtsFinal
                viaPtsFinal = self.viaPtsInit
                timeFinal = self.computeTime(viaPtsInit, viaPtsFinal)
                self.viaPts = viaPtsInit + viaPtsFinal + [timeFinal]
                self.viaPtsPub.publish(Float64MultiArray(data=self.viaPts))
                
                if msg.data:
                    self.enabler.call_async(Enabler.Request(enable=False))

    def computeTime(self, viaPtsInit, viaPtsFinal):
        Vmax = 1.0
        Amax = 0.5
        Jmax = 0.5

        relativeDist = np.linalg.norm(np.array(viaPtsFinal) - np.array(viaPtsInit))

        time = (Amax/Jmax) + (Vmax/Amax) + (relativeDist/Vmax)
        return time + self.currTime
    
    def clockCallback(self, msg):
        self.currTime = msg.data / 1000

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