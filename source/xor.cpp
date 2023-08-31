#include <iostream>
#include "neural_network.h"

int main()
{
	NeuralNetwork n(2, 0, 2, 2);

	n.Print();

	n.Forward();

	n.Print();
}

