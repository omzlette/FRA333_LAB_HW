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
            print("Wall Collision")
            return True
        return False
    
    def pos2idx(self,pos):
        linearTrans = np.array([[1/3, np.sqrt(3)/3],
                                [-1/3, np.sqrt(3)/3]])
        a = np.matmul(linearTrans, pos)
        return np.vectorize(round)(a)
    
    def trackBeeBot(self, com, W):
        W = W.T
        stepMatrix = self.idx2pos(1,1).reshape(2,1)
        
        if len(com) == 0:
            return self.walkedPath, self.currentPos
        
        for i in com.replace('0',''):
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
                
        return self.walkedPath, self.walkedPos
        
    # a_i is initial position
    # com is command {'0'->stop, '1'->forward, '2'->backward, '3'->turn right, '4'->turn left}
    # W is wall
