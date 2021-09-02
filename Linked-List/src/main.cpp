#include "linked-list/linked_list.h"

int main (int argc, char *argv[])
{
	LinkedList *l1 = new LinkedList();
	l1->insert_to_tail(2);
	l1->insert_to_tail(5);
	l1->insert_to_tail(1);
	l1->insert_to_tail(8);
	l1->insert_to_tail(4);
	l1->insert_to_head(15);
	l1->insert_to_head(12);
	l1->insert_to_head(11);
	l1->print();

	Node *n1 = l1->search_element(4);
	if (n1) printf("Node '%u' was found!\n",n1->get_id());
	Node *n2 = l1->search_element(15);
	if (n2) printf("Node '%u' was found!\n",n2->get_id());
	Node *n3 = l1->search_element(100);
	if (n3) printf("Node '%u' was found!\n",n3->get_id());	// Will not print

	l1->delete_node(15);
	l1->print();
	l1->delete_node(11);
	l1->print();
	l1->delete_node(4);
	l1->print();
	l1->delete_node(100);

	delete l1;


	DoublyLinkedList<double> l2();

	return 0;
}