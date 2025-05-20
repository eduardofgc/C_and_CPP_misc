#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int valor;
    struct Node* prox;
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
    newNode->valor = index;

    if (myList->last == NULL){
        myList->head = newNode;
        myList->last = newNode;
    }
    else{
        myList->last->prox = newNode;
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

int main(){
    int n;
    List* myList = queue();

    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        enqueue(myList, i+1);
    }

    printf("current size: %d\n", size(myList));
    printf("deleting head now...\n");

    dequeue(myList);

    printf("current size: %d", size(myList));


    return 0;
}