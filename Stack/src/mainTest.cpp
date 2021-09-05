#include "stack/stack.h"
#include "../deps/microunit.h"

UNIT (Stack_Test){
	bool flag = true;
	const uint32_t num_insertions = 1000;
	Stack<int> *s = new Stack<int>();
	for (uint32_t i = 0; i < num_insertions; i++)
		s->push(static_cast<int>(i));
	for (uint32_t i = num_insertions-1; i > 0; i--)
	{
		int value = s->pop();
		if (value != static_cast<int>(i))
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
