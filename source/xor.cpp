#include <iostream>
#include "neural_network.h"

int main()
{
	NeuralNetwork n(2, 3, 2, 4);

	n.Print();

	printf("--------------\n\n\n\n\n\n");

	n.Forward();

	n.Print();
}

