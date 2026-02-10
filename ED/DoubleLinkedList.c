#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* prox;
    struct Node* passado;
} Node;

typedef struct Lista{
    int size;
    Node* head;
    Node* ultimo;
} Lista;

Lista* createList(){
    Lista* novaLista = (Lista*) malloc(sizeof(Lista));
    novaLista->head = NULL;
    novaLista->ultimo = NULL;
    novaLista->size = 0;

    return novaLista;
}

void addElem(int num, Lista* minhaLista){
    Node* novo = malloc(sizeof(Node));
    novo->val = num;

    if (minhaLista->head == NULL){
        minhaLista->head = novo;
        minhaLista->ultimo = novo;
    }
    else{
        minhaLista->ultimo->prox = novo;
        novo->passado = minhaLista->ultimo;
        minhaLista->ultimo = novo;
        novo->prox = NULL;
    }

    minhaLista->size++;
}

void deleteElem(Lista* minhaLista, int num){
    Node* referenceNode = minhaLista->head;
    int close = 0, cont = 0;

    while (close == 0){
        if (referenceNode->val == num && referenceNode == minhaLista->head){
            referenceNode->prox->passado = NULL;
            free(referenceNode);

            close = 1;
        }
        else if (referenceNode->val == num && referenceNode == minhaLista->ultimo){
            referenceNode->passado->prox = NULL;
            free(referenceNode);

            close = 1;
        }
        else if (referenceNode->val == num){
            referenceNode->passado->prox = referenceNode->prox;
            referenceNode->prox->passado = referenceNode->passado;
            free(referenceNode);

            close = 1;
        }

        referenceNode = referenceNode->prox;
        cont++;

        if (cont == 100000 || referenceNode->prox == NULL){
            printf("elemento n existe\n");
            break;
        }
    }
}

void printLista(Lista* minhaLista){
    Node* referenceNode = minhaLista->head;

    while (referenceNode != NULL){
        printf("%d ", referenceNode->val);
        referenceNode = referenceNode->prox;
    }

    printf("\n");
}

int main(){
    int n, x, del;
    scanf("%d", &n);

    Lista* minhaLista = createList();

    for (int i = 0; i < n; i++){
        scanf("%d", &x);

        addElem(x, minhaLista);
    }

    printLista(minhaLista);

    scanf("%d", &del);
    deleteElem(minhaLista, del);

    printLista(minhaLista);

    return 0;
}