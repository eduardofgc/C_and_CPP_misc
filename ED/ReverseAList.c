#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct{
    Node* head;
    int size
} List;

List* createList(){
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;

    return list;
}

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void addNode(List* list, int data){
    Node* newNode = createNode(data);

    if (list->head == NULL){
        list->head = newNode;
    } 
    else{
        Node* current = list->head;

        while (current->next != NULL){
            current = current->next;
        }

        current->next = newNode;
    }
}

void printList(List* list){
    Node* current = list->head;

    while (current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

void reverseList(List* list){
    Node* prev = NULL;
    Node* curr = list->head;
    Node* next = NULL;

    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    list->head = prev;
}

void freeList(List* list){
    Node* current = list->head;

    while (current != NULL){
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    free(list);
}

int main(){
    List* list = createList();

    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);

    printf("Original list:\n");
    printList(list);

    reverseList(list);

    printf("Reversed list:\n");
    printList(list);

    freeList(list);

    return 0;
}