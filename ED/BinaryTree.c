#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int id;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree{
    Node* root;
    int height;
} Tree; 

Tree* createTree(){
    Tree* myTree = (Tree*)malloc(sizeof(Tree));
    myTree->root = NULL;
    myTree->height = 0;

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
    
    myTree->height++;
}

int main(){

    return 0;
}