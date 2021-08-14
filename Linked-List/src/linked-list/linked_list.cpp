#include "linked_list.h"

Node::Node (const uint32_t id, const double value)
{
    this->id = id;
    this->value = value;
    this->next = NULL;
}

Node::~Node ()
{
    this->next = NULL;
}

void Node::print ()
{
    printf("|| %u [%g] ||", this->id, this->value);
}

LinkedList::LinkedList ()
{
    this->num_nodes = 0;
    this->head = NULL;
    this->tail = NULL;
}

LinkedList::LinkedList (const char filename[])
{

}

LinkedList::~LinkedList ()
{
    Node *tmp = NULL;
    while (!is_empty())
    {
        tmp = this->head;
        delete_element(tmp->get_value());
    }
}

Node* LinkedList::insert_element (const double value)
{
    uint32_t cur_num_nodes = this->num_nodes;
    Node *n = new Node(cur_num_nodes,value);

    // CASE 1) List is empty
    if (!this->tail)
    {
        this->head = n;
        this->tail = n;
        this->num_nodes++;
    }
    // CASE 2) Insert at the last element
    else
    {
        this->tail->set_next(n);
        this->tail = n;
        this->num_nodes++;
    }
    return n;
}

Node* LinkedList::search_element (const double value)
{
    Node *tmp = this->head;
    while (tmp != NULL)
    {
        if (tmp->get_value() == value) return tmp;
        tmp = tmp->get_next();
    }
    return NULL;
}

bool LinkedList::delete_element (const double value)
{
    Node *tmp = this->head;
    Node *tmp2 = tmp;
    
    // Pass through the list searching for the element
    while (tmp != NULL && tmp->get_value() != value)
    {
        tmp2 = tmp;
        tmp = tmp->get_next();
    }

    // Found the element
    if (tmp)
    {
        // CASE 1) Head of the list
        if (this->head == tmp)
            this->head = tmp->get_next();
        // CASE 2) Tail of the list
        else if (this->tail == tmp)
            this->tail = tmp2;

        tmp2->set_next(tmp->get_next());
        delete tmp;
        this->num_nodes--;
        return true;
    }
    // Element not found
    else
    {
        fprintf(stderr,"[-] ERROR! Value '%g' was not found in the list!\n",value);
        return false;
    }
}

void LinkedList::print ()
{
    if (is_empty())
        printf("[!] The list is EMPTY!\n");
    
    Node *tmp = this->head;
    while (tmp != NULL)
    {
        tmp->print();
        printf(" --> ");
        tmp = tmp->get_next();
    }
    printf("\n");
}

bool LinkedList::is_empty ()
{
    return (this->num_nodes == 0) ? true : false;
}
