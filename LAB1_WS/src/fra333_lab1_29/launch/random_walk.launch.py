#!usr/bin/python3
from re import L
from tkinter import N
from launch import LaunchDescription
from launch.actions import ExecuteProcess,DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, FindExecutable
def generate_launch_description():
    launch_description = LaunchDescription()

    rate = LaunchConfiguration('rate')
    rate_launch_arg = DeclareLaunchArgument('rate',default_value='5.0')
    launch_description.add_action(rate_launch_arg)
    
    turtlename = LaunchConfiguration('turtle')
    turtlename_launch_arg = DeclareLaunchArgument('turtle',default_value='turtle1')
    launch_description.add_action(turtlename_launch_arg)
    
    turtleNode = Node(
        package='turtlesim',
        executable='turtlesim_node',
        # name='test',
        parameters=[
            {'background_b':0},
            {'background_g':0},
            {'background_r':0},
        ],
    )
    
    linearNode = Node(
        package='fra333_lab1_29',
        executable='noise_generator.py',
        namespace= 'linear',
        arguments=[rate],
    )
    
    angularNode = Node(
        package='fra333_lab1_29',
        executable='noise_generator.py',
        namespace= 'angular',
        arguments=[rate],
    )

    velocityMuxNode = Node(
        package='fra333_lab1_29',
        executable='velocity_mux.py',
        arguments=[rate],
        parameters=[
            {'turtlename':turtlename},
        ],
    )
    
    linearMean = 5.0
    linearVar = 0.3
    angularMean = 2.0
    angularVar = 4.0

    srv_linear_noise = ExecuteProcess(
        cmd=[[
            f'ros2 service call /linear/set_noise lab1_interfaces/srv/SetNoise "{{mean: {{data: {linearMean}}}, variance: {{data: {linearVar}}}}}"'
        ]],
        shell=True
    )
    srv_angular_noise = ExecuteProcess(
        cmd=[[
            f'ros2 service call /angular/set_noise lab1_interfaces/srv/SetNoise "{{mean: {{data: {angularMean}}}, variance: {{data: {angularVar}}}}}"'
        ]],
        shell=True
    )
    
    processToRun = [turtleNode, linearNode, angularNode, velocityMuxNode, srv_linear_noise, srv_angular_noise]
    for i in processToRun:
        launch_description.add_action(i)

    return launch_description

    