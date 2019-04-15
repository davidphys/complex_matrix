
all: main

main: main.cpp
	g++ -o main main.cpp

run: main
	./main > out.txt
	python plot.py

clean: 
	-rm main
	-rm out.txt
	-rm plot.png
	
	
