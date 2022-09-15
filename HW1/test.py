import numpy as np

# walkedPath = a_i = np.array([-4, -1]).reshape(2,1) # facing north
# stepMatrix = np.array([[1],[1]]) # XYZ
# turn left
thetaL = (90*np.pi)/180
# turn right
# thetaR = (-45*np.pi)/180

# COM = ""

def testRotateMat(theta):
    # rotation matrix
    R = np.array([[np.cos(theta), -np.sin(theta)],
                  [np.sin(theta), np.cos(theta)]])
    return R

# def rotateMatX(theta):
#     return np.array([[1, 0, 0],
#                         [0, np.cos(theta), -np.sin(theta)],
#                         [0, np.sin(theta), np.cos(theta)]])

# def rotateMatY(theta):
#     return np.array([[np.cos(theta), 0, np.sin(theta)],
#                         [0, 1, 0],
#                         [-np.sin(theta), 0, np.cos(theta)]])

# def rotateMatZ(theta):
#     return np.array([[np.cos(theta), -np.sin(theta), 0],
#                         [np.sin(theta), np.cos(theta), 0],
#                         [0, 0, 1]])

def idx2pos(i,j):
  d = 1
  a = np.array([3/2,np.math.sqrt(3)/2])*d*(i-1)
  b = np.array([-3/2,np.math.sqrt(3)/2])*d*(j-1)
  return a+b+np.array([0,np.math.sqrt(3)])

def pos2idx(x,y):
  d = 1
  a = np.array([1/3,-1/3])*d*x
  b = np.array([1/np.sqrt(3),1/np.sqrt(3)])*d*y
  return (a+b).reshape(2,1)

testArr = idx2pos(0,-1).reshape(2,1)
print(testArr)

testArr = pos2idx(testArr[0], testArr[1])

print(testArr)
# # print([i for i in COM if i != '0'])

# def radians(angle):
#   return angle * np.pi / 180

# def trig(angle):
#   r = radians(angle)
#   return np.cos(r), np.sin(r)

# def matrix(rotation):
#   xC, xS = trig(rotation[0])
#   yC, yS = trig(rotation[1])
#   zC, zS = trig(rotation[2])
#   Rotate_X_matrix = np.array([[1, 0, 0, 0],
#                               [0, xC, -xS, 0],
#                               [0, xS, xC, 0],
#                               [0, 0, 0, 1]])
#   Rotate_Y_matrix = np.array([[yC, 0, yS, 0],
#                               [0, 1, 0, 0],
#                               [-yS, 0, yC, 0],
#                               [0, 0, 0, 1]])
#   Rotate_Z_matrix = np.array([[zC, -zS, 0, 0],
#                               [zS, zC, 0, 0],
#                               [0, 0, 1, 0],
#                               [0, 0, 0, 1]])
#   return np.dot(Rotate_Z_matrix,np.dot(Rotate_Y_matrix, Rotate_X_matrix))

# stepMatrix = np.matmul(matrix([0,0,theta],[0,0,0]), stepMatrix)
# print(stepMatrix)
# print(matrix([0,0,90],[1,1,0]))