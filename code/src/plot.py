import numpy as np
import matplotlib.pyplot as plt


mat = np.loadtxt('bin/test.csv',delimiter=',',dtype=float)
for i in range(1,len(mat)):
    plt.plot(mat[0],mat[i],label="n={}".format(i))
plt.xlabel("Values of z [fm]")
plt.ylabel("Values of psi [fm]^(-1/2)")
plt.title("Plot of the quantum harmonic oscillator's solutions (with an electron)")
plt.legend()
plt.show()