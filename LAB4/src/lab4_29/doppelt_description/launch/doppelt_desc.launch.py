import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource

from launch.actions import IncludeLaunchDescription

from launch_ros.actions import Node
import xacro
from launch.substitutions import PathJoinSubstitution, LaunchConfiguration

from launch_ros.substitutions import FindPackageShare

def generate_launch_description():

    # Specify the name of the package and path to xacro file within the package
    pkg_name = 'doppelt_description'
    file_subpath = 'xacro/doppelt_robot.urdf.xacro'
    
    # Use xacro to process the file
    xacro_file = os.path.join(get_package_share_directory(pkg_name),file_subpath)
    robot_description_raw = xacro.process_file(xacro_file).toxml()

    # Create rviz2 node
    package_path = get_package_share_directory('doppelt_description')
    rviz_file_path = os.path.join(package_path, 'config', 'doppelt_description.rviz')

    rviz = Node(
       package='rviz2',
       executable='rviz2',
       name='rviz',
       arguments=['-d', rviz_file_path],
       output='screen')

    # doppelt_control Node
    X2_tracker = Node(
        package = "doppelt_control",
        executable = "tracker.py"
    )
    X2_generator = Node(
        package = "doppelt_control",
        executable = "generator.py"
    )
    X2_scheduler = Node(
        package = "doppelt_control",
        executable = "scheduler.py"
    )

    # doppelt_kinematic Node
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

    # Configure the node
    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[{'robot_description': robot_description_raw,
        'use_sim_time': True}] # add other parameters here if required
    )

    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('gazebo_ros'), 'launch'), '/gazebo.launch.py']),
        )

    spawn_entity = Node(package='gazebo_ros', executable='spawn_entity.py',
                    arguments=['-topic', 'robot_description',
                                '-entity', 'robot'],
                    output='screen')

    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner.py",
        arguments=["joint_state_broadcaster", "--controller-manager", "/controller_manager"],
    )
    
    robot_controller_spawner = Node(
        package="controller_manager",
        executable="spawner.py",
        arguments=["joint_group_velocity_controller", "--controller-manager", "/controller_manager"],
    )

    # Run the node
    return LaunchDescription([
        gazebo,
        rviz,
        node_robot_state_publisher,
        spawn_entity,
        joint_state_broadcaster_spawner,
        robot_controller_spawner,
        X2_tracker,
        X2_generator,
        X2_scheduler,
        ktype_launch_arg,
        X2_proximity,
        X2_traject_tracking
    ])


