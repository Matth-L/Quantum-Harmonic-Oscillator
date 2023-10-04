import numpy as np
import matplotlib.pyplot as plt


mat = np.loadtxt('../bin/test.csv',delimiter=',',dtype=float)
for i in range(1,len(mat)):
    plt.plot(mat[0],mat[i])
plt.show()