#include "linked-list/linked_list.h"

void test_singly_linked_list ()
{
	SinglyLinkedList<double> *l1 = new SinglyLinkedList<double>();
	l1->insert_to_tail(2);
	l1->insert_to_tail(5);
	l1->insert_to_tail(1);
	l1->insert_to_tail(8);
	l1->insert_to_tail(4);
	l1->insert_to_head(15);
	l1->insert_to_head(12);
	l1->insert_to_head(11);
	l1->print();

	SLLNode<double> *n1 = l1->search_element(4);
	if (n1) printf("Node '%u' was found!\n",n1->get_id());
	SLLNode<double> *n2 = l1->search_element(15);
	if (n2) printf("Node '%u' was found!\n",n2->get_id());
	SLLNode<double> *n3 = l1->search_element(100);
	if (n3) printf("Node '%u' was found!\n",n3->get_id());	// Will not print

	l1->delete_node(15);
	l1->print();
	l1->delete_node(11);
	l1->print();
	l1->delete_node(4);
	l1->print();
	l1->delete_node(100);

	delete l1;
}

void test_doubly_linked_list ()
{
	DoublyLinkedList<double> *l2 = new DoublyLinkedList<double>();
	
	l2->insert_to_tail(3);
	l2->insert_to_tail(1);
	l2->insert_to_tail(5);
	l2->insert_to_tail(7);
	l2->insert_to_tail(2);
	l2->print();
	
	delete l2;
}

int main (int argc, char *argv[])
{
	printf("============= SINGLY LINKED LIST ===============\n");
	test_singly_linked_list();
	printf("============= SINGLY LINKED LIST ===============\n");

	printf("============= DOUBLY LINKED LIST ===============\n");
	test_doubly_linked_list();
	printf("============= DOUBLY LINKED LIST ===============\n");
	
	return 0;
}