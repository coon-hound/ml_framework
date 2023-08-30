all: 
	g++ -std=c++20 -Wall -Werror -c matrix.cpp
	g++ -std=c++20 -Wall -Werror -c neural_network.cpp
	g++ -std=c++20 -Wall -Werror -c xor.cpp
	g++ -g matrix.o neural_network.o xor.o -o xor -lm

clean:
	rm -rf a.out xor
	rm -rf *.o
	

