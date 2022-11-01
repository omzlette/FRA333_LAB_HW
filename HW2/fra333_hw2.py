#!/usr/bin/python3
import numpy as np
import math
from HW2_utils import FKHW2

'''
    Name:   Tharnarch Thoranisttakul 63340500025
            Sirawich Lousomboon 63340500066
    Date:   10/29/2022
    Description:
'''

# Question 1
def endEffectorJacobianHW2(q):
    '''
    Input -
        q : format list 1x3 [[i_11, i_12, i_13]]
        q unit: rad
    ==================================================
    Procedure -
        1. Compute Rotation Matrix of Frame i vs. Global Frame, Position Matrix of Frame i vs. Global Frame and Position Matrix of End Effector vs. Global Frame.
        2. Declare a z-axis vector [0,0,1] in the global frame.
        3. Multiply each rotational matrix (R1, R2, R3) with the z-axis vector.
        4. Compute the cross product of angular Jacobian matrix and the position vector from each frame to the end effector.
        5. Concatenate the angular and linear Jacobian matrices.
    '''
    # 1. Compute Rotation Matrix of Frame i vs. Global Frame, Position Matrix of Frame i vs. Global Frame and Position Matrix of End Effector vs. Global Frame.
    R,P,_,p_e = FKHW2(q)

    '''
    where -
        R = Rotation Matrix of Frame i vs. Global Frame [3x3x4]
        P = Position Matrix of Frame i vs. Global Frame [3x4]
        p_e = Position Matrix of End Effector vs. Global Frame [1x3]
    '''
    R1,R2,R3 = R[:,:,0], R[:,:,1], R[:,:,2]
    P1,P2,P3 = P[:,0], P[:,1], P[:,2]

    # 2. Declare a z-axis vector [0,0,1] in the global frame.
    rotateZ = np.array([0, 0, 1]).reshape(3, 1)

    # 3. Multiply each rotational matrix (R1, R2, R3) with the z-axis vector.
    angularJ01 = R1 @ rotateZ
    angularJ02 = R2 @ rotateZ
    angularJ03 = R3 @ rotateZ
    # We will get angular Jacobian matrix [3x3]
    angularJacobian = np.concatenate((angularJ01, angularJ02, angularJ03), axis=1)
    
    # 4. Compute the cross product of angular Jacobian matrix and the position vector of each frame to the end effector.
    linearJ01 = np.cross(angularJ01.reshape(1, 3), (p_e - P1)).reshape(3, 1)
    linearJ02 = np.cross(angularJ02.reshape(1, 3), (p_e - P2)).reshape(3, 1)
    linearJ03 = np.cross(angularJ03.reshape(1, 3), (p_e - P3)).reshape(3, 1)
    # We will get linear Jacobian matrix [3x3]
    linearJacobian = np.concatenate((linearJ01, linearJ02, linearJ03), axis=1)

    '''
    Output -
        return format list 6x3
        [ [i_11, i_12, i_13],
          [i_21, i_22, i_23],
          [i_31, i_32, i_33],
          [i_41, i_42, i_43],
          [i_51, i_52, i_53],
          [i_61, i_62, i_63] ]
    '''
    # 5. Concatenate the angular and linear Jacobian matrices.
    return np.concatenate((angularJacobian, linearJacobian), axis=0)


    

# Question 2
def checkSingularityHW2(q):
    '''
    Input -
        q : format list 1x3 [[i_11, i_12, i_13]]
        q unit: rad
    ==================================================
    Procedure -
        1. Compute the Jacobian matrix, then select the last 3 rows (Linear Jacobian).
        2. Compute the determinant of the Jacobian matrix.
            - If the absolute of determinant is less than 0.001, then the robot is approaching a singularity state (True).
    '''
    
    # 1. Compute the Jacobian matrix, then select the last 3 rows (Linear Jacobian).
    endJacob = endEffectorJacobianHW2(q)[3:6,:]
    '''
    where -
        endJacob = End Effector Jacobian Matrix [6x3]
    ==================================================
    Output -
        return format bool
    '''
    # 2. Compute the determinant of the Jacobian matrix.
    #    - If the absolute of determinant is less than 0.001, then the robot is approaching a singularity state (True).
    return np.abs(np.linalg.det(endJacob)) < 0.001



# Question 3
def computeEffortHW2(q,w):
    '''
        q : format list 1x3 [[i_11, i_12, i_13]]
        q unit: rad
        type something here
    ==================================================
    Procedure -
        1. Compute the Rotational Matrix of End Effector vs. Global Frame (R_e) and Jacobian matrix (endJacob).
        2. Transpose wrench vector (w array) to make it a column vector and separate moment and force vector.
        3. Multiply moment and force vector with Rotational Matrix of End Effector vs. Global Frame (R_e) to get the wrench vector in the end effector frame.
        4. Multiply the wrench vector in the end effector frame with the transposed Jacobian matrix (endJacob) to get the joint effort vector.
        5. Transpose the joint effort vector to make it a row vector.
    '''
    # 1. Compute the Rotational Matrix of End Effector vs. Global Frame (R_e) and Jacobian matrix (endJacob).
    _,_,R_e,_ = FKHW2(q)
    endJacob = endEffectorJacobianHW2(q)

    '''
    where -
        R_e = Rotational Matrix of End Effector vs. Global Frame [3x3]
        endJacob = End Effector Jacobian Matrix [6x3]
    '''
    # 2. Transpose wrench vector (w array) to make it a column vector and separate moment and force vector.
    wt = np.transpose(w)

    # 3. Multiply moment and force vector with Rotational Matrix of End Effector vs. Global Frame (R_e) to get the wrench vector in the end effector frame.
    N0e = R_e @ wt[0:3]
    F0e = R_e @ wt[3:6]
    W0e = np.concatenate((N0e,F0e), axis = 0)

    # 4. Multiply the wrench vector in the end effector frame with the transposed Jacobian matrix (endJacob) to get the joint effort vector.
    # This is in column vector format. We need to transpose it to get the row vector.
    tau = np.transpose(endJacob) @ W0e

    '''
    Output -
        return format list 1x3
        [ [i_11, i_12, i_13] ]
    '''
    # 5. Transpose the joint effort vector to make it a row vector.
    return np.transpose(tau)
