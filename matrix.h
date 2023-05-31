#ifndef MATRIX_H
#define MATRIX_H
#include <memory>

class Matrix
{
public:
	Matrix() = default;
	Matrix(int rows, int cols);

	Matrix(int rows, int cols, std::shared_ptr<double[]> arr);
//	~Matrix();
	void Alloc(std::shared_ptr<double[]> arr);
	void Sigmoid();
	void Fill(int x);
	void Rand();
	void Rand(double min, double max);
	void Print();

	static Matrix Dot(Matrix a, Matrix b);
	static Matrix Add(Matrix a, Matrix b);

	int getRows();
	int getCols();
	double getEl(int i, int j);

	void setEl(int i, int j, int value); 

	Matrix operator * (Matrix const &a);
	Matrix operator + (Matrix const &a);

private:
	int _rows;
	int _cols;
	std::shared_ptr<double[]> _arr;
//	double *_arr;

};

#endif // MATRIX_H
