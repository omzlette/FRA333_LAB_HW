import numpy as np

stepMatrix = np.array([[0],[1]]) # facing north

# turn left
thetaL = (60*np.pi)/180
# turn right
thetaR = (-60*np.pi)/180

def testRotateMat(theta):
    # rotation matrix
    R = np.array([[np.cos(theta), -np.sin(theta)],
                  [np.sin(theta), np.cos(theta)]])
    return R

stepMatrix = np.matmul(testRotateMat(thetaL), stepMatrix)
stepMatrix = np.matmul(testRotateMat(thetaL), stepMatrix)
stepMatrix = np.matmul(testRotateMat(thetaL), stepMatrix)

print(stepMatrix)