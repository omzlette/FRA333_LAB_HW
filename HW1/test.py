# import numpy as np

# # walkedPath = a_i = np.array([-4, -1]).reshape(2,1) # facing north
# # stepMatrix = np.array([[1],[1]]) # XYZ
# # turn left
# thetaL = (90*np.pi)/180
# # turn right
# # thetaR = (-45*np.pi)/180

# # COM = ""

# def testRotateMat(theta):
#     # rotation matrix
#     R = np.array([[np.cos(theta), -np.sin(theta)],
#                   [np.sin(theta), np.cos(theta)]])
#     return R

# # def rotateMatX(theta):
# #     return np.array([[1, 0, 0],
# #                         [0, np.cos(theta), -np.sin(theta)],
# #                         [0, np.sin(theta), np.cos(theta)]])

# # def rotateMatY(theta):
# #     return np.array([[np.cos(theta), 0, np.sin(theta)],
# #                         [0, 1, 0],
# #                         [-np.sin(theta), 0, np.cos(theta)]])

# # def rotateMatZ(theta):
# #     return np.array([[np.cos(theta), -np.sin(theta), 0],
# #                         [np.sin(theta), np.cos(theta), 0],
# #                         [0, 0, 1]])

# def idx2pos(i,j):
#   d = 1
#   a = np.array([3/2,np.math.sqrt(3)/2])*d*(i-1)
#   b = np.array([-3/2,np.math.sqrt(3)/2])*d*(j-1)
#   return a+b+np.array([0,np.math.sqrt(3)])

# # def pos2idx(x,y):
# #   a = (np.array([1/3,-1/3])*x).astype(int)
# #   b = (np.array([1/np.sqrt(3),1/np.sqrt(3)])*y).astype(int)
# #   return (a+b).astype(int)

# def pos2idx(x,y):
#   i = x+y*np.sqrt(3)/3
#   j = -x+y*np.sqrt(3)/3
#   return np.array([i, j])

# testArr = idx2pos(0,-1).reshape(2,1)
# # print(testArr)

# testArr = pos2idx(testArr[0], testArr[1])

# # print(testArr.reshape(2,1))
# a_i = [-4, -1]
# currentPos = idx2pos(a_i[0],a_i[1]).reshape(2,1)
# print(currentPos[1])
# print('-'*10)
# arr = np.array([-1,1])
# arr = idx2pos(arr[0], arr[1])
# w = [[-1, 0, -2, 0, 3, 4, 0, 4, -2, -3, 4, -4, -1, 5], [1, 0, -1, 5, 3, 4, 2, -5, 5, 3, -3, 3, -5, -4]]
# w = np.array(w).T
# print(w)
# print("-----------------")
# print(arr)
# print(pos2idx(arr[0],arr[1]))
# if any((pos2idx(arr[0],arr[1]) == w).all(1)):
#   print("ran into a wall")
# print((pos2idx(arr[0],arr[1]) == w).all(1))
# # # print([i for i in COM if i != '0'])
# print('-'*10)
# var1 = np.array([[-5.00000000e+00, -4.00000000e+00, -3.00000000e+00, -2.00000000e+00,
#   -1.00000000e+00, -1.00000000e+00, -1.11947488e-15, -8.69674703e-16,
#   -1.11947488e-15, -8.69674703e-16,  1.00000000e+00, -8.69674703e-16,
#   -1.11947488e-15,  1.00000000e+00, -1.11947488e-15, -8.69674703e-16,
#    1.00000000e+00, -8.69674703e-16, -1.11947488e-15, -1.14723046e-15,
#   -1.61907524e-15, -1.59131967e-15,  1.00000000e+00, -1.91513472e-15,
#    1.00000000e+00,  2.00000000e+00,  1.00000000e+00, -1.32301577e-15,
#    1.00000000e+00,  2.00000000e+00,  1.00000000e+00,  1.00000000e+00,
#    1.00000000e+00,  1.00000000e+00,  1.00000000e+00, -7.30896825e-16,
#    1.00000000e+00, -7.30896825e-16],
#  [-4.00000000e+00, -3.00000000e+00, -3.00000000e+00, -3.00000000e+00,
#   -3.00000000e+00, -4.00000000e+00, -3.00000000e+00, -2.00000000e+00,
#   -3.00000000e+00, -2.00000000e+00, -1.00000000e+00, -2.00000000e+00,
#   -3.00000000e+00, -2.00000000e+00, -3.00000000e+00, -2.00000000e+00,
#   -2.00000000e+00, -2.00000000e+00, -3.00000000e+00, -4.00000000e+00,
#   -5.00000000e+00, -4.00000000e+00, -4.00000000e+00, -5.00000000e+00,
#   -4.00000000e+00, -4.00000000e+00, -5.00000000e+00, -5.00000000e+00,
#   -4.00000000e+00, -4.00000000e+00, -4.00000000e+00, -3.00000000e+00,
#   -2.00000000e+00, -3.00000000e+00, -4.00000000e+00, -5.00000000e+00,
#   -5.00000000e+00, -5.00000000e+00]])
# print(var1)
# print('-'*10)
# var1 = var1.astype(int)
# print(var1)
# # def radians(angle):
# #   return angle * np.pi / 180

# # def trig(angle):
# #   r = radians(angle)
# #   return np.cos(r), np.sin(r)

# # def matrix(rotation):
# #   xC, xS = trig(rotation[0])
# #   yC, yS = trig(rotation[1])
# #   zC, zS = trig(rotation[2])
# #   Rotate_X_matrix = np.array([[1, 0, 0, 0],
# #                               [0, xC, -xS, 0],
# #                               [0, xS, xC, 0],
# #                               [0, 0, 0, 1]])
# #   Rotate_Y_matrix = np.array([[yC, 0, yS, 0],
# #                               [0, 1, 0, 0],
# #                               [-yS, 0, yC, 0],
# #                               [0, 0, 0, 1]])
# #   Rotate_Z_matrix = np.array([[zC, -zS, 0, 0],
# #                               [zS, zC, 0, 0],
# #                               [0, 0, 1, 0],
# #                               [0, 0, 0, 1]])
# #   return np.dot(Rotate_Z_matrix,np.dot(Rotate_Y_matrix, Rotate_X_matrix))

# # stepMatrix = np.matmul(matrix([0,0,theta],[0,0,0]), stepMatrix)
# # print(stepMatrix)
# # print(matrix([0,0,90],[1,1,0]))

import numpy as np

arr = [1,2,3,4,1]
arr2 = [0,0,0,0,0]
arrMap = map(lambda x,y: x+y, arr, arr2)
print(list(arrMap))
print('-'*10)

arrNp = np.array([[1,2],[3,4]])
powerFunc = np.vectorize(lambda x: x**2)
arrVec = powerFunc(arrNp)
print(arrVec)
print('-'*10)
print(np.vectorize(lambda x: x**2)(arrNp))
print('-'*10)

arrTest = np.array([[1,3]])
W = np.array([[1,2],
              [2,3],
              [3,4],
              [4,5]])
print(any((arrTest == W).all(1)))
print('-'*10)

A = np.array([[1],[4]])
print(A)
print('-'*10)

B = np.array([[1,4],[3,6],[7,8]]).T
print(B)
print('-'*10)

m = any((A == B).all(1))
print(m)
print('-'*10)

# com = '13322432430331402441344321344124034332440312031321040223421323134024043020301410324214112200423440124'
# com = com.replace('0','')
# print(com)
# print('-'*10)

# arrTest2 = np.array([[-1.50000000e+00, -1.50000000e+00,  2.22044605e-16,  1.50000000e+00, 3.00000000e+00],
#                     [-7.79422863e+00, -6.06217783e+00, -5.19615242e+00, -4.33012702e+00, -3.46410162e+00]])

# def pos2idx(pos):
#     linearTrans = np.array([[1/3, np.sqrt(3)/3],
#                             [-1/3, np.sqrt(3)/3]])
#     a = np.matmul(linearTrans, pos)
#     return np.vectorize(round)(a)

# print(pos2idx(arrTest2))
print('Testing variable address')
print('-'*10)
test1 = test2 = np.array([[1,2,3],[4,5,6]])
print(test1 is test2)
print('-'*10)
print('test1 id:', id(test1))
print('test2 id:', id(test2))
print('-'*10)
test1 = np.append(test1, [[7,8,9]], axis=0)
print(test1 is test2)
print('-'*10)
print('test1 id:', id(test1))
print('test2 id:', id(test2))
print('-'*10)
test1 = np.append(test1, [[7,8,9]], axis=0)
print(test1 is test2)
print('-'*10)
print('test1 id:', id(test1))
print('test2 id:', id(test2))
print('-'*10)

a = [1, 2, 3]
b = a
b.append(4)
print(a)
print(b)
print('-'*10)
print(id(a))
print(id(b))