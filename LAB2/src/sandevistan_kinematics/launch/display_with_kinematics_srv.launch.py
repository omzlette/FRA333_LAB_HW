#!/usr/bin/env python3
from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.actions import IncludeLaunchDescription, ExecuteProcess
from launch.substitutions import PathJoinSubstitution
from launch.launch_description_sources import PythonLaunchDescriptionSource

import sys


def generate_launch_description():

    ### How to launch another launch file ###
    #
    # You must specify the package, folder, and the name
    #
    display = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([FindPackageShare('sandevistan_description'),
                                  'launch',
                                  'display.launch.py'])
            ])
        )
    
    kinematics_server = Node(package='sandevistan_kinematics',
                             executable='kinematics_server.py',)
    
    # q1, q2, q3, q4 = 0.0, 0.0, 0.0, 0.0
                    
    # srv_jointState = ExecuteProcess(
    #     cmd=[[
    #         'ros2 service call /set_joints sandevistan_kinematics_interfaces/srv/GetPosition ',
    #         f'"{{joint: {{position: [{q1},{q2},{q3},{q4}]}}}}"'
    #     ]],
    #     shell=True)
    
    # [x, y, z] = [0.12, 0.3, 0.5]
    # [gamma1, gamma2] = [-1, 1]
    # q3 = 20.0
    
    # srv_IKSolve = ExecuteProcess(
    #     cmd=[[
    #         'ros2 service call /solve_ik sandevistan_kinematics_interfaces/srv/SolveIK ',
    #         f'"{{position: {{x: {x}, y: {y}, z: {z}}}, armconfig: [{gamma1}, {gamma2}], jointconfig: {q3}}}"'
    #     ]],
    #     shell=True)
    # Launch Description
    launch_description = LaunchDescription()
    launch_description.add_action(display)
    launch_description.add_action(kinematics_server)
    # launch_description.add_action(srv_jointState)
    # launch_description.add_action(srv_IKSolve)
    
    return launch_description

def main(args=None):
    try:
        generate_launch_description()
    except KeyboardInterrupt:
        # quit
        sys.exit()

if __name__ == '__main__':
    main()
    