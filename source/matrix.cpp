#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#define MAT_AT(i, j) _arr[(i)*_cols + (j)]


static double rand_double()
{
	return (double) rand() / (double) RAND_MAX;
}

static double sigmoid(double x)
{
	return 1.f / (1.f + exp(-x));
}


Matrix::Matrix(int rows, int cols) : 
	_rows(rows),
	_cols(cols),
	_arr(rows * cols, 0.0) {
	
}
	

Matrix::Matrix(int rows, int cols, const std::vector<double> arr) :
	_rows(rows),
	_cols(cols),
	_arr(arr) {
}

void Matrix::Alloc(const std::vector<double> arr)
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
	assert(a.GetCols() == b.GetRows());
	int n = a.GetCols();
	int rows = a.GetRows();
	int cols = b.GetCols();

	Matrix ret(rows, cols);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			for(int k = 0; k < n; k++){
				ret.SetEl(i, j, ret.GetEl(i, j) + a.GetEl(i, k) * b.GetEl(k, j));	
			}
		}
	}

//	free(arr);

	return ret; 
}

Matrix Matrix::Add(Matrix a, Matrix b)
{
	assert(a.GetRows() == b.GetRows());
	assert(a.GetCols() == b.GetCols());

	int rows = a.GetRows();
	int cols = a.GetCols();

	Matrix ret(rows, cols);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			ret.SetEl(i, j, a.GetEl(i, j) + b.GetEl(i, j));
		}
	} 
	
	return ret;
}

int Matrix::GetRows()
{
	return _rows;
}

int Matrix::GetCols()
{
	return _cols;
}


double Matrix::GetEl(int i, int j)
{
	return MAT_AT(i, j);
}

void Matrix::SetEl(int i, int j, double value)
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
