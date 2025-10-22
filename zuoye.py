import numpy as np

v =np.array([0.416,0.4135,0.4215])
h = 1/(1+np.exp(-v))
print('h = ',h)
z = np.array([1.1577,1.2425])
y = 1/(1+np.exp(-z))
print("y = ",y)
print(0.1819*(-0.1391)*0.6038)