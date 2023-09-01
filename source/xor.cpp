#include <iostream>
#include "neural_network.h"

int main()
{
	NeuralNetwork n(2, 0, 2, 2);

	n.Print();

	printf("got here\n");

	n.Forward();

	n.Print();
}

