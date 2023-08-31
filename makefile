all: 
	g++ -std=c++20 -Wall -Werror -I "header" -c source/matrix.cpp
	g++ -std=c++20 -Wall -Werror -I "header" -c source/neural_network.cpp
	g++ -std=c++20 -Wall -Werror -I "header" -c source/layer.cpp
	g++ -std=c++20 -Wall -Werror -I "header" -c source/xor.cpp
	g++ -g matrix.o neural_network.o layer.o xor.o -o xor -lm

clean:
	rm -rf a.out xor
	rm -rf *.o
	

