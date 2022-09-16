#!/usr/bin/python3
from trackbeebot import BeeBot
import numpy as np

class MyBeeBot(BeeBot):
    def __init__(self,a_i):
        super().__init__(a_i)
        self.walkedPos = self.currentPos = self.idx2pos(a_i[0],a_i[1]).reshape(2,1)
        self.theta = (60*np.pi)/180 # positive = ccw, negative = cw
            
    def rotateMat(self, theta):
        return np.array([[np.cos(theta), -np.sin(theta)],
                         [np.sin(theta), np.cos(theta)]])
    
    def wallCollision(self, W, pos):
        return True if any((self.pos2idx(pos).reshape(1,2) == W).all(1)) else False
    
    def pos2idx(self,pos):
        linearTrans = np.array([[1/3, np.sqrt(3)/3],
                                [-1/3, np.sqrt(3)/3]])
        return np.vectorize(round)(np.matmul(linearTrans, pos))
    
    def trackBeeBot(self, com, W):
        stepMatrix = self.idx2pos(1,1).reshape(2,1)  
        for i in com.replace('0',''):
            if i == '1' and not self.wallCollision(W.T, self.currentPos + stepMatrix):
                self.currentPos = self.currentPos + stepMatrix
                self.walkedPos = np.concatenate((self.walkedPos, self.currentPos), axis=1)
            elif i == '2' and not self.wallCollision(W.T, self.currentPos-stepMatrix):
                self.currentPos = self.currentPos - stepMatrix
                self.walkedPos = np.concatenate((self.walkedPos, self.currentPos), axis=1)
            elif i == '3':
                stepMatrix = np.matmul(self.rotateMat(self.theta), stepMatrix)
            elif i == '4':
                stepMatrix = np.matmul(self.rotateMat(-self.theta), stepMatrix)
        return self.pos2idx(self.walkedPos), self.walkedPos
        
    # a_i is initial position
    # com is command {'0'->stop, '1'->forward, '2'->backward, '3'->turn right, '4'->turn left}
    # W is wall