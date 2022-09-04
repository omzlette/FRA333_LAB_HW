#!usr/bin/python3
from struct import pack
from launch import LaunchDescription
from launch.actions import ExecuteProcess,DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
def generate_launch_description():
    # create a place holder for launch description
    launch_description = LaunchDescription()

    ### Example for adding launch argument ###
    rate = LaunchConfiguration('rate')
    rate_launch_arg = DeclareLaunchArgument('rate',default_value='5.0')
    launch_description.add_action(rate_launch_arg)
    
    ### Example for adding a node ###
    turtlesimNode = Node(
        package = 'turtlesim',
        executable = 'turtlesim_node',
        parameters=[
            {"background_b": 0},
            {"background_g": 0},
            {"background_r": 0}],
    )
    launch_description.add_action(turtlesimNode)

    linearNode = Node(
        package = 'fra333_lab1_29',
        executable ='noise_generator.py',
        namespace = 'linear',
        arguments = [rate],
    )
    launch_description.add_action(linearNode)
    
    angularNode = Node(
        package = 'fra333_lab1_29',
        executable = 'noise_generator.py',
        namespace = 'angular',
        arguments = [rate],
    )
    launch_description.add_action(angularNode)

    velocityNode = Node(
        package = 'fra333_lab1_29',
        executable = 'velocity_mux.py',
        arguments = [rate],
    )
    launch_description.add_action(velocityNode)

    ### Example for execute a shell command in python script ###
    linear_mean = 0.0
    linear_variance = 1.0
    angular_mean = 0.0
    angular_variance = 1.0

    launch_description.add_action(ExecuteProcess(
        cmd = [[f'ros2 service call /linear/set_noise lab1_interfaces/srv "{{mean: {{data: {linear_mean}}}, variance: {{data: {linear_variance}}}}}"']],
        shell=True
    ))
    
    launch_description.add_action(ExecuteProcess(
        cmd = [[f'ros2 service call /angular/set_noise lab1_interfaces/srv "{{mean: {{data: {angular_mean}}}, variance: {{data: {angular_variance}}}}}"']],
        shell=True
    ))

    return launch_description

    