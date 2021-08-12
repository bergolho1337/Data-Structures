#include "matrix/matrix.h"
#include "../deps/microunit.h"

UNIT (Matrix_Add){
	Matrix m1("inputs/m1.txt");
	Matrix m2("inputs/m2.txt");
	Matrix m3("inputs/m3.txt");
	ASSERT_TRUE(m1 + m2 == m3);
}

UNIT (Matrix_Sub){
	Matrix m1("inputs/m1.txt");
	Matrix m2("inputs/m2.txt");
	Matrix m4("inputs/m4.txt");
	ASSERT_TRUE(m1 - m2 == m4);
}

UNIT (Matrix_Mult){
	Matrix m1("inputs/m1.txt");
	Matrix m2("inputs/m2.txt");
	Matrix m5("inputs/m5.txt");
	ASSERT_TRUE(m1 * m2 == m5);
}

UNIT (Matrix_Transpose){
	Matrix m6("inputs/m6.txt");
	Matrix m7("inputs/m7.txt");
	ASSERT_TRUE(m6.transpose() == m7);
}

int main (int argc, char *argv[])
{
	return microunit::UnitTester::Run() ? 0 : -1;
}
