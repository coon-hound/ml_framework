#include <iostream>
#include "matrix.h"

int main()
{
	/*
	double m_arr[] = {1, 2, 3, 4, 5, 6};
	Matrix m(2, 3, std::shared_ptr<double>(m_arr));
	m.Print();
	printf("--------\n");

	double b_arr[] = {7, 8, 9, 10, 11, 12};
	Matrix b(3, 2, std::shared_ptr<double>(b_arr));
	b.Print();
	printf("--------\n");

	Matrix res = m * b;
	res.Print();
	res = m + m;
	res.Print();
	*/


	/*
	Matrix input(1, 2);

	Matrix w1(2, 2);	
	Matrix b1(1, 2);
	Matrix o1(1, 2);

	Matrix w2(2, 1);
	Matrix b2(1, 1);

	Matrix output(1, 1);

	w1.Rand();
	b1.Rand();

	w2.Rand();
	b2.Rand();

	printf("w1 = \n");
	w1.Print();
	printf("-----\n");
	printf("b1 = \n");
	b1.Print();
	printf("-----\n");

	printf("w2 = \n");
	w2.Print();
	printf("-----\n");
	printf("b2 = \n");
	b2.Print();
	printf("-----\n");

	o1 = Matrix::Dot(input, w1);	
	o1 = Matrix::Add(o1, b1);
	o1.Sigmoid();

	output = Matrix::Dot(o1, w2);
	output = Matrix::Add(output, b2);
	output.Sigmoid();
*/
}

