#include "queue/queue.h"

void test_integer_queue ()
{
	int value;
	Queue<int> *q1 = new Queue<int>();
	q1->enqueue(10);
	q1->enqueue(5);
	value = q1->dequeue();
	printf("|| %d ||\n",value);
	q1->enqueue(15);
	q1->enqueue(7);
	value = q1->dequeue();
	printf("|| %d ||\n",value);
	delete q1;
}

void test_double_queue ()
{
	Queue<double> *q1 = new Queue<double>();
	q1->enqueue(10.555);
	q1->enqueue(5.123);
	q1->enqueue(8.999);
	q1->enqueue(1.456);
	q1->dequeue();
	q1->enqueue(7.159);
	while (!q1->is_empty())
	{
		QNode<double> *first = q1->peek();
		double value = q1->dequeue();
		printf("|| %g ||\n",value);
	}
	delete q1;
}

int main (int argc, char *argv[])
{
	printf("============= INTEGER QUEUE ===============\n");
	test_integer_queue();
	printf("============= INTEGER QUEUE ===============\n");
	printf("============= DOUBLE QUEUE ===============\n");
	test_double_queue();
	printf("============= DOUBLE QUEUE ===============\n");
	return 0;
}