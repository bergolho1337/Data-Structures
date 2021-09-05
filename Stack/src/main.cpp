#include "stack/stack.h"

void test_integer_stack ()
{
	Stack<int> *s1 = new Stack<int>();
	s1->push(5);
	s1->push(8);
	s1->push(2);
	s1->push(1);
	s1->push(9);
	s1->push(6);
	while (!s1->is_empty())
	{
		SNode<int> *top = s1->peek();
		int value = s1->pop();
		printf("|| %d ||\n",value);
	}
	delete s1;
}

void test_double_stack ()
{
	Stack<double> *s1 = new Stack<double>();
	s1->push(5.225);
	s1->push(8.123);
	s1->push(2.945);
	s1->push(1.402);
	s1->push(9.678);
	s1->push(6.159);
	while (!s1->is_empty())
	{
		SNode<double> *top = s1->peek();
		double value = s1->pop();
		printf("|| %g ||\n",value);
	}
	delete s1;
}

int main (int argc, char *argv[])
{
	printf("============= INTEGER STACK ===============\n");
	test_integer_stack();
	printf("============= INTEGER STACK ===============\n");
	printf("============= DOUBLE STACK ===============\n");
	test_double_stack();
	printf("============= DOUBLE STACK ===============\n");
	return 0;
}