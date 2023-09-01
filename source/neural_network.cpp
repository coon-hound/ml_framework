#include "neural_network.h"

#include <stdlib.h>
#include <queue>

#define MAT_AT(x, i, j) (x).get()[(i) * _cols + (j)]

void NeuralNetwork::rand_parameters() {
  for(Layer l : _layers) {
	l.RandParams();
  }
}

NeuralNetwork::NeuralNetwork(int input, int hidden, int output, int layers)
{
	_ninput_nodes = input;
	_nhidden_nodes = hidden;
	_noutput_nodes = output;
	_nlayers = layers;

	std::queue<int> q;
	q.push(_ninput_nodes);
	for(int i = 0; i < _nlayers - 2; i++) {
		q.push(hidden);
	}
	q.push(_noutput_nodes);

	for(int i = 0; i < _nlayers - 1; i++) {
		int next = q.front();
		q.pop();
		_layers.push_back(Layer(q.front(), next));
	}

	_layers.push_back(Layer(q.front(), 0));

	_layers[0].RandActivation();
	rand_parameters();
}

void NeuralNetwork::Forward() {
	for(int i = 0; i < _nlayers - 1; i++) {
		printf("hi\n");
		_layers[i].Forward().Print();
		printf("hi\n");
		_layers[i + 1].SetA(_layers[i].Forward());
	}
}

//debug
void NeuralNetwork::Print() {
	for(Layer l : _layers) {
		l.Print();
	}
}