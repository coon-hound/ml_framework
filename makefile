all: 
	gcc -std=c++17 -Wall -Werror -c matrix.cpp
	gcc -std=c++17 -Wall -Werror -c test.cpp
	gcc matrix.o test.o -o test

clean:
	rm -rf a.out test
	rm -rf *.o
	

