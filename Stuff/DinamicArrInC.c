#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *list;
    int index, cap;
} DinamicArray;

void Construct(DinamicArray *dinamicExample, int capacity){
    dinamicExample->cap = capacity;
    dinamicExample->index = 0;
    dinamicExample->list = malloc(sizeof(int) * dinamicExample->cap);
}

void Destruct(DinamicArray *dinamicExample){
    free(dinamicExample->list);
}

void Resize(DinamicArray *dinamicExample){
    int *newList = malloc(sizeof(int) * dinamicExample->cap * 2);

    for (int i = 0; i < dinamicExample->index; i++){
        newList[i] = dinamicExample->list[i];
    }

    free(dinamicExample->list);
    dinamicExample->list = newList;
    dinamicExample->cap *= 2;
}

void AddElem(DinamicArray *dinamicExample, int val){
    if (dinamicExample->index == dinamicExample->cap){
        Resize(dinamicExample);
    }

    dinamicExample->list[dinamicExample->index] = val;
    dinamicExample->index++;
}

void PrintElems(DinamicArray *dinamicExample){

    for (int i = 0; i < dinamicExample->index; i++){
        printf("%d ", dinamicExample->list[i]);
    }

    printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);

    DinamicArray dinamico;
    Construct(&dinamico, 2);

    for (int i = 0; i < n; i++){
        AddElem(&dinamico, i+1);

        printf("Current capacity: %d\n", dinamico.cap);
        printf("Elements: ");
        PrintElems(&dinamico);

        printf("#######################################\n");
    }

    Destruct(&dinamico);

    return 0;
}