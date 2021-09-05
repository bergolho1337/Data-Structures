#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

template<class T>
class SNode
{
private:
    uint32_t id;
    T value;
    SNode *next;
public:
    SNode (const uint32_t id, const T &value, SNode *next = nullptr)
    {
        this->id = id;
        this->value = value;
        this->next = next;
    }
    ~SNode ()
    {
        this->next = nullptr;
    }
    inline uint32_t get_id () { return this->id; }
    inline T get_value () { return this->value; }
    inline SNode* get_next () { return this->next; }
    inline void set_id (const uint32_t id) { this->id = id; }
    inline void set_value (const T value) { this->value = value; }
    inline void set_next (SNode *next) { this->next = next; }
    void print ()
    {
        printf("|| %u [%g] ||", this->id, this->value);
    }
};

template<class T>
class Stack
{
private:
    uint32_t num_nodes;
    SNode<T> *top;
public:
    Stack ();
    ~Stack ();
    inline uint32_t get_num_nodes () { return this->num_nodes; }
    void push (const T &value);
    SNode<T>* peek ();
    T pop ();
    bool is_empty ();
};

template<class T>
Stack<T>::Stack ()
{
    this->num_nodes = 0;
    this->top = nullptr;
}

template<class T>
Stack<T>::~Stack ()
{
    while (!is_empty())
        pop();
}

template<class T>
void Stack<T>::push (const T &value)
{
    uint32_t num_nodes = this->num_nodes;
    SNode<T> *n = new SNode<T>(num_nodes,value);

    if (is_empty())
    {
        this->top = n;
        this->num_nodes++;
    }
    else
    {
        n->set_next(this->top);
        this->top = n;
        this->num_nodes++;
    }
}

template<class T>
SNode<T>* Stack<T>::peek ()
{
    return this->top;
}

template<class T>
T Stack<T>::pop ()
{
    if (is_empty())
    {
        fprintf(stderr,"[-] ERROR! Stack is EMPTY!\n");
        return 0;
    }
    else
    {
        SNode<T> *tmp = this->top;
        T value = tmp->get_value();
        this->top = tmp->get_next();
        delete tmp;
        this->num_nodes--;
        return value;
    }
}

template<class T>
bool Stack<T>::is_empty ()
{
    return (this->top) ? false : true;
}

#endif