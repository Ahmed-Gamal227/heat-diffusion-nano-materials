import numpy as np
import matplotlib.pyplot as plt

for step in range(100):  # Number of time steps
    #data = np.loadtxt(f"heatmap_{step}.dat")
    data = np.loadtxt(f"D:/MyProjects/Vs-Code/Python/heat/heatmap_{step}.dat")

    x, y, z = data[:, 0], data[:, 1], data[:, 2]
    plt.tricontourf(x, y, z, levels=50, cmap="hot")
    plt.title(f"Heat Map at Step {step}")
    plt.colorbar(label="Temperature")
    plt.pause(0.1)
    plt.clf()
