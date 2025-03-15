#include <iostream>

class dog{
    public:
        std::string name;
        std::string breed;
        std::string gender;
        int age;

        void bark(){
            std::cout << "woof\n";
        }

        int months_alive(dog A){
            int day_age = 12 * A.age;

            return day_age;
        }
};

int main (){
    dog spike;

    std::cin >> spike.name;
    std::cin >> spike.breed;
    std::cin >> spike.gender;
    std::cin >> spike.age;

    spike.bark();
    std::cout << spike.name << " is " << spike.months_alive(spike) << " months old.\n";

    return 0;
}