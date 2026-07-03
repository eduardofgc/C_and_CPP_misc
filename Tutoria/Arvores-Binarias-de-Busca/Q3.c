#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int key;
    struct Node *left, *right, *parent;
    int size;
} Node;

void imprime_intervalo(Node *raiz, int x, int y) {
    if (raiz == NULL) return;
    if (raiz->key > x) imprime_intervalo(raiz->left, x, y);
    if (raiz->key >= x && raiz->key <= y) printf("%d ", raiz->key);
    if (raiz->key < y) imprime_intervalo(raiz->right, x, y);
}
