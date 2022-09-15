#!/usr/bin/python3
from trackbeebot import BeeBot
import matplotlib.pyplot as plt 
from matplotlib.patches import Polygon
import numpy as np
import math
import json

class MyBeeBot(BeeBot):
    def __init__(self,a_i):
        super().__init__(a_i)
        self.walkedPos = self.currentPos = self.idx2pos(a_i[0],a_i[1]).reshape(2,1)
        self.walkedPath = self.currentPath = np.array(a_i, dtype=np.int64).reshape(2,1)
        self.thetaL = (60*np.pi)/180
        self.thetaR = (-60*np.pi)/180
            
    def rotateMat(self, theta):
        return np.array([[np.cos(theta), -np.sin(theta)],
                         [np.sin(theta), np.cos(theta)]])
    
    def wallCollision(self, W, pos):
        if any((self.pos2idx(pos).reshape(1,2) == W).all(1)):
            return True
        return False
    
    def pos2idx(self,pos):
        linearTrans = np.array([[1/3, np.sqrt(3)/3],
                                [-1/3, np.sqrt(3)/3]])
        a = np.matmul(linearTrans, pos)
        return np.vectorize(round)(a)
    
    def trackBeeBot(self, com, W):
        com = [i for i in com if i != '0']
        W = W.T
        stepMatrix = self.idx2pos(1,1).reshape(2,1)
        
        if len(com) == 0:
            return self.walkedPath, self.currentPos
        
        for i in com:
            if i == '1':
                if not self.wallCollision(W, self.currentPos+stepMatrix):
                    self.currentPos = self.currentPos + stepMatrix
                    self.walkedPos = np.concatenate((self.walkedPos, self.currentPos), axis=1)
                    self.walkedPath = np.concatenate((self.walkedPath, self.pos2idx(self.currentPos)), axis=1)
            elif i == '2':
                if not self.wallCollision(W, self.currentPos-stepMatrix):
                    self.currentPos = self.currentPos - stepMatrix
                    self.walkedPos = np.concatenate((self.walkedPos, self.currentPos), axis=1)
                    self.walkedPath = np.concatenate((self.walkedPath, self.pos2idx(self.currentPos)), axis=1)
            elif i == '3':
                stepMatrix = np.matmul(self.rotateMat(self.thetaL), stepMatrix)
            elif i == '4':
                stepMatrix = np.matmul(self.rotateMat(self.thetaR), stepMatrix)
        # self.walkedPath = np.array([[round(i) for i in self.walkedPath[0]],
        #                             [round(i) for i in self.walkedPath[1]]])
        return self.walkedPath, self.walkedPos
        
    # a_i is initial position
    # com is command {'0'->stop, '1'->forward, '2'->backward, '3'->turn right, '4'->turn left}
    # W is wall
    
    # add your code here
# np.set_printoptions(suppress=True)
# testBot = MyBeeBot([-5, -4])
# C = '13322432430331402441344321344124034332440312031321040223421323134024043020301410324214112200423440124'
# # C = '1'
# W = np.array([[-1, 0, -2, 0, 4, 3, 5, -3, 3, 4, 1, 5, 3, -5], [1, 0, -1, 5, -5, -1, 5, -4, 0, -1, 3, 0, 0, -4]])
# # W = np.array([[],[]])
# A, P = testBot.trackBeeBot(C, W)
# print(A)
# print('----------------')
# print(A.astype(np.int64))
# print('----------------')
# print(A[0][10])
# print('----------------')
# print(A[0][10].astype(np.int64))
# print('----------------')
# testVar = 0.9
# print(int(testVar))
# print(round(testVar))
# print(P)

# testBot = MyBeeBot([0, -5])
# C = '132'
# W = np.array([[],[]])
# A, P = testBot.trackBeeBot(C, W)