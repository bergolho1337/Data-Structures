#include "linked-list/linked_list.h"

int main (int argc, char *argv[])
{
	LinkedList *l1 = new LinkedList();
	l1->insert_element(2);
	l1->insert_element(5);
	l1->insert_element(1);
	l1->insert_element(8);
	l1->insert_element(4);
	l1->print();

	double key = 1.0;
	Node *n1 = l1->search_element(key);
	if (n1)
		printf("[+] Found key '%g' in the list!\n",n1->get_value());
	else
		printf("[-] ERROR! Key '%g' was NOT found in the list!\n",key);
	
	key = 100.0;
	Node *n2 = l1->search_element(key);
	if (n2)
		printf("[+] Found key '%g' in the list!\n",n2->get_value());
	else
		printf("[-] ERROR! Key '%g' was NOT found in the list!\n",key);

	key = 2.0;
	bool flag = l1->delete_element(key);
	if (flag)
		printf("[+] Node '%g' was deleted from the list!\n",key);
	l1->print();

	key = 4.0;	
	flag = l1->delete_element(key);
	if (flag)
		printf("[+] Node '%g' was deleted from the list!\n",key);
	l1->print();

	key = 1.0;	
	flag = l1->delete_element(key);
	if (flag)
		printf("[+] Node '%g' was deleted from the list!\n",key);
	l1->print();
	
	key = 8.0;	
	flag = l1->delete_element(key);
	if (flag)
		printf("[+] Node '%g' was deleted from the list!\n",key);
	l1->print();

	key = 5.0;	
	flag = l1->delete_element(key);
	if (flag)
		printf("[+] Node '%g' was deleted from the list!\n",key);
	l1->print();

	key = 100.0;	
	flag = l1->delete_element(key);
	if (flag)
		printf("[+] Node '%g' was deleted from the list!\n",key);
	l1->print();

	delete l1;
	
	return 0;
}