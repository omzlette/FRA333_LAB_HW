#!/usr/bin/python3
import sys
import rclpy
import numpy as np
from rclpy.node import Node
from rclpy.qos import QoSProfile
from builtin_interfaces.msg import Duration

from sandevistan_interface.msg import IMUMessage
from trajectory_msgs.msg import JointTrajectory , JointTrajectoryPoint

class SandeStatePub(Node):
    def __init__(self):
        super().__init__('kinematic_server')

        self.timestep = 100
        qos_profile = QoSProfile(depth=10)

        # Create JointTrajectory and JointTrajectoryPoint
        self.JointTrajectory = JointTrajectory()
        self.point = JointTrajectoryPoint()

        # Declare Default Joint Values (q1, q2, q3)
        defaultJointCf = [0., 0., 0.]

        # Declare Joint Names (joint_1, joint_2, joint_3)
        self.JointTrajectory.joint_names = ['joint_1', 'joint_2', 'joint_3']
        self.JointTrajectory.position = defaultJointCf

        # Controller Publisher
        self.publish_topic = "/joint_trajectory_position_controller/joint_trajectory"
        self.controllerPub = self.create_publisher(JointTrajectory, self.publish_topic, qos_profile)

        # IMU Subscriber
        self.imusub = self.create_subscription(IMUMessage, '/sandevistan_IMU', self.imu_subscribtion_callback, self.timestep)

        # Create Timer
        self.timer = self.create_timer(1.0 / self.timestep, self.joint_timer_callback)

        # Declare Parameter
        self.linear_accel = [0., 0., 0.]
        self.angular_vel = [0., 0., 0.]
        self.pos = [0.25, 0., 0.15]
        self.oldpos = [0., 0., 0.]
        self.radtodeg = 180 / np.pi

    def imu_subscribtion_callback(self, msg:IMUMessage):
        self.linear_accel = msg.linear_acceleration
        self.angular_vel = msg.angular_velocity

    def PositionUpdate(self):
        g = 9.80665

        self.oldpos = self.pos

        StepVel = 0.1

        # IMU X to JointStage X
        if int(self.angular_vel[0]) != 0:
            self.pos[0] -= StepVel*(self.angular_vel[0] / g)

        # IMU Y to JointStage Y
        if int(self.angular_vel[1]) != 0:
            self.pos[1] -= StepVel*(self.angular_vel[1] / g)

        # IMU Z to JointStage Z
        if int(self.angular_vel[2]) != 0:
            self.pos[2] -= StepVel*(self.angular_vel[2] / g)
        
        qarray = self.IKEq(self.pos)

        # Check JointControl Values
        if qarray[1] >= 0 and qarray[1] <= np.pi:
            if qarray[2] >= -np.pi/2 and qarray[2] <= np.pi/2:
                self.point = qarray
            else:
                self.oldpos = self.pos
        else:
            self.oldpos = self.pos
    
    # Pos Control Algorithm
    def IKEq(self,pos:list):
        # Calculate the joint values by using the inverse kinematics equations.
        l0 = 0.15
        l2 = 0.15
        l3 = 0.1

        x = pos[0]
        y = pos[1]
        z = pos[2]

        # Calculate q1
        q1 = np.arctan2(y, x)

        # Calculate q3
        cosq3 = (x**2 + y**2 + (z - l0)**2 - l2**2 - l3**2) / (2 * l2 * l3)
        sinq3 = np.sqrt(1 - cosq3**2)
        q3 = np.arctan2(sinq3, cosq3)

        # Calculate q2
        cosq2 = ( (-l3*np.sin(q3)*y/np.sin(q1)) + ((l2 + l3*np.cos(q3))*(z-l0))  )
        sinq2 = ( (l2 + l3*np.cos(q3))*y/np.sin(q1) + (l3*np.sin(q3)*(z-l0)) )
        q2 = np.arctan2(cosq2, sinq2)
        qarray = [q1, q2, q3]
        return qarray

    def joint_timer_callback(self):
        # Publish Clock and Joint State
        self.JointTrajectory.points = self.point
        self.point.time_from_start = Duration(sec=1)
        self.controllerPub.publish(self.JointTrajectory)

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



