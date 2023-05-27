#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:
	Matrix(int rows, int cols);
	Matrix(int rows, int cols, double *arr);
	void Alloc(double *arr);
	void Fill(int x);
	void Rand(double min, double max);
	void Print();
	static Matrix Dot(Matrix a, Matrix b);
	static Matrix Add(Matrix a, Matrix b);

	int getRows();
	int getCols();
	double getEl(int i, int j);

private:
	int _rows;
	int _cols;
	double *_arr;

};

#endif // MATRIX_H
