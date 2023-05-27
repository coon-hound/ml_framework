#include <iostream>
#include "matrix.h"

int main()
{
	double m_arr[] = {2, 3, 4, 5};
	Matrix m(2, 2, m_arr);
	m.Print();
	printf("--------\n");

	double b_arr[] = {5, 6, 3, 7};
	Matrix b(2, 2, b_arr);
	b.Print();
	printf("--------\n");

	Matrix res = Matrix::Add(m, b);
	res.Print();
}
