import os
import sys
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

import yaml

def generate_launch_description():
    with open(os.path.join(get_package_share_directory('doppelt_control'), 'config', 'via_points.yaml'), 'r') as f:
        allviaPts = yaml.load(f, Loader=yaml.FullLoader)

    with open(os.path.join(get_package_share_directory('doppelt_control'), 'config', 'tracker_config.yaml'), 'r') as f:
        trackerVal = yaml.load(f, Loader=yaml.FullLoader)
        Kp, Ki = trackerVal['Kp'], trackerVal['Ki']

    # doppelt_control Node
    X2_tracker = Node(
        package = "doppelt_control",
        executable = "tracker.py",
        parameters=[{'Kp': Kp, 'Ki': Ki}]
    )
    X2_generator = Node(
        package = "doppelt_control",
        executable = "generator.py"
    )
    X2_scheduler = Node(
        package = "doppelt_control",
        executable = "scheduler.py",
        # parameters=[{'viaPts': allviaPts}]
    )

    return LaunchDescription([
        X2_tracker,
        X2_generator,
        X2_scheduler
    ])

def main(args=None):
    try:
        generate_launch_description()
    except KeyboardInterrupt:
        # quit
        sys.exit()

if __name__ == '__main__':
    main()