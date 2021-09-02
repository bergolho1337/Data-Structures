#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

// ------------------------------------------------------------------------------------------------------
// SINGLY LINKED LIST
template<class T>
class SLLNode
{
private:
    uint32_t id;
    T value;
    SLLNode *next;
public:
    SLLNode (const uint32_t id, const T &value, SLLNode *next = nullptr)
    {
        this->id = id;
        this->value = value;
        this->next = next;
    }
    ~SLLNode ()
    {
        this->next = nullptr;
    }
    inline uint32_t get_id () { return this->id; }
    inline T get_value () { return this->value; }
    inline SLLNode* get_next () { return this->next; }
    inline void set_id (const uint32_t id) { this->id = id; }
    inline void set_value (const T value) { this->value = value; }
    inline void set_next (SLLNode *next) { this->next = next; }
    void print ()
    {
        printf("|| %u [%g] ||", this->id, this->value);
    }
};

template<class T>
class SinglyLinkedList
{
private:
    uint32_t num_nodes;
    SLLNode<T> *head;
    SLLNode<T> *tail;
public:
    SinglyLinkedList ();
    ~SinglyLinkedList ();
    inline uint32_t get_num_nodes () { return this->num_nodes; }
    SLLNode<T>* insert_to_head (const T&);
    SLLNode<T>* insert_to_tail (const T&);
    SLLNode<T>* search_element (const T&);
    T delete_from_head ();
    T delete_from_tail ();
    bool delete_node (const T);
    bool is_empty ();
    void print ();
};

template<class T>
SinglyLinkedList<T>::SinglyLinkedList ()
{
    this->num_nodes = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList ()
{
    while (!is_empty())
    {
        delete_from_head();
    }
}

template<class T>
SLLNode<T>* SinglyLinkedList<T>::insert_to_head (const T &value)
{
    uint32_t num_nodes = this->num_nodes;
    this->head = new SLLNode<T>(num_nodes,value,this->head);
    if (!this->tail)
        this->tail = this->head;
    this->num_nodes++;
    return this->head;
}

template<class T>
SLLNode<T>* SinglyLinkedList<T>::insert_to_tail (const T &value)
{
    uint32_t num_nodes = this->num_nodes;
    if (this->tail)
    {
        this->tail->set_next(new SLLNode<T>(num_nodes,value));
        this->tail = this->tail->get_next();
    }
    else
    {
        this->head = this->tail = new SLLNode<T>(num_nodes,value);
    }
    this->num_nodes++;
    return this->tail;
}

template<class T>
SLLNode<T>* SinglyLinkedList<T>::search_element (const T &value)
{
    SLLNode<T> *tmp = this->head;
    while (tmp != NULL)
    {
        if (tmp->get_value() == value) return tmp;
        tmp = tmp->get_next();
    }
    return nullptr;
}

template<class T>
T SinglyLinkedList<T>::delete_from_head ()
{
    if (this->head)
    {
        double result = this->head->get_value();
        SLLNode<T> *tmp = this->head;
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

template<class T>
T SinglyLinkedList<T>::delete_from_tail ()
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
            SLLNode<T> *tmp2 = this->head;
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

template<class T>
bool SinglyLinkedList<T>::delete_node (const T value)
{
    SLLNode<T> *tmp = this->head;
    SLLNode<T> *tmp2 = tmp;
    
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

template<class T>
void SinglyLinkedList<T>::print ()
{
    if (is_empty())
        printf("[!] The list is EMPTY!\n");
    
    SLLNode<T> *tmp = this->head;
    while (tmp != NULL)
    {
        tmp->print();
        printf(" --> ");
        tmp = tmp->get_next();
    }
    printf("\n");
}

template<class T>
bool SinglyLinkedList<T>::is_empty ()
{
    return (this->num_nodes == 0) ? true : false;
}

// ------------------------------------------------------------------------------------------------------
// DOUBLY LINKED LIST
template<class T>
class DLLNode
{
private:
    uint32_t id;
    T value;
    DLLNode *next, *prev;
public:
    DLLNode (const uint32_t id, const T &value, DLLNode *next = nullptr, DLLNode *prev = nullptr)
    {
        this->id = id;
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
    ~DLLNode ()
    {
        this->next = this->prev = nullptr;
    }
    inline uint32_t get_id () { return this->id; }
    inline T get_value () { return this->value; }
    inline DLLNode* get_next () { return this->next; }
    inline DLLNode* get_prev () { return this->prev; }
    inline void set_id (const uint32_t id) { this->id = id; }
    inline void set_value (const T value) { this->value = value; }
    inline void set_next (DLLNode *next) { this->next = next; }
    inline void set_prev (DLLNode *prev) { this->prev = prev; }
    void print ()
    {
        printf("|| %u [%g] ||", this->id, this->value);
    }
};

template<class T>
class DoublyLinkedList
{
private:
    uint32_t num_nodes;
    DLLNode<T> *head;
    DLLNode<T> *tail;
public:
    DoublyLinkedList ();
    ~DoublyLinkedList ();
    inline uint32_t get_num_nodes () { return this->num_nodes; }
    void insert_to_tail (const T&);
    T delete_from_tail ();
    void print ();
    bool is_empty ();
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList ()
{
    this->num_nodes = 0;
    this->head = this->tail = nullptr;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList ()
{
    while (!is_empty())
    {
        delete_from_tail();
    }
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
    this->num_nodes++;
}

template<class T>
T DoublyLinkedList<T>::delete_from_tail ()
{
    if (this->tail)
    {
        T result = this->head->get_value();
        if (this->head == this->tail)
        {
            delete this->tail;
            this->head = this->tail = nullptr;
        }
        else
        {
            this->tail = this->tail->get_prev();
            delete this->tail->get_next();
            this->tail->set_next(nullptr);
        }
        return result;
    }
    else
    {
        fprintf(stderr,"[-] ERROR! On 'delete_from_tail'! The list is empty!\n");
        return 0;
    }
}

template<class T>
void DoublyLinkedList<T>::print ()
{
    if (is_empty())
    {
        printf("The list is empty!\n");
        return;
    }
    DLLNode<T> *tmp = this->head;
    while (tmp != NULL)
    {
        tmp->print();
        printf(" --> ");
        tmp = tmp->get_next();
    }
    printf("\n");
}

template<class T>
bool DoublyLinkedList<T>::is_empty ()
{
    return (this->head) ? false : true;
}

#endif