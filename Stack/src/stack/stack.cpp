#include "stack.h"

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

Stack::Stack ()
{
    this->num_nodes = 0;
    this->top = NULL;
}

Stack::~Stack ()
{
    Node *tmp = NULL;
    while (!is_empty())
    {
        pop();
    }
}

void Stack::push (const double value)
{
    uint32_t cur_num_nodes = this->num_nodes;
    Node *n = new Node(cur_num_nodes,value);

    // CASE 1) Stack is empty
    if (!this->top)
    {
        this->top = n;
        this->num_nodes++;
    }
    // CASE 2) Insert at the last element
    else
    {
        n->set_next(this->top);
        this->top = n;
        this->num_nodes++;
    }
}

Node* Stack::peek ()
{
    return this->top;
}

double Stack::pop ()
{
    if (is_empty())
    {
        fprintf(stderr,"[-] ERROR! Stack is EMPTY!\n");
        return 0.0;
    }
    else
    {
        Node *tmp = this->top;
        double value = tmp->get_value();
        this->top = tmp->get_next();
        delete tmp;
        this->num_nodes--;
        return value;
    }
}

bool Stack::is_empty ()
{
    return (this->num_nodes == 0) ? true : false;
}
