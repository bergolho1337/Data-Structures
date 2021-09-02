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
    Node (const uint32_t id, const double value, Node *next = nullptr);
    ~Node ();
    inline uint32_t get_id () { return this->id; }
    inline double get_value () { return this->value; }
    inline Node* get_next () { return this->next; }
    inline void set_id (const uint32_t id) { this->id = id; }
    inline void set_value (const double value) { this->value = value; }
    inline void set_next (Node *next) { this->next = next; }
    void print ();
};

class LinkedList
{
private:
    uint32_t num_nodes;
    Node *head;
    Node *tail;
public:
    LinkedList ();
    ~LinkedList ();
    inline uint32_t get_num_nodes () { return this->num_nodes; }
    Node* insert_to_head (const double value);
    Node* insert_to_tail (const double value);
    Node* search_element (const double value);
    double delete_from_head ();
    double delete_from_tail ();
    bool delete_node (const double value);
    bool is_empty ();
    void print ();
};

#endif