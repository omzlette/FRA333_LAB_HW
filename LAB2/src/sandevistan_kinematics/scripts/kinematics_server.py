#!/usr/bin/python3
import sys
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile

from sandevistan_kinematics.robot_module import *

from sensor_msgs.msg import JointState
from sandevistan_kinematics_interfaces.srv import GetPosition, SolveIK

class SandeStatePub(Node):
    def __init__(self):
        super().__init__('kinematics_server')

        # Joint State Publisher
        qos_profile = QoSProfile(depth=10)
        self.jointPub = self.create_publisher(JointState, 'joint_states', qos_profile)
        self.jointPubTimer = self.create_timer(1/rate, self.jointPubTimerCallback)

        # Default Joint State
        self.jointState = JointState()
        self.jointState.name = jointName
        self.jointState.position = defaultJointCf

        # Create Service Servers for Set joint and Solve IK
        self.setJoint = self.create_service(GetPosition, 'set_joints', self.setJointCallback) # FK
        self.inverseKine = self.create_service(SolveIK, 'solve_ik', self.solveIKCallback) # IK

        self.get_logger().info("SandeStatePub started")

    def jointPubTimerCallback(self):
        # Publish Clock and Joint State
        self.jointState.header.stamp = self.get_clock().now().to_msg()
        self.jointPub.publish(self.jointState)

    def setJointCallback(self, request:GetPosition.Request, response:GetPosition.Response):
        # Callback Function for Set Joint Service
        # User will send joint values and this function will save the joint values into q1 to q4.
        # Then, it will return the position of the end effector (x, y, z) by calculating the kinematics of the robot.
        [q1, q2, q3, q4] = request.joint.position[0:4]
        [q1, q2, q3] = [i*degree for i in [q1, q2, q3]]
        self.jointState.position = q = [q1, q2, q3, q4]
        x, y, z = FKEq(q, linkLengths)
        response.position.x = x
        response.position.y = y
        response.position.z = z
        return response

    def solveIKCallback(self, request:SolveIK.Request, response:SolveIK.Response):
        # Callback Function for Solve IK Service
        # User will send the position of the end effector (x, y, z), gamma and q3.
        # Then, it will return the joint values (q1, q2, q3, q4) by calculating the inverse kinematics of the robot.
        # If the position is not reachable, it will return the joint values as 0.
        pos = [request.position.x, request.position.y, request.position.z]
        gamma = request.armconfig
        q3 = request.jointconfig*degree
        IKSuccess = checkWSIK(pos)
        q1, q2, q4 = IKEq(pos, gamma, linkLengths) if IKSuccess else 0, 0, 0
        IKSuccess = response.success = checkWSFK([q1, q2, q3, q4])
        self.jointState.position = response.joint.position = [q1, q2, q3, q4] if IKSuccess else defaultJointCf
        return response

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
