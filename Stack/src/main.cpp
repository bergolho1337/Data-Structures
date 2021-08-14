#include "stack/stack.h"

int main (int argc, char *argv[])
{
	Stack *s1 = new Stack();
	s1->push(5);
	s1->push(8);
	s1->push(2);
	s1->push(1);
	s1->push(9);
	s1->push(6);

	while (!s1->is_empty())
	{
		Node *top = s1->peek();
		double value = s1->pop();
		printf("|| %g ||\n",value);
	}

	delete s1;

	return 0;
}