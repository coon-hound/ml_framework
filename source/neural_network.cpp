#include "neural_network.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>

#define MAT_AT(x, i, j) (x).get()[(i) * _cols + (j)]

static double sigmoid(double x) {
	return (1.f / (1.f + exp(-x)));
}

#define A(x) sigmoid(x)

static double dA(double x) {
	return A(x) * (1 - A(x));
}

static double dC(double a, double y) {
	return 2 * (a - y);
}

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
		_layers.push_back(Layer(next, q.front()));
	}

	_layers.push_back(Layer(q.front(), 0));

	_layers[0].RandActivation();
	rand_parameters();
}

void NeuralNetwork::Forward() {
	for(int i = 0; i < _nlayers - 1; i++) {
		_layers[i].Forward();
		_layers[i + 1].SetA(_layers[i].Forward());
	}
}

void NeuralNetwork::BackPropagate(double learn_rate) {
	//output layer
	//dC/dW = dC/dA * dA/dZ * dZ/dW
	//dC/dB = dC/dA * dA/dZ * dZ/dB
	//dC/dA = 2 * (A - Y)
	//dA/dZ = A * (1 - A)
	//dZ/dW = A
	//dZ/dB = 1	

	//we should have a secret sauce variable
	//double secret_sauce = dC/dA * dA / dZ

	//for each layer we iterate throught, we update the secret sauce
	//by multiplying on it the dA/dZ1 * dZ1/dA for each layer

	//for all the others, we multiply the secret sauce by dZ/dW

	//ya daz the backprop magik

	//iterate backwards

	double val = dC() * dA();

	for(int i = _nlayers - 2; i >= 0; i--) {
		for(int j = 0; j < _layers[i].GetSize(); i++) {

		}
	}
}

void NeuralNetwork::Train() {

	Forward();
	//backpropagation
	//output layer
	//dC/dW = dC/dA * dA/dZ * dZ/dW
	//dC/dB = dC/dA * dA/dZ * dZ/dB
	//dC/dA = 2 * (A - Y)
	//dA/dZ = A * (1 - A)
	//dZ/dW = A
	//dZ/dB = 1

}

//debug
void NeuralNetwork::Print() {
	for(Layer l : _layers) {
		l.Print();
	}
}