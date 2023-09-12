#include <iostream>
#include <vector>
#include "neural_network.h"

double rand_double()
{
	return (double) rand() / (double) RAND_MAX;
}

int main()
{
	NeuralNetwork n(2, 3, 2, 4);

	std::vector<std::vector<double>> data;
	std::vector<std::vector<double>> labels;

	std::vector<std::vector<double>> tData;
	std::vector<std::vector<double>> tLabels;

	for(int i = 0; i < 10; i++) {
		data.push_back({rand_double(), rand_double()});
		labels.push_back({rand_double(), rand_double()});
		
		tData.push_back({rand_double(), rand_double()});
		tLabels.push_back({rand_double(), rand_double()});
	}

	printf("---data---\n");
	for(int i = 0; i < 10; i++) {
		printf("%f, %f\n", data[i][0], data[i][1]);
	}

	printf("---labels---\n");
	for(int i = 0; i < 10; i++) {
		printf("%f, %f\n", labels[i][0], labels[i][1]);
	}

	printf("---training data---\n");
	for(int i = 0; i < 10; i++) {
		printf("%f, %f\n", tData[i][0], tData[i][1]);
	}

	printf("---training labels---\n");
	for(int i = 0; i < 10; i++) {
		printf("%f, %f\n", tLabels[i][0], tLabels[i][1]);
	}


	n.ImportTrainingData(data, labels, tData, tLabels);

	n.Print();

	n.Forward(0);

	n.Print();

	n.Forward(1);
	
	n.Print();
}

