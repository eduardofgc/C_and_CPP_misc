#include <iostream>

class Node{
    public:
        int valor;
        Node* p_prox;
};

int main (){
    Node* novo; //n = new Node;
    Node* head; //primeiro node
    Node* temp; //aponta pro próximo, porque interpreta t->p_prox = n;

    //1 node (cabeça)
    novo = new Node;
    novo->valor = 1;
    temp = novo;
    head = novo;

    //2 node (corpo)
    novo = new Node;
    novo->valor = 2;
    temp->p_prox = novo;
    temp = temp->p_prox;

    //3 node (fim)
    novo = new Node;
    novo->valor = 3;
    temp->p_prox = novo;
    temp = temp->p_prox;

    novo->p_prox = NULL;

    //    note to self: revisar lógica dessa lista (desenhar) e refazê-la usando um objeto para a própria lista e um loop for
    //    para definir o tamanho da lista que será determinado de acordo com input.

    return 0;
}