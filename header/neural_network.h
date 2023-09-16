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

	void ImportTrainingData (std::vector<std::vector<double>> taData, std::vector<std::vector<double>> taLabels, std::vector<std::vector<double>> teData, std::vector<std::vector<double>> teLabels);

	void Forward(int dataIndex);
	void BackPropagate(int dataIndex, double learn_rate);

	void ApplyGradients(double learn_rate);

	void Train(int epochs, double learn_rate);

	//debug

	void Print();

private:
	int _ninput_nodes;
	int _nhidden_nodes;
	int _noutput_nodes;
	int _nlayers; //layers including input and output layers

	//training data is 2d vector because each one training data is one vector, and we have many pieces of data
	int _nTrainingDataSets;
	int _nTestingDataSets;
	std::vector<std::vector<double>> _trainingData;
	std::vector<std::vector<double>> _trainingLabels;
	std::vector<std::vector<double>> _testingData;
	std::vector<std::vector<double>> _testingLabels;

  std::vector<Layer> _layers;
  
  void rand_parameters();
};

#endif //NEURAL_NETWORK_H
