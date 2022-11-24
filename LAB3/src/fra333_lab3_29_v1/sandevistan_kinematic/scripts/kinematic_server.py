#!/usr/bin/python3
import sys
import os
import rclpy
import numpy as np
from rclpy.node import Node
from rclpy.qos import QoSProfile
from builtin_interfaces.msg import Duration
import yaml

from sandevistan_interface.msg import IMUMessage
from trajectory_msgs.msg import JointTrajectory , JointTrajectoryPoint

class SandeStatePub(Node):
    def __init__(self):
        super().__init__('kinematic_server')
        self.node_starttime = self.get_clock().now().to_msg().sec
        self.currtime = self.get_clock().now().to_msg().sec
        self.timestep = 10
        qos_profile = QoSProfile(depth=10)

        # Create JointTrajectory and JointTrajectoryPoint

        # Controller Publisher
        self.publish_topic = "/joint_trajectory_position_controller/joint_trajectory"
        self.controllerPub = self.create_publisher(JointTrajectory, self.publish_topic, qos_profile)

        # IMU Subscriber
        self.imusub = self.create_subscription(IMUMessage, '/sandevistan_IMU', self.imu_subscribtion_callback, 50)

        # Create Timer
        self.timer = self.create_timer(1.0 / self.timestep, self.joint_timer_callback)

        # Declare Parameter
        self.linear_accel = [0., 0., 0.]
        self.angular_vel = [0., 0., 0.]
        self.pos = [0.25, 0., 0.15]
        self.oldpos = self.pos
        self.radtodeg = 180 / np.pi
        self.poscylin = [0., 0., 0.]
        self.qarray = [0., 0., 0.]

        self.accelMean = [0., 0., 0.]
        self.anvelMean = [0., 0., 0.]

        currPath = os.path.dirname(os.path.realpath(__file__))
        with open(currPath + '/imu_calibration.yaml', 'r') as file:
            doc = yaml.full_load(file)

            self.accelMean[0] = doc[0]['linear_accelX']
            self.accelMean[1] = doc[1]['linear_accelY']
            self.accelMean[2] = doc[2]['linear_accelZ']
            self.anvelMean[0] = doc[3]['angular_velX']
            self.anvelMean[1] = doc[4]['angular_velY']
            self.anvelMean[2] = doc[5]['angular_velZ']


    def imu_subscribtion_callback(self, msg:IMUMessage):
        self.linear_accel = [msg.linear_acceleration[0] - self.accelMean[0],
                             msg.linear_acceleration[1] - self.accelMean[1],
                             msg.linear_acceleration[2] - self.accelMean[2]]
        self.angular_vel = [msg.angular_velocity[0] - self.anvelMean[0],
                            msg.angular_velocity[1] - self.anvelMean[1],
                            msg.angular_velocity[2] - self.anvelMean[2]]
        # self.linear_accel = msg.linear_acceleration
        # self.angular_vel = msg.angular_velocity

    def PositionUpdate(self):

        self.poscylin = [np.sqrt(self.pos[0]**2 + self.pos[1]**2), np.arctan2(self.pos[1], self.pos[0]), self.pos[2]]

        # Calculate the new position in cylindrical coordinates
        # IMU X to  X
        if np.round(self.linear_accel[0]) != 0:
            self.poscylin[0] += 0.001*np.abs(self.linear_accel[0])/self.linear_accel[0]

        # IMU Y to JointStage Y
        if np.round(self.linear_accel[1]) != 0:
            self.poscylin[1] += 0.001*np.abs(self.linear_accel[1])/self.linear_accel[1]

        # IMU Z to JointStage Z
        if np.round(self.linear_accel[2]) != 0:
            self.poscylin[2] += 0.001*np.abs(self.linear_accel[2])/self.linear_accel[2]
        
        # Convert the new position to cartesian coordinates
        self.pos = [self.poscylin[0]*np.cos(self.poscylin[1]), self.poscylin[0]*np.sin(self.poscylin[1]), self.poscylin[2]]

        self.IKEq()

    # Pos Control Algorithm
    def IKEq(self):
        # Calculate the joint values by using the inverse kinematics equations.
        l0 = 0.15
        l2 = 0.15
        l3 = 0.1
        x = float(self.pos[0])
        y = float(self.pos[1])
        z = float(self.pos[2])

        # Calculate q3
        if l2-l3 <= np.sqrt(x**2 + y**2 + (z - l0)**2) <= l2+l3 and x**2 + y**2 + z**2 + l0**2 >= 2*z*l0:
            self.get_logger().info('oh hi\n\n\n')
            # Calculate q1
            q1 = np.arctan2(y, x)

            cosq3 = (x**2 + y**2 + (z - l0)**2 - l2**2 - l3**2) / (2 * l2 * l3)
            sinq3 = np.sqrt(1 - cosq3**2)
            
            q3 = np.arctan2(sinq3, cosq3)

            # Calculate q2
            sinq2 = ((-l3*sinq3)*(y/np.sin(q1))) + ((l2 + (l3*cosq3))*(z-l0))
            cosq2 = (l2 + (l3*cosq3))*(y/np.sin(q1)) + ((l3*sinq3)*(z-l0))
            q2 = np.arctan2(sinq2, cosq2)
            self.oldpos = self.pos

            self.qarray = [float(q1), float(q2), float(q3)]
        
        else:
            self.pos = self.oldpos

    def joint_timer_callback(self):
        self.currtime = self.get_clock().now().to_msg().sec
        if self.currtime - self.node_starttime > 10:
            # Publish Clock and Joint State
            JointTrajec = JointTrajectory()
            point = JointTrajectoryPoint()
            self.PositionUpdate()
            # Check JointControl Values
            point.positions = self.qarray
            JointTrajec.joint_names = ['joint_1', 'joint_2', 'joint_3']
            point.time_from_start = Duration(sec=1)
            JointTrajec.points.append(point)
            self.controllerPub.publish(JointTrajec)

            self.get_logger().info('------------------------------------')
            self.get_logger().info(f'linear_accel: {self.linear_accel}')
            self.get_logger().info(f'poscylin: {self.poscylin}')
            self.get_logger().info(f'pos: {self.pos}')
            self.get_logger().info(f'q: {JointTrajec.points[0]}')

def main(args=None):
    rclpy.init(args=args)
    node = SandeStatePub()
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



