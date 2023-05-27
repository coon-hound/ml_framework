#include <iostream>
#include "matrix.h"

int main()
{
	double m_arr[] = {1, 2, 3, 4, 5, 6};
	Matrix m(2, 3, m_arr);
	m.Print();
	printf("--------\n");

	double b_arr[] = {7, 8, 9, 10, 11, 12};
	Matrix b(3, 2, b_arr);
	b.Print();
	printf("--------\n");

	Matrix res = Matrix::Dot(m, b);	
	res.Print();
}
