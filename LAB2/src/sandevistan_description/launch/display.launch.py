#!/usr/bin/env python3
import os
from re import sub
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
import sys

def generate_launch_description():
    package_path = get_package_share_directory('sandevistan_description')
    rviz_file_path = os.path.join(package_path, 'config', 'sandevistan_kinematics.rviz')
    robot_desc_path = os.path.join(package_path, 'robot', 'sandevistan.urdf')
    
    rviz = Node(
       package='rviz2',
       executable='rviz2',
       name='rviz',
       arguments=['-d', rviz_file_path],
       output='screen')

    with open(robot_desc_path, 'r') as infp:
        robot_description = infp.read()
    
    robot_state_publisher = Node(package='robot_state_publisher',
                                  executable='robot_state_publisher',
                                  output='screen',
                                  parameters=[
                                    {'use_sim_time': 'false'},
                                    {'robot_description': robot_description}
                                  ]
    )

    # Launch Description
    launch_description = LaunchDescription()
    toAddAction = [rviz, robot_state_publisher]
    for i in toAddAction:
        launch_description.add_action(i)
    
    return launch_description

def main(args=None):
    try:
        generate_launch_description()
    except KeyboardInterrupt:
        # quit
        sys.exit()

if __name__ == '__main__':
    main()
    