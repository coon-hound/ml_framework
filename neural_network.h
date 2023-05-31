#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H
#include "matrix.h"

class NeuralNetwork
{
public:
	NeuralNetwork();
	NeuralNetwork(int input, int hidden, int output, int layers);
	void Forward();



private:
	int _input_layers;
	int _hidden_layers;
	int _output_layers;
	int _layers; //layers including input and output layers

	std::shared_ptr<Matrix[]> _x;
	std::shared_ptr<Matrix[]> _w;
	std::shared_ptr<Matrix[]> _b;

};

#endif //NEURAL_NETWORK_H
