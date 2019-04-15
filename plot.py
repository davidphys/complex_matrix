import matplotlib.pyplot as plt
import pylab

#Load our data.
data=pylab.loadtxt("out.txt")

#first column is the times
angles=data[:,0]
#second column is the angles
positions=data[:,1]
#third column is the real part of <\uparrow|\psi>
realpart=data[:,2]

fig, ax = plt.subplots()
ax.plot(angles,positions,label='$\\langle x\\rangle$')
ax.plot(angles,realpart,label='$\\operatorname{Re}(\\langle x|\psi\\rangle )$')

ax.set(xlabel='$\\theta$ (rads)',
       title='Position vs. angle plot')
ax.grid()
ax.legend()

fig.savefig("plot.png")
