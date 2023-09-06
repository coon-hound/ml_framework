#ifndef MATRIX_H
#define MATRIX_H

#include <memory>
#include <vector>

class Matrix
{
public:
	Matrix() = default;
	Matrix(int rows, int cols);
	Matrix(int rows, int cols, const std::vector<double> arr);

	void Alloc(const std::vector<double> arr);
	void Sigmoid();
	void Fill(int x);
	void Rand();
	void Rand(double min, double max);
	void Print();

	static Matrix Dot(Matrix a, Matrix b);
	static Matrix Add(Matrix a, Matrix b);

	int GetRows();
	int GetCols();

	double GetEl(int i, int j);
	void SetEl(int i, int j, double value); 

	Matrix operator * (Matrix const &a);
	Matrix operator + (Matrix const &a);

private:
	int _rows;
	int _cols;
	std::vector<double> _arr;

};

#endif // MATRIX_H
