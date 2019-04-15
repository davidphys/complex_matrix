#Good example matplotlib plots are at:
#https://matplotlib.org/api/_as_gen/matplotlib.pyplot.legend.html
#https://matplotlib.org/gallery/lines_bars_and_markers/simple_plot.html
#Google is your friend here! If you don't know how to do X, google 
#"how to do X in matplotlib", or ask me, or ask a question on stackexchange.com.
#Be sure to cite your code if you copied and pasted a significant amount of someone 
#else's code (you don't have to cite documentation you use though)

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
