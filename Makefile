all: 
	g++ scratchpad.cpp -o scratch
	clear

run: 
	./scratch

clean:
	rm scratch
	clear

test: test.cpp
	g++ -std=c++11 -w -I. -o test test.cpp