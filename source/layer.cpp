#include "layer.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double rand_double()
{
	return (double) rand() / (double) RAND_MAX;
}

static double sigmoid(double x) {
	return (1.f / (1.f + exp(-x)));
}

#define A(x) sigmoid(x)

Matrix Layer::applyActivationFunction(Matrix &a) {
	Matrix res(a.GetRows(), a.GetCols());
	for(int i = 0; i < a.GetRows(); i++) {
		for(int j = 0; j < a.GetCols(); j++) {
			res.SetEl(i, j, A(a.GetEl(i, j)));
		}
	}

	return res;
}

Layer::Layer(int nodes, int next_nodes) {
	_size = nodes;
	_next_size = next_nodes;

	if(_next_size == 0) {
		_a = std::make_shared<Matrix>(1, nodes);
		_w = nullptr;
		_b = nullptr;
		return;
	}

	_a = std::make_shared<Matrix>(1, nodes);
	_w = std::make_shared<Matrix>(nodes, next_nodes);
	_b = std::make_shared<Matrix>(1, next_nodes);
}

void Layer::RandParams() {
	for(int i = 0; i < _next_size; i++) {
		for(int j = 0; j < _size; j++) {
			_w->SetEl(j, i, rand_double());
		}
		_b->SetEl(0, i, rand_double());
	}

}

void Layer::RandActivation() {
	for(int i = 0; i < _size; i++) {
		_a->SetEl(0, i, rand_double());
	}

}


int Layer::GetSize() {
	return _size;
}

double Layer::GetWEl(int row, int col) {
	return _w->GetEl(row, col);
}

void Layer::SetWEl(int row, int col, double value) {
	_w->SetEl(row, col, value);
}

void Layer::SetA(Matrix a) {
	_a = std::make_shared<Matrix>(a);
}

double Layer::GetAEl(int row, int col) {
	return _a->GetEl(row, col);
}

void Layer::SetAEl(int row, int col, double value) {
	_a->SetEl(row, col, value);
}

double Layer::GetBEl(int row, int col) {
	return _b->GetEl(row, col);
}

void Layer::SetBEl(int row, int col, double value) {
	_b->SetEl(row, col, value);
}


Matrix Layer::Forward() {
	Matrix res = Matrix::Dot(*_a, *_w);
	res = Matrix::Add(res, *_b);

  _z = std::make_shared<Matrix>(res);
  
	res = applyActivationFunction(res);
	return res;
}

//Debug
void Layer::Print() {
	//print activation node values
	printf("activation node values: \n");
	for(int i = 0; i < _a->GetCols(); i++) {
		printf("a%d = %f\n", i, _a->GetEl(0, i));
	}

	//print weight values
	printf("weight values: \n");
	if(_w == nullptr) {
		printf("output layer, no weights\n");
	}
	else {
		for(int i = 0; i < _w->GetRows(); i++) {
			for(int j = 0; j < _w->GetCols(); j++) {
				printf("w%d%d = %f\n", i, j, _w->GetEl(i, j));
			}
		}
	}

	// print bias values
	printf("bias values: \n");
	if(_b == nullptr) {
		printf("output layer, no biases\n");
	}
	else{
		for(int i = 0; i < _b->GetCols(); i++) {
			printf("b%d = %f\n", i, _b->GetEl(0, i));
		}
	}

	printf("-----------------\n\n");
}