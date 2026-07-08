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

void imprime_ordem_inversa(Node *raiz) {
    if (raiz == NULL) return;
    imprime_ordem_inversa(raiz->right);
    printf("%d ", raiz->key);
    imprime_ordem_inversa(raiz->left);
}

void imprime_intervalo(Node *raiz, int x, int y) {
    if (raiz == NULL) return;
    if (raiz->key > x) imprime_intervalo(raiz->left, x, y);
    if (raiz->key >= x && raiz->key <= y) printf("%d ", raiz->key);
    if (raiz->key < y) imprime_intervalo(raiz->right, x, y);
}

void preenche_vetor(Node *raiz, int *vet, int *idx) {
    if (raiz == NULL) return;
    preenche_vetor(raiz->left, vet, idx);
    vet[(*idx)++] = raiz->key;
    preenche_vetor(raiz->right, vet, idx);
}
 
void imprime_duas_arvores(Node *raiz1, int n, Node *raiz2, int m) {
    int *v1 = malloc(n * sizeof(int));
    int *v2 = malloc(m * sizeof(int));
    int i1 = 0, i2 = 0;
    preenche_vetor(raiz1, v1, &i1);
    preenche_vetor(raiz2, v2, &i2);
 
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (v1[i] <= v2[j]) printf("%d ", v1[i++]);
        else printf("%d ", v2[j++]);
    }
    while (i < n) printf("%d ", v1[i++]);
    while (j < m) printf("%d ", v2[j++]);
    printf("\n");
 
    free(v1);
    free(v2);
}