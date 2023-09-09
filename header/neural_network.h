#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "matrix.h"
#include "layer.h"
#include <vector>

class NeuralNetwork
{
public:
	NeuralNetwork();
	NeuralNetwork(int input, int hidden, int output, int layers);

	void ImportTrainingData (std::vector<double> data, std::vector<double> labels);

	void Forward();
	void BackPropagate();

	void Train();

	void BackPropagate(double learn_rate);

	//debug

	void Print();

private:
	int _ninput_nodes;
	int _nhidden_nodes;
	int _noutput_nodes;
	int _nlayers; //layers including input and output layers

	//training data
	int _nTrainingDataSets;
	std::vector<double> _trainingData;
	std::vector<double> _trainingLabels;

  std::vector<Layer> _layers;
  
  void rand_parameters();
};

#endif //NEURAL_NETWORK_H
