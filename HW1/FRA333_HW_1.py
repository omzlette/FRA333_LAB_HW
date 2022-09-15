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
        self.walkedPath = self.currentPos = self.idx2pos(a_i[0],a_i[1]).reshape(2,1)
        # self.walkedPath = self.currentPos = np.array(a_i).reshape(2,1)
        self.thetaL = (60*np.pi)/180
        self.thetaR = (-60*np.pi)/180
        print(self.currentPos)
    # a_i is initial position
    # c is command {'0'->stop, '1'->forward, '2'->backward, '3'->turn right, '4'->turn left}
    # o is obstacle

    # Left: XZY | Right: YZX
    # To Y-Axis: use RotateMatX | To X-Axis: use RotateMatZ | To Z-Axis: use RotateMatY
    # On Y: XZ | On X: YZ | On Z: XY
    
    # def rotateMatX(self, theta):
    #     return np.array([[1, 0, 0],
    #                      [0, np.cos(theta), -np.sin(theta)],
    #                      [0, np.sin(theta), np.cos(theta)]])
    
    # def rotateMatY(self, theta):
    #     return np.array([[np.cos(theta), 0, np.sin(theta)],
    #                      [0, 1, 0],
    #                      [-np.sin(theta), 0, np.cos(theta)]])
    
    # def rotateMatZ(self, theta):
    #     return np.array([[np.cos(theta), -np.sin(theta), 0],
    #                      [np.sin(theta), np.cos(theta), 0],
    #                      [0, 0, 1]])
    
    def rotateMat(self, theta):
        return np.array([[np.cos(theta), -np.sin(theta)],
                         [np.sin(theta), np.cos(theta)]])
    
    def wallCollision(self, W):
        if len(W) != 0:
            pass
        return False
    
    def pos2idx(self,x,y):
        pass
    
    def trackBeeBot(self, com, W):
        #get all commands that are not 0
        com = [i for i in com if i != '0']
        # get all obstacles (walls)
        W = np.array(W)
        stepMatrix = self.idx2pos(1,1).reshape(2,1)
        if len(com) == 0:
            return self.currentPos, 0
        
        for i in com:
            if i == '1':
                if not self.wallCollision(W):
                    self.currentPos = self.currentPos + stepMatrix
                self.walkedPath = np.append(self.walkedPath, self.currentPos, axis=1)
                print("forward")
            elif i == '2':
                if not self.wallCollision(W):
                    self.currentPos = self.currentPos - stepMatrix
                self.walkedPath = np.append(self.walkedPath, self.currentPos, axis=1)
                print("backward")
            elif i == '3':
                stepMatrix = np.matmul(self.rotateMat(self.thetaL), stepMatrix)
                print("left")
                print(stepMatrix)
            elif i == '4':
                stepMatrix = np.matmul(self.rotateMat(self.thetaR), stepMatrix)
                print("right")
            # else:
            #     print("Invalid command")
            #     return self.currentPos, 0
        return self.walkedPath
        
        
    # a_i is initial position
    # com is command {'0'->stop, '1'->forward, '2'->backward, '3'->turn right, '4'->turn left}
    # W is wall
    
    # add your code here
testBot = MyBeeBot([-4, -1])
P = testBot.trackBeeBot('3', [])
# print(P)