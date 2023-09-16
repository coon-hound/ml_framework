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
  for (Layer l : _layers) {
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
	for (int i = 0; i < _nlayers - 2; i++) {
		q.push(hidden);
	}
	q.push(_noutput_nodes);

	for (int i = 0; i < _nlayers - 1; i++) {
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

	for (int i = 0; i < _nlayers - 1; i++) {
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

	//double val = dC() * dA();

	//calculate the thing for the last layer

	//matrix dimesons
	/*
	_a = std::make_shared<Matrix>(1, nodes);
	_w = std::make_shared<Matrix>(nodes, next_nodes);
	_b = std::make_shared<Matrix>(1, next_nodes);

	_z = 1, next_nodes
	_an = 1, next_nodes

	_backPropagationValues = std::make_shared<Matrix>(1, nodes);
	_wGradientVector = std::make_shared<Matrix>(nodes, next_nodes);
	_bGradientVector = std::make_shared<Matrix>(1, next_nodes);


	*/

	Layer secondLastLayer = _layers[_nlayers - 1];
	Layer lastLayer = _layers[_nlayers - 2];
	//cook the first layer first
	std::vector<double> pdCAArr(secondLastLayer.GetSize(), 0);
	for (int i = 0; i < secondLastLayer.GetSize(); i++) {
		for (int j = 0; j < lastLayer.GetSize(); j++) {
			double pdZA = secondLastLayer.GetWEl(i, j);
			double pdAZ = dA(lastLayer.GetZEl(0, j));
			double pdCA = dC(secondLastLayer.GetAEl(1, j), _trainingLabels[dataIndex][j]);	
			pdCAArr[i] += pdZA + pdAZ + pdCA;
		}
	}

	//weights
	for (int currLayerIndex = _nlayers - 2; currLayerIndex >= 0; currLayerIndex--) {
		Layer currLayer = _layers[currLayerIndex];
		Layer prevLayer = _layers[currLayerIndex + 1];

		//first layer is special
		if(currLayerIndex == _nlayers - 2) {

			//weights
			for (int i = 0; i < currLayer.GetSize(); i++) {
				for (int j = 0; j < prevLayer.GetSize(); j++) {
					double pdAZ = dA(prevLayer.GetZEl(0, j));
					// double pdCA = dC(currLayer.GetAEl(0, i), _trainingLabels[dataIndex][j]);	
					double pdZW = currLayer.GetAEl(0, i);

					double currLayerBackPropogationValue = pdAZ * pdCAArr[i];
					double currLayerWeightUpdateValue = currLayerBackPropogationValue * pdZW;

					currLayer.SetBackPropagationValues(0, i, currLayerBackPropogationValue); 
					currLayer.SetWeightGradientVectorValues(i, j, currLayerWeightUpdateValue);
				}
			}

			// biases
			for(int j = 0; j < prevLayer.GetSize(); j++) {
				double pbZB = 1;

				//update bias gradient values
				double currLayerBackPropagationValue = currLayer.GetBackPropagationValues(0, j);
				double biasGradientValue = currLayerBackPropagationValue * pbZB;

				currLayer.SetBiasGradientVectorValues(0, j, biasGradientValue);
			}

			continue;
		}

		// weights
		for(int i = 0; i < currLayer.GetSize(); i++) {
			for(int j = 0; j < prevLayer.GetSize(); j++) {
				double pdZW = currLayer.GetAEl(0, i);
				double pdZA = currLayer.GetWEl(i, j);
				double pdAZ = dA(currLayer.GetZEl(0, j));

				//update propogation values
				double prevLayerBackPropagationValue = prevLayer.GetBackPropagationValues(0, j);
				double currLayerBackPropagationValue = pdAZ * pdZA * prevLayerBackPropagationValue;

				currLayer.SetBackPropagationValues(0, i, currLayerBackPropagationValue);

				//update weight gradient values
				double weightsGradientValue = currLayerBackPropagationValue * pdZW;

				currLayer.SetWeightGradientVectorValues(i, j, weightsGradientValue);
			}
		}

		// biases
		for(int j = 0; j < prevLayer.GetSize(); j++) {
				double pdZB = 1;

				//update bias gradient values
				double currLayerBackPropagationValue = currLayer.GetBackPropagationValues(0, j);
				double biasGradientValue = currLayerBackPropagationValue * pdZB;

				currLayer.SetBiasGradientVectorValues(0, j, biasGradientValue);
		}
	}
}

void NeuralNetwork::ApplyGradients(double learn_rate) {
	for (auto l : _layers) {
		l.ApplyGradients(learn_rate);
	}
}

void NeuralNetwork::Train(int epocs, double learn_rate) {


}

//debug
void NeuralNetwork::Print() {
	for (Layer l : _layers) {
		l.Print();
	}
}