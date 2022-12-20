import sys
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # doppelt_kinematic Node
    display = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([FindPackageShare('doppelt_description'),
                                  'launch',
                                  'doppelt_desc.launch.py'])
            ])
        )

    control = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([FindPackageShare('doppelt_control'),
                                  'launch',
                                  'doppelt_ctrl.launch.py'])
            ])
        )

    ktype = LaunchConfiguration('kinematicsType')
    ktype_launch_arg = DeclareLaunchArgument('kinematicsType', default_value='forward')

    X2_proximity = Node(
        package = "doppelt_kinematics",
        executable = "proximity_server.py",
        arguments = [ktype]
    )

    X2_traject_tracking = Node(
        package = "doppelt_kinematics",
        executable = "traject_tracking_server.py"
    )

    return LaunchDescription([
        display,
        control,
        ktype_launch_arg,
        X2_proximity,
        X2_traject_tracking
    ])

def main(args=None):
    try:
        generate_launch_description()
    except KeyboardInterrupt:
        # quit
        sys.exit()

if __name__ == '__main__':
    main()