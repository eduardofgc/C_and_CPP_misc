#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int key;
    struct Node *left, *right, *parent;
    int size;
} Node;

Node* antecessor(Node *x) {
    if (x == NULL) return NULL;
    if (x->left != NULL) return maximo(x->left);
    Node *y = x->parent;
    while (y != NULL && x == y->left) {
        x = y;
        y = y->parent;
    }
    return y;
}

