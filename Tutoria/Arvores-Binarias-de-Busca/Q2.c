#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int key;
    struct Node *left, *right, *parent;
    int size;
} Node;

void imprime_ordem_inversa(Node *raiz) {
    if (raiz == NULL) return;
    imprime_ordem_inversa(raiz->right);
    printf("%d ", raiz->key);
    imprime_ordem_inversa(raiz->left);
}
