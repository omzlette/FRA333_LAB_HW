#!/usr/bin/python3
from trackbeebot import BeeBot
import numpy as np

class MyBeeBot(BeeBot):
    def __init__(self,a_i):
        super().__init__(a_i)
        # Get the initial position (a_i) of the BeeBot on "Hexagonal Coordinate" 
        # and change it to "Cartesian Coordinate"
        self.walkedPos = self.currentPos = self.idx2pos(np.array([a_i]).reshape(2,1))
        # Declare the angle of rotation in radian, in this case we use 60 degrees
        # because the hexagonal grid is 60 degrees rotated
        self.theta = (60*np.pi)/180
        
    def rotateMat(self, theta):
        # This function is for creating a rotation matrix
        # ----------------------------------------------
        # "theta" is the angle of rotation in radian.
        # ----------------------------------------------
        # For this matrix, when we use 'negative' theta, it will rotate the matrix in clockwise direction
        # and when we use 'positive' theta, it will rotate the matrix in counter-clockwise direction.
        return np.array([[np.cos(theta), -np.sin(theta)],
                         [np.sin(theta), np.cos(theta)]])
    
    def wallCollision(self, W, pos):
        # This function is for checking if the BeeBot is going to collide with the wall
        # ----------------------------------------------
        # "W" is the wall matrix in the form of [[x1, y1], [x2, y2], ..., [xn, yn]].
        # "pos" is the next position of the BeeBot in the form of [[x], [y]].
        # ----------------------------------------------
        # The way this function works is by checking if the next position of the BeeBot (pos) can
        # be found in the wall matrix (W). If it can, then it means that the BeeBot is going
        # to collide with the wall.
        # ----------------------------------------------
        # Note: This function checks the position in the hexagonal coordinate.
        return True if any((self.pos2idx(pos).reshape(1,2) == W).all(1)) else False
    
    def idx2pos(self, pos):
        # This function is for changing hexagonal coordinate to cartesian coordinate
        # ----------------------------------------------
        # "pos" is the position of the BeeBot in the form of [[i], [j]].
        # ----------------------------------------------
        # The way this function works is by using linear transformation matrix to change
        # the position of the BeeBot from hexagonal coordinate to cartesian coordinate.
        linearTrans = np.array([[3/2, -3/2],
                                [np.sqrt(3)/2, np.sqrt(3)/2]])
        return np.matmul(linearTrans, pos)
    
    def pos2idx(self,pos):
        # This function is for changing cartesian coordinate to hexagonal coordinate
        # ----------------------------------------------
        # "pos" is the position of the BeeBot in the form of [[x], [y]].
        # ----------------------------------------------
        # The way this function works is by using linear transformation matrix to change
        # the position of the BeeBot from cartesian coordinate to hexagonal coordinate.
        linearTrans = np.array([[1/3, np.sqrt(3)/3],
                                [-1/3, np.sqrt(3)/3]])
        return np.vectorize(round)(np.matmul(linearTrans, pos))
    
    # The function 'idx2pos' and 'pos2idx' calculations are proven in the file: 'HW1\doc\FRA333_HW1_29_Calculation.pdf'
    
    def trackBeeBot(self, com, W):
        # This function is for tracking the BeeBot
        # ----------------------------------------------
        # "com" is the command string. It can contain '0', '1', '2', '3' or '4', eg. '112340213'
        # "W" is the wall matrix in the form of [[x1,x2,...,xn], [y1,y2,...,yn]].
        # ----------------------------------------------
        # The way this function works is by using the command string to determine
        # the direction of the BeeBot. If the command is '0', it will be removed
        # from the command string. 
        # If the command is '1', it will move the BeeBot forward. 
        # If the command is '2', it will move the BeeBot backward. 
        # If the command is '3', it will rotate the BeeBot to the left (counter-clockwise).
        # If the command is '4', it will rotate the BeeBot to the right (clockwise).
        # After the command ends, the function will return the position of the BeeBot in
        # both hexagonal coordinate and cartesian coordinate.
        # ----------------------------------------------
        # Note: Both the forward and backward command will be ignored if the next position is 
        # going to collide with the wall.
        stepMatrix = self.idx2pos(np.array([[1],[1]]))
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