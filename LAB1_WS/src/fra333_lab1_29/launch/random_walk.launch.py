#!usr/bin/python3
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.actions import ExecuteProcess, DeclareLaunchArgument
def generate_launch_description():
    rate = LaunchConfiguration('rate')
    rate_launch_arg = DeclareLaunchArgument('rate',default_value='5.0')
    
    turtleNode = Node(
        package='turtlesim',
        executable='turtlesim_node',
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
        remappings=[
            ('/cmd_vel','/turtle1/cmd_vel'),
        ]
    )
    
    linearMean = 1.0
    linearVar = 0.1
    angularMean = 0.0
    angularVar = 3.0

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
    
    processToRun = [rate_launch_arg, turtleNode, linearNode, angularNode, velocityMuxNode, srv_linear_noise, srv_angular_noise]
    return LaunchDescription(processToRun)