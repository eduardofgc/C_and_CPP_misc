#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int idade;
    struct Node* prox;
    struct Node* past;
    bool priority1, priority2;
} Node;

typedef struct List{
    Node* head;
    Node* last;
    int size;
} List;

List* queue(){
    List* myList = (List*) malloc(sizeof(List));

    myList->head = NULL;
    myList->last = NULL;
    myList->size = 0;
    
    return myList;
}

void enqueue(List* myList, int index){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->idade = index;

    if (myList->last == NULL){
        myList->head = newNode;
        myList->last = newNode;
    }
    else{
        myList->last->prox = newNode;
        newNode->past = myList->last;
        myList->last = newNode;
    }

    newNode->prox = NULL;
    myList->size++;
}

void dequeue(List* myList){
    if (myList->head == NULL){
        printf("list has no nodes.\n");
    }
    else{
        Node* referenceNode = myList->head;
        myList->head = myList->head->prox;
        myList->head->past = NULL;
        
        free(referenceNode);
        myList->size--;
    }
}

Node* front(List* myList){
    if (myList->head == NULL){
        printf("list has no nodes\n");
    }

    return myList->head;
}

bool isEmpty(List* myList){
    if (myList->head == NULL){
        return true;
    }
    else{
        return false;
    }
}

int size(List* myList){
    return myList->size;
}

void swapNodes(List* myList, int index1, int index2){
    if (index1 == index2) return;

    Node* referenceNode1 = myList->head;
    Node* referenceNode2 = myList->head;

    while (referenceNode1 && referenceNode1->idade != index1)
        referenceNode1 = referenceNode1->prox;

    while (referenceNode2 && referenceNode2->idade != index2)
        referenceNode2 = referenceNode2->prox;

    if (!referenceNode1 || !referenceNode2) return;

    Node* referenceNode1_past = referenceNode1->past;
    Node* referenceNode1_prox = referenceNode1->prox;

    Node* referenceNode2_past = referenceNode2->past;
    Node* referenceNode2_prox = referenceNode2->prox;

    referenceNode1->past = referenceNode2_past;
    referenceNode1->prox = referenceNode2_prox;

    referenceNode2->past = referenceNode1_past;
    referenceNode2->prox = referenceNode1_prox;

    if (referenceNode1_past) referenceNode1_past->prox = referenceNode2;
    if (referenceNode1_prox) referenceNode1_prox->past = referenceNode2;

    if (referenceNode2_past) referenceNode2_past->prox = referenceNode1;
    if (referenceNode2_prox) referenceNode2_prox->past = referenceNode1;

    if (myList->head == referenceNode1)
        myList->head = referenceNode2;

    else if (myList->head == referenceNode2)
        myList->head = referenceNode1;
}

int main(){
    int n, ex;
    List* myList = queue();

    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", &ex);
        enqueue(myList, ex);
    }

    printf("current size: %d\n", size(myList));
    printf("deleting head now...\n");

    dequeue(myList);

    printf("current size: %d", size(myList));

    return 0;
}