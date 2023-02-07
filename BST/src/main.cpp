// Author: Lucas Berg
// Compile: g++ -o main main.cpp
// Execute: ./main

#include <bits/stdc++.h>
#include "bst/bst.h"

using namespace std;

int main ()
{
    BinarySearchTree<int> *bst = new BinarySearchTree<int>();
    bst->insert_node(10);
    bst->insert_node(5);
    bst->insert_node(19);
    bst->insert_node(1);
    bst->insert_node(6);
    bst->insert_node(17);
    bst->insert_node(21);

    bst->print(0);  // In-order
    bst->print(1);  // Pos-order
    bst->print(2);  // Pre-order

    delete bst;
    return 0;
}