#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* next;
    struct Node* past;
    int ticket;
} Node;

typedef struct Stack{
    Node* head;
    Node* last;
    int size;
} Stack;

Stack* createStack(){
    Stack* myStack = (Stack*) malloc(sizeof(Stack));
    myStack->head = NULL;
    myStack->last = NULL;
    myStack->size = 0;

    return myStack;
}

void addNode(Stack* myStack, int num){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->ticket = num;
    newNode->next = NULL;

    if (myStack->head == NULL){
        newNode->past = NULL;
        myStack->head = newNode;
        myStack->last = newNode;
    }
    else{
        myStack->head->past = newNode;
        newNode->next = myStack->head;
        myStack->head = newNode;
    }

    myStack->size++;
}

void takeNode(Stack* myStack){
    Node* referenceNode = myStack->head;
    printf("%d\n", myStack->head->ticket);

    if (myStack->head == myStack->last){
        myStack->head = NULL;
        myStack->last = NULL;
        free(referenceNode);
    }
    else{
        referenceNode->next->past = NULL;
        myStack->head = referenceNode->next;
        free(referenceNode);
    }

    myStack->size--;
}

int main(){
    Stack* myStack = createStack();
    int n, x, y;

    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", &x);

        if (x == 1){
            scanf("%d", &y);

            addNode(myStack, y);
        }
        else{
            if (myStack->head == NULL){
                printf("0\n");
            }
            else{
                takeNode(myStack);
            }
        }
    }

    return 0;
}