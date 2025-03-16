#include <iostream>

class Dog{
    public:
        std::string name;
        std::string breed;
        std::string gender;
        int age;

        void bark(){
            std::cout << "woof\n";
        }

        int months_alive(Dog A){
            int day_age = 12 * A.age;

            return day_age;
        }

        Dog(std::string name, std::string breed, std::string gender, int age){
            this->name = name;
            this->breed = breed;
            this->gender = gender;
            this->age = age;
        }
};

int main (){
    std::string nome, raca, genero;
    int idade;

    std::cin >> nome;
    std::cin >> raca;
    std::cin >> genero;
    std::cin >> idade;

    Dog spike(nome, raca, genero, idade);

    spike.bark();
    std::cout << spike.months_alive(spike) << "\n";

    return 0;
}