#include "queue/queue.h"
#include "../deps/microunit.h"

UNIT (Queue_Test){
	bool flag = true;
	const uint32_t num_insertions = 1000;
	Queue<int> *q = new Queue<int>();
	for (uint32_t i = 0; i < num_insertions; i++)
		q->enqueue(static_cast<int>(i));
	for (uint32_t i = 0; i < num_insertions; i++)
	{
		int value = q->dequeue();
		if (value != static_cast<int>(i))
		{
			flag = false;
			break;
		}
	}
	delete q;

	ASSERT_TRUE(flag);
}

int main (int argc, char *argv[])
{
	return microunit::UnitTester::Run() ? 0 : -1;
}
