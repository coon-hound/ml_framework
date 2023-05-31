#include "neural_network.h"
#include <stdlib.h>

#define MAT_AT(x, i, j) (x).get()[(i) * _cols + (j)]

NeuralNetwork::NeuralNetwork()
{
	_input_layers = 0;
	_hidden_layers = 0;
	_output_layers = 0;

	_layers = 0;
	
}

NeuralNetwork::NeuralNetwork(int input, int hidden, int output, int layers)
{
	_input_layers = input;
	_hidden_layers = hidden;
	_output_layers = output;
	_layers = layers;
	_x.reset(new Matrix[_layers]);
	_w.reset(new Matrix[_layers - 1]);
	_b.reset(new Matrix[_layers - 1]);
}

void NeuralNetwork::Forward()
{
	for(int i = 0; i < _layers-2; i++){
		_x[i + 1] = _w[i] * _x[i] + _b[i];
	}
}
