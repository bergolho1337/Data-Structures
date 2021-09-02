#include "linked_list.h"

Node::Node (const uint32_t id, const double value, Node *next)
{
    this->id = id;
    this->value = value;
    this->next = next;
}

Node::~Node ()
{
    this->next = nullptr;
}

void Node::print ()
{
    printf("|| %u [%g] ||", this->id, this->value);
}

LinkedList::LinkedList ()
{
    this->num_nodes = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedList::~LinkedList ()
{
    while (!is_empty())
    {
        delete_from_head();
    }
}

Node* LinkedList::insert_to_head (const double value)
{
    uint32_t num_nodes = this->num_nodes;
    this->head = new Node(num_nodes,value,this->head);
    if (!this->tail)
        this->tail = this->head;
    this->num_nodes++;
    return this->head;
}

Node* LinkedList::insert_to_tail (const double value)
{
    uint32_t num_nodes = this->num_nodes;
    if (this->tail)
    {
        this->tail->set_next(new Node(num_nodes,value));
        this->tail = this->tail->get_next();
    }
    else
    {
        this->head = this->tail = new Node(num_nodes,value);
    }
    this->num_nodes++;
    return this->tail;
}

Node* LinkedList::search_element (const double value)
{
    Node *tmp = this->head;
    while (tmp != NULL)
    {
        if (tmp->get_value() == value) return tmp;
        tmp = tmp->get_next();
    }
    return nullptr;
}

double LinkedList::delete_from_head ()
{
    if (this->head)
    {
        double result = this->head->get_value();
        Node *tmp = this->head;
        if (this->head == this->tail)
            this->head = this->tail = nullptr;
        else
            this->head = this->head->get_next();
        delete tmp;
        this->num_nodes--;
        return result;
    }
    else
    {
        fprintf(stderr,"[-] ERROR! From 'delete_from_head'! The list is empty!\n");
        return 0;
    }
}

double LinkedList::delete_from_tail ()
{
    if (this->tail)
    {
        double result = this->tail->get_value();
        if (this->head == this->tail)
        {
            delete this->tail;
            this->head = this->tail = nullptr;
        }
        else
        {
            Node *tmp2 = this->head;
            while (tmp2->get_next() != this->tail)
            {
                tmp2 = tmp2->get_next();
            }
            delete this->tail;
            this->tail = tmp2;
            this->tail->set_next(nullptr);
        }
        this->num_nodes--;
        return result;
    }
    else
    {
        fprintf(stderr,"[-] ERROR! From 'delete_from_tail'! The list is empty!\n");
        return 0;
    }
}

bool LinkedList::delete_node (const double value)
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
        fprintf(stderr,"[-] ERROR! From 'delete_from_node'! Value '%g' was not found in the list!\n",value);
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

template<class T>
DLLNode<T>::DLLNode (const uint32_t id, const T &value, DLLNode *next, DLLNode *prev)
{
    this->id = id;
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
DLLNode<T>::~DLLNode ()
{
    this->next = nullptr;
    this->prev = nullptr;
}

template<class T>
void DLLNode<T>::print ()
{
    printf("|| %u [%g] ||", this->id, this->value);
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList ()
{
    this->num_nodes = 0;
    this->head = this->tail = nullptr;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList ()
{

}

template<class T>
void DoublyLinkedList<T>::insert_to_tail (const T &value)
{
    uint32_t num_nodes = this->num_nodes;
    if (this->tail)
    {
        this->tail = new DLLNode<T>(num_nodes,value,nullptr,this->tail);
        this->tail->get_prev()->set_next(this->tail);
    }
    else
    {
        this->head = this->tail = new DLLNode<T>(num_nodes,value);
    }
}

template<class T>
void DoublyLinkedList<T>::print ()
{
    DLLNode<T> *tmp = this->head;
    while (tmp != NULL)
    {
        tmp->print();
        printf(" --> ");
        tmp = tmp->get_next();
    }
    printf("\n");
}