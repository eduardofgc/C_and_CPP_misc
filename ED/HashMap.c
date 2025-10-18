//unfinished

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_MAX 20

typedef struct User{
    char name[10];
    int age;
} User;

int getHashValue(User* myUser){
    int cont = 0;

    for (int i = 0; i < strlen(myUser->name); i++){
        cont = cont + myUser->name[i];
    }

    cont = (cont * myUser->age) % TABLE_MAX;
    return cont;
}   

int main(){
    User* userHashTable[TABLE_MAX];

    for (int i = 0; i < TABLE_MAX; i++){
        userHashTable[i] = NULL;
    } //userHashTable = {NULL}

    int n, x, val, cont;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        User* newUser = (User*)malloc(sizeof(User));
        scanf("%d", &newUser->age);
        scanf("%s", newUser->name);
        
        User* referenceUser = userHashTable[i];
        cont = i;

        if (referenceUser == NULL){
            val = getHashValue(newUser);
            userHashTable[val] = newUser;
        }
        else{
            while (referenceUser != NULL){ //acho q nn funciona
                referenceUser = userHashTable[cont+1];
                cont++;
            }
        }    
    }

    return 0;
}