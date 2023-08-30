#include "neural_network.h"
#include <stdlib.h>

#define MAT_AT(x, i, j) (x).get()[(i) * _cols + (j)]

static double rand_double()
{
	return (double) rand() / (double) RAND_MAX;
}

void NeuralNetwork::rand_parameters() {
  for(Layer l : _layers) {
    for(int i = 0; i < l.GetSize(); i++) {
      l.SetWEl(0, i, rand_double());
    }
  }

}

NeuralNetwork::NeuralNetwork(int input, int hidden, int output, int layers)
{
	_ninput_layers = input;
	_nhidden_layers = hidden;
	_noutput_layers = output;
	_nlayers = layers;

  _layers.resize(_nlayers);
}

void NeuralNetwork::Forward()
{
	for(int i = 0; i < _nlayers-2; i++){
	}
}



