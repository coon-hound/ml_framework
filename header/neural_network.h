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

	void ImportTrainingData (std::vector<std::vector<double>> data, std::vector<std::vector<double>> labels);

	void Forward(int dataIndex);
	void BackPropagate(int dataIndex, double learn_rate);

	void Train();

	//debug

	void Print();

private:
	int _ninput_nodes;
	int _nhidden_nodes;
	int _noutput_nodes;
	int _nlayers; //layers including input and output layers

	//training data
	int _nTrainingDataSets;
	std::vector<std::vector<double>> _trainingData;
	std::vector<std::vector<double>> _trainingLabels;

  std::vector<Layer> _layers;
  
  void rand_parameters();
};

#endif //NEURAL_NETWORK_H
