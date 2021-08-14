#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

class Node
{
private:
    uint32_t id;
    double value;
    Node *next;
public:
    Node (const uint32_t id, const double value);
    ~Node ();
    inline uint32_t get_id () { return this->id; }
    inline double get_value () { return this->value; }
    inline Node* get_next () { return this->next; }
    inline void set_id (const uint32_t id) { this->id = id; }
    inline void set_value (const double value) { this->value = value; }
    inline void set_next (Node *next) { this->next = next; }
    void print ();
};

class Stack
{
private:
    uint32_t num_nodes;
    Node *top;
public:
    Stack ();
    ~Stack ();
    inline uint32_t get_num_nodes () { return this->num_nodes; }
    void push (const double value);
    Node* peek ();
    double pop ();
    bool is_empty ();
};

#endif