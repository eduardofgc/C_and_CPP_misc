#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int key;
    struct Node *left, *right, *parent;
    int size;
} Node;

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
