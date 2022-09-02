#!usr/bin/python3
from re import L
from launch import LaunchDescription
from launch.actions import ExecuteProcess,DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, FindExecutable
def generate_launch_description():
    # create a place holder for launch description
    launch_description = LaunchDescription()

    ### Example for adding launch argument ###
    rate = LaunchConfiguration('rate')
    rate_launch_arg = DeclareLaunchArgument('rate',default_value='5.0')
    launch_description.add_action(rate_launch_arg)
    
    ### Example for adding a node ###
    turtleNode = Node(
        package='turtlesim',
        executable='turtlesim_node',
        parameters=[
            {'background_b':0},
            {'background_g':0},
            {'background_r':0},
        ]
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
    )
    
    # launch_description.add_action(turtleNode)
    # launch_description.add_action(linearNode)
    # launch_description.add_action(angularNode)
    # launch_description.add_action(velocityMuxNode)
    
    ### Example for execute a shell command in python script ###
    # vx = 1.0
    # wz = 1.0
    # pub_cmd_vel = ExecuteProcess(
    #     cmd = [[f'ros2 topic pub -r 10 /turtle1/cmd_vel geometry_msgs/msg/Twist "{{linear: {{x: {vx}, y: 0.0, z: 0.0}}, angular: {{x: 0.0, y: 0.0, z: {wz}}}}}"']],
    #     shell=True
    # )
    # launch_description.add_action(pub_cmd_vel)
    
    linearMean = 5.0
    linearVar = 0.3
    angularMean = 2.0
    angularVar = 4.0

    srv_linear_noise = ExecuteProcess(
        cmd=[[
            f'ros2 service call /linear/set_noise lab1_interfaces/srv/SetNoise \"{{mean: {{data: {linearMean}}}, variance: {{data: {linearVar}}}}}\"'
        ]],
        shell=True
    )
    srv_angular_noise = ExecuteProcess(
        cmd=[[
            f'ros2 service call /angular/set_noise lab1_interfaces/srv/SetNoise \"{{mean: {{data: {angularMean}}}, variance: {{data: {angularVar}}}}}\"'
        ]],
        shell=True
    )
    
    # launch_description.add_action(pub_linear_noise)
    # launch_description.add_action(pub_angular_noise)
    
    processToRun = [turtleNode, linearNode, angularNode, velocityMuxNode, srv_linear_noise, srv_angular_noise]
    for i in processToRun:
        launch_description.add_action(i)

    return launch_description

    