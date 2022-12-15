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
        with open(os.path.join(os.path.dirname(__file__), '../'*5, 'src', 'lab4_29', 'doppelt_control', 'config', 'scheduler_config.yaml'), 'r') as f:
            self.allviaPts = yaml.load(f, Loader=yaml.FullLoader)

        self.enabler = self.create_client(Enabler, 'enabler')
        self.viaPtsPub = self.create_publisher(Float64MultiArray, 'via_points', QoS)

        self.reached = self.create_subscription(Bool, 'hasReached', self.reachedCallback, QoS)
        self.idxCount = 0

    def reachedCallback(self, msg):
        if msg.data:
            self.allviaPts.pop(0)
            self.idxCount += 1
            self.enabler.publish(Bool(data=False))
        else:
            viaPtsInit = self.allviaPts[self.idxCount]
            viaPtsFinal = self.allviaPts[self.idxCount+1]
            timeFinal = self.computeTime(viaPtsInit, viaPtsFinal)

            self.viaPts = viaPtsInit + viaPtsFinal + [timeFinal]
            self.viaPtsPub.publish(Float64MultiArray(data=self.viaPts))
            self.enabler.publish(Bool(data=True))

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