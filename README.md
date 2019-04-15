Complex Matrix Example Code
===

Compilation instructions: 
---

`g++ -o main main.cpp` takes main.cpp, compiles it into a program, and saves it to a file called "main".

`./main > out.txt` runs main, and pipes all of its text output to a file called out.txt.

`python plot.py` runs the python file plot.py, which outputs an image of the wavefunction over time.

You should see the following image generated:

![Rotating spin 1/2 particle plot](plot.png)

Physics of what's going on
---

![](latexcode.png)


I chose the rotation of a spin $\frac{1}{2}$ particle as an example problem where I raise a $2\times 2$ matrix to the $N^{th}$ power. For your homework,
you'll be raising a $600\times 600$ matrix to the $N^{th}$ power!

I wanted to simulate rotating an electron about the $\hat{x}$
axis by an angle theta. 
This is realized by the operator $U(\theta)=e^{i \frac{\theta}{2}\sigma_x}$. 
Exponentiation can be approximated by $e^x\approx \left(1+\frac{x}{N}\right)^N$ for large $N$, so the complex matrix that we'll raise to the $N^{th}$ power
is $1+\frac{i\theta \sigma_x}{2N}$.

Finally, we want to measure operators like the position operator $\hat{x}$. 

If I start a particle in the state $|\uparrow\rangle$ and define 
$\hat{x}=|\uparrow\rangle\langle\uparrow|-|\downarrow\rangle\langle\downarrow|$,
then $\langle \hat{x}\rangle$ will just be $|\langle \uparrow|U|\uparrow\rangle|^2-|\langle \downarrow|U|\uparrow\rangle|^2$. If $U$ is a matrix, then this is just
$|U_{11}|^2-|U_{21}|^2$. If U is a matrix in row major format, then this is `norm(U[0])-norm(U[2])`.

Makefile instructions
---

I won't be using the makefile in class, but it wraps up all the commands nicely so that it's easy to run over and over again.

Type "make" to compile the c++ file.

Type "make run" to compile, run, and plot the code.

Type "make clean" to delete the executable, plot, and output data.

