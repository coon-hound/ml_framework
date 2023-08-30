#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#define MAT_AT(i, j) _arr.get()[(i)*_cols + (j)]


static double rand_double()
{
	return (double) rand() / (double) RAND_MAX;
}

static double sigmoid(double x)
{
	return 1.f / (1.f + exp(-x));
}


Matrix::Matrix(int rows, int cols)
{
	srand(time(0));
	_rows = rows;
	_cols = cols;
	_arr = std::make_shared<double>(10);
}

Matrix::Matrix(int rows, int cols, const std::shared_ptr<double> arr)

{
	srand(time(0));

	_rows = rows;
	_cols = cols;
	_arr = arr;
}

void Matrix::Alloc(const std::shared_ptr<double> arr)
{
	_arr = arr;
}

void Matrix::Sigmoid()
{
	for(int i = 0; i < _rows; i++){
		for(int j = 0; j < _cols; j++){
			MAT_AT(i, j) = sigmoid(MAT_AT(i, j));
		}
	}
}

void Matrix::Fill(int x)
{
	for(int i = 0; i < _rows; i++){
		for(int j = 0; j < _cols; j++){
			MAT_AT(i, j) = x;
		}
	}
}

void Matrix::Print()
{
	for(int i = 0; i < _rows; i++){
		for(int j = 0; j < _cols; j++){
			printf("%f ", MAT_AT(i, j));
		}
		printf("\n");
	}
}

void Matrix::Rand()
{
	for(int i = 0; i < _rows; i++){
		for(int j = 0; j < _cols; j++){
			MAT_AT(i, j) = rand_double() * (1 - 0) + 0;
		}
	}
	
}

void Matrix::Rand(double min, double max)
{
	assert(max > min);	
	for(int i = 0; i < _rows; i++){
		for(int j = 0; j < _cols; j++){
			MAT_AT(i, j) = rand_double() * (max - min) + min;
		}
	}
}

Matrix Matrix::Dot(Matrix a, Matrix b)
{
	assert(a.getCols() == b.getRows());
	int n = a.getCols();
	int rows = a.getRows();
	int cols = b.getCols();

	Matrix ret(rows, cols);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			for(int k = 0; k < n; k++){
				ret.setEl(i, j, ret.getEl(i, j) + a.getEl(i, k) * b.getEl(k, j));	
			}
		}
	}

//	free(arr);

	return ret; 
}

Matrix Matrix::Add(Matrix a, Matrix b)
{
	assert(a.getRows() == b.getRows());
	assert(a.getCols() == b.getCols());

	int rows = a.getRows();
	int cols = a.getCols();

//	double *arr = (double *)malloc(sizeof(double) * rows * cols);

	Matrix ret(rows, cols);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			ret.setEl(i, j, a.getEl(i, j) + b.getEl(i, j));
//			arr[(i)*cols + (j)] = a.getEl(i, j) + b.getEl(i, j);
		}
	} 
	
//	Matrix ret(rows, cols, arr);

//	free(arr);

	return ret;
}

int Matrix::getRows()
{
	return _rows;
}

int Matrix::getCols()
{
	return _cols;
}


double Matrix::getEl(int i, int j)
{
	return MAT_AT(i, j);
}

void Matrix::setEl(int i, int j, double value)
{
	MAT_AT(i, j) = value;	
}

Matrix Matrix::operator * (Matrix const &a)
{
	return Matrix::Dot(*this, a);
}

Matrix Matrix::operator + (Matrix const &a)
{
	return Matrix::Add(*this, a);
}
