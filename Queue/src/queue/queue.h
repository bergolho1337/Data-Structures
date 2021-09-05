#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

template<class T>
class QNode
{
private:
    uint32_t id;
    T value;
    QNode *next;
public:
    QNode (const uint32_t id, const T &value, QNode *next = nullptr)
    {
        this->id = id;
        this->value = value;
        this->next = next;
    }
    ~QNode ()
    {
        this->next = nullptr;
    }
    inline uint32_t get_id () { return this->id; }
    inline T get_value () { return this->value; }
    inline QNode* get_next () { return this->next; }
    inline void set_id (const uint32_t id) { this->id = id; }
    inline void set_value (const T value) { this->value = value; }
    inline void set_next (QNode *next) { this->next = next; }
    void print ()
    {
        printf("|| %u [%g] ||", this->id, this->value);
    }
};

template<class T>
class Queue
{
private:
    uint32_t num_nodes;
    QNode<T> *first, *back;
public:
    Queue ();
    ~Queue ();
    inline uint32_t get_num_nodes () { return this->num_nodes; }
    void enqueue (const T &value);
    T dequeue ();
    QNode<T>* peek ();
    bool is_empty ();
};

template<class T>
Queue<T>::Queue ()
{
    this->num_nodes = 0;
    this->first = this->back = nullptr;
}

template<class T>
Queue<T>::~Queue ()
{
    while (!is_empty())
        dequeue();
}

template<class T>
void Queue<T>::enqueue (const T &value)
{
    uint32_t num_nodes = this->num_nodes;
    QNode<T> *n = new QNode<T>(num_nodes,value);

    if (is_empty())
    {
        this->first = this->back = n;
    }
    else
    {
        this->back->set_next(n);
        this->back = n;
    }
    this->num_nodes++;
}

template<class T>
QNode<T>* Queue<T>::peek ()
{
    return this->first;
}

template<class T>
T Queue<T>::dequeue ()
{
    if (is_empty())
    {
        fprintf(stderr,"[-] ERROR! Queue is EMPTY!\n");
        return 0;
    }
    else
    {
        QNode<T> *tmp = this->first;
        T value = tmp->get_value();
        this->first = tmp->get_next();
        if (!this->first) this->back = nullptr;
        delete tmp;
        this->num_nodes--;
        return value;
    }
}

template<class T>
bool Queue<T>::is_empty ()
{
    return (this->first && this->back) ? false : true;
}

#endif