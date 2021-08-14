#include "stack/stack.h"
#include "../deps/microunit.h"

UNIT (Stack_Test){
	bool flag = true;
	const uint32_t num_insertions = 1000;
	Stack *s = new Stack();
	for (uint32_t i = 0; i < num_insertions; i++)
		s->push(static_cast<double>(i));
	for (uint32_t i = num_insertions-1; i > 0; i--)
	{
		double value = s->pop();
		if (value != static_cast<double>(i))
		{
			flag = false;
			break;
		}
	}
	delete s;

	ASSERT_TRUE(flag);
}

int main (int argc, char *argv[])
{
	return microunit::UnitTester::Run() ? 0 : -1;
}
