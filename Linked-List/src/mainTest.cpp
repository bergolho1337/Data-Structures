#include "linked-list/linked_list.h"
#include "../deps/microunit.h"

UNIT (SinglyLinkedList_Insert){
	const uint32_t num_insertions = 1000;
	SinglyLinkedList<double> *l = new SinglyLinkedList<double>();
	for (uint32_t i = 0; i < num_insertions; i++)
		l->insert_to_tail(i);
	uint32_t num_nodes = l->get_num_nodes();
	delete l;

	ASSERT_TRUE(num_nodes == num_insertions);
}

UNIT (SinglyLinkedList_Search){
	SinglyLinkedList<double> *l = new SinglyLinkedList<double>();
	l->insert_to_tail(5);
	l->insert_to_tail(8);
	l->insert_to_tail(2);
	l->insert_to_tail(7);
	l->insert_to_tail(1);
	
	SLLNode<double> *n1 = l->search_element(2);		// Must be found
	SLLNode<double> *n2 = l->search_element(100);		// Must NOT be found
	SLLNode<double> *n3 = l->search_element(1);		// Must be found
	bool flag = (n1 && !n2 && n3) ? true : false;
	delete l;

	ASSERT_TRUE(flag);
}

UNIT (SinglyLinkedList_Delete){
	SinglyLinkedList<double> *l = new SinglyLinkedList<double>();
	l->insert_to_tail(7);
	l->insert_to_tail(2);
	l->insert_to_tail(4);
	l->insert_to_tail(8);
	l->insert_to_tail(6);
	
	bool flag1 = l->delete_node(2);		// Must be found
	bool flag2 = l->delete_node(100);	// Must NOT be found
	bool flag3 = l->delete_node(7);		// Must be found
	bool flag4 = l->delete_node(6);		// Must be found
	bool flag = (flag1 && !flag2 && flag3 && flag4 && l->get_num_nodes() == 2) ? true : false;
	delete l;

	ASSERT_TRUE(flag);
}

UNIT (DoublyLinkedList_Insert){
	const uint32_t num_insertions = 1000;
	DoublyLinkedList<double> *l = new DoublyLinkedList<double>();
	for (uint32_t i = 0; i < num_insertions; i++)
		l->insert_to_tail(i);
	uint32_t num_nodes = l->get_num_nodes();
	delete l;

	ASSERT_TRUE(num_nodes == num_insertions);
}

UNIT (DoublyLinkedList_Delete){
	DoublyLinkedList<double> *l = new DoublyLinkedList<double>();
	l->insert_to_tail(7);
	l->insert_to_tail(2);
	l->insert_to_tail(4);
	l->insert_to_tail(8);
	l->insert_to_tail(6);
	
	double val1 = l->delete_from_tail();		
	double val2 = l->delete_from_tail();		
	double val3 = l->delete_from_tail();		
	double val4 = l->delete_from_tail();		
	double val5 = l->delete_from_tail();
	double val6 = l->delete_from_tail();		
	bool flag = (val1 && val2 && val3 && val4 && val5 && !val6) ? true : false;
	delete l;

	ASSERT_TRUE(flag);
}

int main (int argc, char *argv[])
{
	return microunit::UnitTester::Run() ? 0 : -1;
}
