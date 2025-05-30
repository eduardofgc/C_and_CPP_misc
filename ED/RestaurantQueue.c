#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int ticket;

    struct Node* next;
    struct Node* past;
} Node;

typedef struct Queue{
    Node* head;
    Node* last;
    int size;
} Queue;

Queue* createQueue(){
    Queue* myQueue = (Queue*) malloc(sizeof(Queue));
    myQueue->head = NULL;
    myQueue->last = NULL;
    myQueue->size = 0;

    return myQueue;
}

void addNode(Queue* myQueue, int num){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->ticket = num;

    if (myQueue->head == NULL){
        myQueue->head = newNode;
        myQueue->last = newNode;
    }
    else{
        myQueue->last->next = newNode;
        newNode->past = myQueue->last;
        myQueue->last = newNode;
    }

    myQueue->size++;
}

void dequeue(Queue* myQueue){
    Node* referenceNode = myQueue->head;
    printf("%d\n", myQueue->head->ticket);

    if (myQueue->head->next == NULL){
        myQueue->head = NULL;
    }
    else{
        myQueue->head = myQueue->head->next;
        myQueue->head->past = NULL;
    }

    free(referenceNode);
    myQueue->size--;
}

int main(){
    int n, x, y = 101;
    scanf("%d", &n);

    Queue* myQueue = createQueue();

    for (int i = 0; i < n; i++){
        scanf("%d", &x);

        if (x == 1){
            scanf("%d", &y);

            addNode(myQueue, y);
        }
        else{
            dequeue(myQueue);
        }
    }

    return 0;
}