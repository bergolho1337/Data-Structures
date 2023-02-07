#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

// ------------------------------------------------------------------------------------------------------
// BINARY SEARCH TREE
template<class T>
class BSTNode
{
public:
    uint32_t id;
    T value;
    BSTNode *left;
    BSTNode *right;
public:
    BSTNode (const uint32_t id, const T &value, BSTNode *left = nullptr, BSTNode *right = nullptr)
    {
        this->id = id;
        this->value = value;
        this->left = left;
        this->right = right;
    }
    ~BSTNode ()
    {
        this->left = nullptr;
        this->right = nullptr;
    }
    inline uint32_t get_id () { return this->id; }
    inline T get_value () { return this->value; }
    inline BSTNode* get_left () { return this->left; }
    inline BSTNode* get_right () { return this->right; }
    inline void set_id (const uint32_t id) { this->id = id; }
    inline void set_value (const T value) { this->value = value; }
    inline void set_left (BSTNode *left) { this->left = left; }
    inline void set_right (BSTNode *right) { this->right = right; }
    void print ()
    {
        printf("|| %u [%g] ||", this->id, this->value);
    }
};

template<class T>
class BinarySearchTree
{
public:
    uint32_t num_nodes;
    BSTNode<T> *root;
public:
    BinarySearchTree ();
    ~BinarySearchTree ();
    inline uint32_t get_num_nodes () { return this->num_nodes; }
    BSTNode<T>* insert_node (const T &value);
    T delete_node (const T);
    BSTNode<T>* free_BST (BSTNode<T> *root);
    bool is_empty ();
    void print (int type);
private:
    BSTNode<T>* insert_node_aux (BSTNode<T> *root, const T &value);
    void print_in_order (BSTNode<T> *root);
    void print_pre_order (BSTNode<T> *root);
    void print_pos_order (BSTNode<T> *root);
};

template<class T>
BinarySearchTree<T>::BinarySearchTree ()
{
    this->num_nodes = 0;
    this->root = nullptr;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree ()
{
    if (this->root) {
        free_BST(this->root);
    }
}

template<class T>
BSTNode<T>* BinarySearchTree<T>::free_BST (BSTNode<T> *root)
{
    if (root)
    {
        root->left = free_BST(root->left);
        root->right = free_BST(root->right);
        delete root;
    }
    return nullptr;
}

template<class T>
BSTNode<T>* BinarySearchTree<T>::insert_node (const T &value)
{
    this->root = insert_node_aux(this->root,value);
    return this->root;
}

template<class T>
BSTNode<T>* BinarySearchTree<T>::insert_node_aux (BSTNode<T> *root, const T &value)
{
    // First node in the tree
    if (root == nullptr) {
        root = new BSTNode<T>(this->num_nodes++,value);
    }
    // The tree has nodes already ...
    else {
        // Binary Search Tree property
        // Right-subtree must contain values greater than current node
        if (value > root->value) {
            root->right = insert_node_aux(root->right,value);
        }
        // Left-subtree must contain values less than current node
        else if (value < root->value) {
            root->left = insert_node_aux(root->left,value);
        }
        else {
            fprintf(stderr,"[-] ERROR! Value is already in the BST tree!\n");
        }
    }
    return root;
}

// type of printing:
// 0 = IN-ORDER
// 1 = PRE-ORDER
// 2 = POS-ORDER
template<class T>
void BinarySearchTree<T>::print (const int type)
{
    if (this->root != nullptr) {
        switch (type) {
            case 0:
                printf("Printing in-order\n");
                print_in_order(this->root);
                break;
            case 1:
                printf("Printing pre-order\n");
                print_pre_order(this->root);
                break;
            case 2:
                printf("Printing pos-order\n");
                print_pos_order(this->root);
                break;
            default:
                break;
        }
    }
}
 
template<class T>
void BinarySearchTree<T>::print_in_order (BSTNode<T> *root)
{
    if (root != nullptr) {
        // Search the left-subtree
        print_in_order(root->left);

        // Process the node
        printf("%d\n", root->value);

        // Search the right-subtree
        print_in_order(root->right);
    }
}

template<class T>
void BinarySearchTree<T>::print_pre_order (BSTNode<T> *root)
{
    if (root != nullptr) {
        // Process the node
        printf("%d\n", root->value);

        // Search the left-subtree
        print_pre_order(root->left);

        // Search the right-subtree
        print_pre_order(root->right);
    }
}

template<class T>
void BinarySearchTree<T>::print_pos_order (BSTNode<T> *root)
{
    if (root != nullptr) {
        // Search the left-subtree
        print_pos_order(root->left);

        // Search the right-subtree
        print_pos_order(root->right);

        // Process the node
        printf("%d\n", root->value);
    }
}

#endif