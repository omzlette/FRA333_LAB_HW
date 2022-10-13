#!/usr/bin/python3
import numpy as np

# Declare Rate of the timer
rate = 10

# Declare Default Joint Values (q1, q2, q3, q4)
defaultJointCf = [0., 0., 0., 0.]

# Declare Link Lengths
linkLengths = [0.4, 0.15, 0.2]

# For changing degrees to radians
degree = np.pi / 180.0

# Declare Joint Names (same as in URDF)
jointName = ['joint_0_1', 'joint_1_2', 'joint_2_3', 'joint_3_4']

def FKEq(q:list, link:list):
    # Calculate the position of the end effector by using the forward kinematics equations.
    x = -(link[1] + link[2] + q[3])*np.sin(q[0])*np.cos(q[1])
    y = (link[1] + link[2] + q[3])*np.cos(q[0])*np.cos(q[1])
    z = link[0] + link[1]*np.sin(q[1]) + link[2]*np.sin(q[1]) + q[3]*np.sin(q[1])
    return x, y, z

def IKEq(pos:list, gamma:int, link:list):
    # Calculate the joint values by using the inverse kinematics equations.
    q1 = -np.arctan2(pos[0]/gamma, pos[1]/gamma)
    q2 = np.arcsin(np.sqrt(1-((pos[0]**2+pos[1]**2)/((np.sqrt(((pos[2]-link[0])**2)+pos[0]**2+pos[1]**2))**2))))
    q4 = -link[1] - link[2] + (np.sqrt(((pos[2]-link[0])**2)+pos[0]**2+pos[1]**2))
    return q1, q2, q4

def checkWSIK(pos:list):
    # Check if the position is in the workspace of the robot.
    ptInWS = np.sqrt(pos[0]**2 + pos[1]**2 + (pos[2]-linkLengths[0])**2)
    if((0.35 <= ptInWS <= 0.45) and (0.4 <= pos[2] <= 0.85)):
        return True
    return False

def checkWSFK(q:list):
    # Check if the joint values are in the workspace of the robot.
    if((0 <= q[1] <= np.pi) and 0 <= q[3] <= 0.1):
        return True
    return False