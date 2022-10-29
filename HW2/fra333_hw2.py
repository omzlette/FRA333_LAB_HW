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
        q : format list 1x3 [[i_11, i_12, i_13]]
        q unit: rad
        type something here
    '''

    # R = Rotation Matrix Frame i/Frame Global [3x3x4]
    # P = Position of Frame Frame i/Frame Global [3x4]
    # R_e = H0_e Rotation Matrix of End Effector/Frame Global [3x3]
    # p_e = Position Matrix of End Effector/Frame Global [1x3]
    R,P,R_e,p_e = FKHW2(q)

    R1 = (R[:,:,0])
    R2 = (R[:,:,1])
    R3 = (R[:,:,2])
    rotateZ = np.array([0,0,1]).reshape(3,1)

    angularJ01 = np.matmul(R1,rotateZ)
    angularJ02 = np.matmul(R2,rotateZ)
    angularJ03 = np.matmul(R3,rotateZ)

    angularJacobian = np.concatenate((angularJ01,angularJ02,angularJ03),axis = 1)

    velocityJ01 = np.cross(angularJ01.reshape(1,3),(p_e-P[:,0])).reshape(3,1)
    velocityJ02 = np.cross(angularJ02.reshape(1,3),(p_e-P[:,1])).reshape(3,1)
    velocityJ03 = np.cross(angularJ03.reshape(1,3),(p_e-P[:,2])).reshape(3,1)

    velocityJacobian = np.concatenate((velocityJ01,velocityJ02,velocityJ03),axis = 1)

    return np.concatenate((angularJacobian,velocityJacobian),axis = 0)

    '''
        return format list 6x3
        [ [i_11, i_12, i_13],
          [i_21, i_22, i_23],
          [i_31, i_32, i_33],
          [i_41, i_42, i_43],
          [i_51, i_52, i_53],
          [i_61, i_62, i_63] ]
    '''
    

# Question 2
def checkSingularityHW2(q):
    '''
        q : format list 1x3 [[i_11, i_12, i_13]]
        q unit: rad
        type something here
    '''
    endJacob = endEffectorJacobianHW2(q)[3:6,:]

    # if np.abs(np.linalg.det(endJacob)) != (np.linalg.det(endJacob)):
    #     print(np.abs(np.linalg.det(endJacob)))
    #     print((np.linalg.det(endJacob)))
    
    return True if np.abs(np.linalg.det(endJacob)) < 0.001 else False

    '''
        return format bool
    '''

# Question 3
def computeEffortHW2(q,w):
    '''
        q : format list 1x3 [[i_11, i_12, i_13]]
        q unit: rad
        type something here

        return format list 1x3
        [ [i_11, i_12, i_13] ]
    '''
