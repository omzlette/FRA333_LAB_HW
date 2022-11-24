#!/usr/bin/python3
import sys
import os
import rclpy
import numpy as np
from rclpy.node import Node
import yaml

from sandevistan_interface.msg import IMUMessage

class calibrateIMU(Node):
    def __init__(self):
        super().__init__('calibrate')
        self.timestep = 10

        # IMU Subscriber
        self.imusub = self.create_subscription(IMUMessage, '/sandevistan_IMU', self.imu_subscribtion_callback, 100)

        # Declare Parameter
        self.linear_accelX = np.array([])
        self.linear_accelY = np.array([])
        self.linear_accelZ = np.array([])
        self.angular_velX = np.array([])
        self.angular_velY = np.array([])
        self.angular_velZ = np.array([])

    def imu_subscribtion_callback(self, msg:IMUMessage):
        self.linear_accelX = np.append(self.linear_accelX, msg.linear_acceleration[0])
        self.linear_accelY = np.append(self.linear_accelY, msg.linear_acceleration[1])
        self.linear_accelZ = np.append(self.linear_accelZ, msg.linear_acceleration[2])

        self.angular_velX = np.append(self.angular_velX, msg.angular_velocity[0])
        self.angular_velY = np.append(self.angular_velY, msg.angular_velocity[1])
        self.angular_velZ = np.append(self.angular_velZ, msg.angular_velocity[2])

    def calibrate(self):
        self.linear_accelX_mean = np.mean(self.linear_accelX)
        self.linear_accelY_mean = np.mean(self.linear_accelY)
        self.linear_accelZ_mean = np.mean(self.linear_accelZ)
        self.angular_velX_mean = np.mean(self.angular_velX)
        self.angular_velY_mean = np.mean(self.angular_velY)
        self.angular_velZ_mean = np.mean(self.angular_velZ)
    
def main(args=None):
    rclpy.init(args=args)
    node = calibrateIMU()
    startTime = node.get_clock().now().to_msg().sec
    print('Calibrating IMU')
    try:
        while node.get_clock().now().to_msg().sec - startTime < 10:
            rclpy.spin_once(node)
    except KeyboardInterrupt:
        print('repeater stopped cleanly')
    except BaseException:
        print('exception in repeater:', file=sys.stderr)
        raise
    finally:
        node.calibrate()
        currPath = os.path.dirname(os.path.realpath(__file__))
        with open(currPath + '/imu_calibration.yaml', 'w') as file:
            yaml.dump([{"linear_accelX": float(node.linear_accelX_mean)},
                {"linear_accelY": float(node.linear_accelY_mean)},
                {"linear_accelZ": float(node.linear_accelZ_mean)},
                {"angular_velX": float(node.angular_velX_mean)},
                {"angular_velY": float(node.angular_velY_mean)},
                {"angular_velZ": float(node.angular_velZ_mean)}], file)
        print('Calibration Done')
        node.destroy_node()
        rclpy.shutdown() 

if __name__=='__main__':
    main()
    