#include "neural_network.h"
#include <stdlib.h>

#define MAT_AT(x, i, j) (x).get()[(i) * _cols + (j)]

NeuralNetwork::NeuralNetwork()
{
	_layers = 0;
}

NeuralNetwork::NeuralNetwork(int layers)
{
	_layers = layers;
	_x.reset(new Matrix[_layers]);
	_w.reset(new Matrix[_layers]);
	_b.reset(new Matrix[_layers]);
}

void NeuralNetwork::Forward()
{
	for(int i = 0; i < _layers-2; i++){
		_x[i + 1] = _w[i] * _x[i] + _b[i];
	}
}
