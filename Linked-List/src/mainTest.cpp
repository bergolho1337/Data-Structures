#include "linked-list/linked_list.h"
#include "../deps/microunit.h"

UNIT (LinkedList_Insert){
	const uint32_t num_insertions = 1000;
	LinkedList *l = new LinkedList();
	for (uint32_t i = 0; i < num_insertions; i++)
		l->insert_element(i);
	uint32_t num_nodes = l->get_num_nodes();
	delete l;

	ASSERT_TRUE(num_nodes == num_insertions);
}

UNIT (LinkedList_Search){
	LinkedList *l = new LinkedList();
	l->insert_element(5);
	l->insert_element(8);
	l->insert_element(2);
	l->insert_element(7);
	l->insert_element(1);
	
	Node *n1 = l->search_element(2);		// Must be found
	Node *n2 = l->search_element(100);		// Must NOT be found
	Node *n3 = l->search_element(1);		// Must be found
	bool flag = (n1 && !n2 && n3) ? true : false;
	delete l;

	ASSERT_TRUE(flag);
}

UNIT (LinkedList_Delete){
	LinkedList *l = new LinkedList();
	l->insert_element(7);
	l->insert_element(2);
	l->insert_element(4);
	l->insert_element(8);
	l->insert_element(6);
	
	bool flag1 = l->delete_element(2);		// Must be found
	bool flag2 = l->delete_element(100);	// Must NOT be found
	bool flag3 = l->delete_element(7);		// Must be found
	bool flag4 = l->delete_element(6);		// Must be found
	bool flag = (flag1 && !flag2 && flag3 && flag4 && l->get_num_nodes() == 2) ? true : false;
	delete l;

	ASSERT_TRUE(flag);
}

int main (int argc, char *argv[])
{
	return microunit::UnitTester::Run() ? 0 : -1;
}
