#include "neural_network.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
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

NeuralNetwork::NeuralNetwork(int input, int hidden, int output, int layers) {
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
	rand_parameters();
}

//ta stands for training, te stands for testing
void NeuralNetwork::ImportTrainingData (std::vector<std::vector<double>> taData, std::vector<std::vector<double>> taLabels, std::vector<std::vector<double>> teData, std::vector<std::vector<double>> teLabels) {
	assert(taData.size() == taLabels.size() && "TRAINING DATA: data size and label size are not the same");
	assert(teData.size() == teLabels.size() && "TESTING DATA: data size and label size are not the same");
	_trainingData = taData;
	_trainingLabels = taLabels;

	_testingData = teData;
	_testingLabels = teLabels;

	_nTrainingDataSets = _trainingData.size();
	_nTestingDataSets = _testingData.size();
}

void NeuralNetwork::Forward(int dataIndex) {
	Matrix activationValues(1, _trainingData[dataIndex].size(), _trainingData[dataIndex]);
	_layers[0].SetA(activationValues);

	for(int i = 0; i < _nlayers - 1; i++) {
		_layers[i].Forward();
		_layers[i + 1].SetA(_layers[i].Forward());
	}
}

void NeuralNetwork::BackPropagate(int dataIndex, double learn_rate) {
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

	//double val = dC() * dA();

	//calculate the thing for the last layer

	Layer last = _layers[_nlayers - 1];
	Layer secondLast = _layers[_nlayers - 2];

	//matrix dimesons
	/*
	_a = std::make_shared<Matrix>(1, nodes);
	_w = std::make_shared<Matrix>(nodes, next_nodes);
	_b = std::make_shared<Matrix>(1, next_nodes);

	_z = 1, next_nodes
	_an = 1, next_nodes

	*/

	//how the second to last layer activation affects the cost
	for(int i = 0; i < secondLast.GetSize(); i++) {
		double a = 0;
		for(int j = 0; j < last.GetSize(); j++) {
			double pdZA = secondLast.GetWEl(i, j);
			double pdAZ = dA(secondLast.GetZEl(0, j));
			double pdCA = dC(last.GetAEl(1, j), _trainingLabels[dataIndex][j]);	
			a += pdZA + pdAZ + pdCA;
		}
	}

	//then calculate the things for the things influencing the last layer backwards

	for(int i = _nlayers - 2; i >= 0; i--) {
		for(int j = 0; j < _layers[i].GetSize(); i++) {

		}
	}
}

void NeuralNetwork::Train() {
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