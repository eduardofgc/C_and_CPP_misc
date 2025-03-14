#include <iostream>

struct estudante{
    std::string nome, mencao;
    double nota;
};

void mudar_nota(estudante &est, double nova){
    est.nota = nova;
}

int main (){
    double nova_nota;
    std::cin >> nova_nota;

    estudante eduardo;
    eduardo.nota = 5;

    mudar_nota(eduardo, nova_nota);
    std::cout << eduardo.nota;

    return 0;
}