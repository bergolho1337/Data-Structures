// Author: Lucas Berg
//  Solution to entry question from 'EntrevistaDeCodigoBR' Discord channel
// Compile: g++ -o main main.cpp
// Execute: ./main

#include <bits/stdc++.h>

using namespace std;

// Binary Search Tree Implementations
struct no {
    no *esquerda;
    no *direita;
    int valor;
}typedef no;

no* inicializa_ABB () {
    return nullptr;
}

bool vazia_ABB (no *raiz) {
    return (!raiz) ? true : false;
}

no* libera_ABB (no *raiz) {
    if (!vazia_ABB(raiz)) {
        raiz->esquerda = libera_ABB(raiz->esquerda);
        raiz->direita = libera_ABB(raiz->direita);
        free(raiz);
    }
    return nullptr;
}

no* insere_ABB (no *raiz, const int val) {
    // First node in the tree
    if (raiz == nullptr) {
        raiz = (no*)malloc(sizeof(no));
        raiz->valor = val;
        raiz->esquerda = nullptr;
        raiz->direita = nullptr;
    }
    // The tree has nodes already ...
    else {
        // Binary Search Tree property
        // Right-subtree must contain values greater than current node
        if (val > raiz->valor) {
            raiz->direita = insere_ABB(raiz->direita,val);
        }
        // Left-subtree must contain values less than current node
        else if (val < raiz->valor) {
            raiz->esquerda = insere_ABB(raiz->esquerda,val);
        }
        else {
            fprintf(stderr,"[-] ERRO! Valor '%d' jah se encontra na arvore!\n",val);
        }
    }
    return raiz;
}

// Question function
// Solution: O(n)
void imprime_in_order (no *raiz) {
    if (raiz != nullptr) {
        // Search the left-subtree
        imprime_in_order (raiz->esquerda);

        // Process the node
        printf("%d\n", raiz->valor);

        // Search the right-subtree
        imprime_in_order (raiz->direita);
    }
}

// MAIN PROGRAM
int main () {
    no *abb_raiz = inicializa_ABB();
    abb_raiz = insere_ABB(abb_raiz,10);
    abb_raiz = insere_ABB(abb_raiz,5);
    abb_raiz = insere_ABB(abb_raiz,19);
    abb_raiz = insere_ABB(abb_raiz,1);
    abb_raiz = insere_ABB(abb_raiz,6);
    abb_raiz = insere_ABB(abb_raiz,17);
    abb_raiz = insere_ABB(abb_raiz,21);

    // Question function
    // Solution: O(n)
    imprime_in_order(abb_raiz);

    libera_ABB(abb_raiz);

    return 0;
}