#include "matrix/matrix.h"

int main (int argc, char *argv[])
{
	Matrix m1(3,3);
	m1.randomize();
	m1.print();

	Matrix m2(3,3);
	m2.randomize();
	m2.print();
	
	Matrix m3 = m1 + m2;
	m3.print();

	Matrix m4 = m1 * m2;
	m4.print();

	if (m1 == m4)
		printf("Matrix 'm1' is EQUAL to 'm4'\n");
	else
		printf("Matrix 'm1' is NOT EQUAL to 'm4'\n");

	Matrix m5(4,4);
	m5.print();

	Matrix m6(4,4);
	m6.print();

	if (m5 == m6)
		printf("Matrix 'm5' is EQUAL to 'm6'\n");
	else
		printf("Matrix 'm5' is NOT EQUAL to 'm6'\n");

	Matrix m7(2,4);
	m7.randomize();
	m7.print();

	Matrix m8 = m7.transpose();
	m8.print();

	Matrix m9(5,5);
	m8.randomize();
	m8.print();

	Matrix m10 = m8 * 5.0;
	m10.print();

	return 0;
}