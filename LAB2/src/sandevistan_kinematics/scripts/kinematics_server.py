#!/usr/bin/python3
import sys
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile

from sandevistan_kinematics.robot_module import rate, defaultJointCf, linkLengths, degree, jointName, FKEq, IKEq, checkWS

from sensor_msgs.msg import JointState
from sandevistan_kinematics_interfaces.srv import GetPosition, SolveIK

class SandeStatePub(Node):
    def __init__(self):
        super().__init__('kinematics_server')

        qos_profile = QoSProfile(depth=10)
        self.jointPub = self.create_publisher(JointState, 'joint_states', qos_profile)
        self.jointPubTimer = self.create_timer(1/rate, self.jointPubTimerCallback)

        self.jointState = JointState()
        self.jointState.position = defaultJointCf

        self.setJoint = self.create_service(GetPosition, 'set_joints', self.setJointCallback)
        self.inverseKine = self.create_service(SolveIK, 'solve_ik', self.solveIKCallback)

        self.get_logger().info("SandeStatePub started")

    def jointPubTimerCallback(self):
        self.jointState.header.stamp = self.get_clock().now().to_msg()
        self.jointState.name = jointName
        self.jointPub.publish(self.jointState)

    def setJointCallback(self, request:GetPosition.Request, response:GetPosition.Response):
        [q1, q2, q3, q4] = request.joint.position[0:4]
        [q1, q2, q3] = [i*degree for i in [q1, q2, q3]]
        self.jointState.position = q = [q1, q2, q3, q4]
        x, y, z = FKEq(q, linkLengths)
        response.position.x = x
        response.position.y = y
        response.position.z = z
        return response

    def solveIKCallback(self, request:SolveIK.Request, response:SolveIK.Response):
        pos = [request.position.x, request.position.y, request.position.z]
        gamma = request.armconfig
        q3 = request.jointconfig*degree
        q1, q2, q4 = IKEq(pos, gamma, linkLengths)
        IKSuccess = response.success = checkWS([q1, q2, q3, q4])
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
