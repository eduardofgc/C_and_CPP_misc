#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int id;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree{
    Node* root;
} Tree; 

Tree* createTree(){
    Tree* myTree = (Tree*)malloc(sizeof(Tree));
    myTree->root = NULL;

    return myTree;
}

void createNode(Tree* myTree, int num){
    Node* myNode = (Node*)malloc(sizeof(Node));
    myNode->id = num;

    myNode->left = NULL;
    myNode->right = NULL;

    if (myTree->root == NULL){
        myTree->root = myNode;
    }
    else{
        Node* referenceNode = myTree->root;

        while (1){
            if (myNode->id > referenceNode->id && referenceNode->right != NULL){
                referenceNode = referenceNode->right;
            }
            else if (myNode->id < referenceNode->id && referenceNode->left != NULL){
                referenceNode = referenceNode->left;
            }
            else if (myNode->id > referenceNode->id && referenceNode->right == NULL){
                referenceNode->right = myNode;
                break;
            }
            else if (myNode->id < referenceNode->id && referenceNode->left == NULL){
                referenceNode->left = myNode;
                break;
            }
        }
    }
}

Node* findNode(Tree* myTree, int num){
    Node* referenceNode = myTree->root;
    int cont = 0;

    while (referenceNode != NULL && cont < 1000){
        if (num > referenceNode->id){
            referenceNode = referenceNode->right;
        }
        else if (num < referenceNode->id){
            referenceNode = referenceNode->left;
        }
        else if (num == referenceNode->id){
            break;
        }

        cont++;
    }

    return referenceNode;
}

int main(){
    Tree* myTree = createTree();

    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        createNode(myTree, x);
    }

    scanf("%d", &x);

    Node* myNode = findNode(myTree, x);
    
    if (myNode != NULL) printf("%d\n", myNode->id);
    else printf("node not found\n");

    return 0;
}