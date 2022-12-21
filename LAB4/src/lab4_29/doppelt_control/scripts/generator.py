#!/usr/bin/python3
import sys
import os
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile

from std_msgs.msg import Float64MultiArray, Int64

class X2TrajGen(Node):
    def __init__(self):
        super().__init__('doppelt_generator')

        self.QoS = QoSProfile(depth=10)
        self.rate = 10

        self.refPosVel = self.create_publisher(Float64MultiArray, 'reference/task_states', self.QoS)
        
        self.points = [0, 0, 0, 0, 0, 0]
        self.dur = 0
        self.quinticStart = 0
        self.pointsDurSub = self.create_subscription(Float64MultiArray, 'via_points', self.pointsDurCallback, self.QoS)
        self.evalFlag = False

        self.clock = self.create_subscription(Int64, 'doppelt_clock', self.clockCallback, self.QoS)
        self.currTime = 0

        self.quinticEvalTimer = self.create_timer(1/self.rate, self.quinticEvalCallback)

    def pointsDurCallback(self, msg):
        self.points = msg.data[0:6]
        self.dur = msg.data[6]
        if not self.evalFlag:
            self.quinticStart = self.currTime
            self.evalFlag = True

    def QuinticTrajGen(self, t0, tf, q, v):
        quinticTrajMat = np.array([[1, t0, t0**2, t0**3, t0**4, t0**5],
                                   [0, 1, 2*t0, 3*t0**2, 4*t0**3, 5*t0**4],
                                   [0, 0, 2, 6*t0, 12*t0**2, 20*t0**3],
                                   [1, tf, tf**2, tf**3, tf**4, tf**5],
                                   [0, 1, 2*tf, 3*tf**2, 4*tf**3, 5*tf**4],
                                   [0, 0, 2, 6*tf, 12*tf**2, 20*tf**3]])
        inputParam = np.array([[q[0]],
                               [v[0]],
                               [0],
                               [q[1]],
                               [v[1]],
                               [0]])
        outputParam = np.linalg.inv(quinticTrajMat) @ inputParam
        return outputParam

    def QuinticEval(self, t, param):
        a_t = param[0] + param[1]*t + param[2]*t**2 + param[3]*t**3 + param[4]*t**4 + param[5]*t**5
        adot_t = param[1] + 2*param[2]*t + 3*param[3]*t**2 + 4*param[4]*t**3 + 5*param[5]*t**4
        return float(a_t), float(adot_t)

    def linearInterpolation(self, quinticParam):
        a_t = np.array(quinticParam[0:3])
        adot_t = np.array(quinticParam[3:6])
        pref = (1 - a_t) * self.points[0:3] + a_t * self.points[3:6]
        vref = adot_t * (self.points[3:6] - self.points[0:3])
        return list(pref) + list(vref)

    def quinticEvalCallback(self):
        if self.evalFlag:
            curTime = self.currTime - self.quinticStart
            if curTime > self.dur:
                self.evalFlag = False
            else:
                pointwVel = Float64MultiArray()
                quinticParam = [self.QuinticEval(curTime, self.QuinticTrajGen(0, self.dur, [self.points[0], self.points[3]], [0, 0]))[0],
                                self.QuinticEval(curTime, self.QuinticTrajGen(0, self.dur, [self.points[1], self.points[4]], [0, 0]))[0],
                                self.QuinticEval(curTime, self.QuinticTrajGen(0, self.dur, [self.points[2], self.points[5]], [0, 0]))[0],
                                self.QuinticEval(curTime, self.QuinticTrajGen(0, self.dur, [self.points[0], self.points[3]], [0, 0]))[1],
                                self.QuinticEval(curTime, self.QuinticTrajGen(0, self.dur, [self.points[1], self.points[4]], [0, 0]))[1],
                                self.QuinticEval(curTime, self.QuinticTrajGen(0, self.dur, [self.points[2], self.points[5]], [0, 0]))[1]]
                pointwVel.data = self.linearInterpolation(quinticParam)
                self.refPosVel.publish(pointwVel)

    def clockCallback(self, msg):
        self.currTime = msg.data/1000

        
def main(args=None):
    rclpy.init(args=args)
    node = X2TrajGen()
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