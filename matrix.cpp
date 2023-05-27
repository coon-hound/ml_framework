#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define MAT_AT(i, j) _arr[(i)*_cols + (j)]

static double rand_double()
{
	return (double) rand() / (double) RAND_MAX;
}

Matrix::Matrix(int rows, int cols)
{
	srand(time(0));

	_rows = rows;
	_cols = cols;
	_arr = (double*)malloc(sizeof(*_arr) * _cols * _rows);
}

Matrix::Matrix(int rows, int cols, double *arr)
{
	srand(time(0));

	_rows = rows;
	_cols = cols;
	_arr = arr;
}

void Matrix::Alloc(double *arr)
{
	_arr = arr;
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
	Matrix res(1, 2);
	printf("helelogapsodf\n\n\n\n\n");
	return res;
}

Matrix Matrix::Add(Matrix a, Matrix b)
{
	assert(a.getRows() == b.getRows());
	assert(a.getCols() == b.getCols());

	int rows = a.getRows();
	int cols = a.getCols();

	double *arr = (double *)malloc(sizeof(double) * rows * cols);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			arr[(i)*cols + (j)] = a.getEl(i, j) + b.getEl(i, j);
		}
	} 
	
	Matrix ret(rows, cols, arr);

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
	return _arr[(i)*_cols + (j)];
}







