#include <iostream>
#include <conio.h>

const int height = 20;
const int width = 20;
int x, y, fruit_x, fruit_y, score;
enum Direct {STOP = 0, UP, DOWN, LEFT, RIGHT};
Direct dir;

bool endGame;

void Setup(){
    endGame = false;

    //starting xpos & ypos
    x = width/2;
    y = height/2;
    dir = STOP;

    fruit_x = rand() % width;
    fruit_y = rand() % height;

    score = 0;
}

void Draw(){
    system("cls"); //clear screen on cmd

    //ceiling
    for (int i = 0; i < width; i++){
        std::cout << "-";
    }

    std::cout << "\n";

    for (int i=0; i < width; i++){

        for (int j=0; j < height; j++){

            if (j == 0 || j == width-1){
                std::cout << "|";
            }
            else if (j == y && i == x){
                std::cout << "O";
            }
            else if (j == fruit_y && i == fruit_x){
                std::cout << "*";
            }
            else{
                std::cout << " ";
            }
        }

        std::cout << "\n";
    }


    //floor
    for (int i=0; i < width; i++){
        std::cout << "-";
    }

    std::cout << "\n";
}

void Simulate(){

    if (_kbhit){ //part of conio.h, detects if key is pressed
        switch(_getch()){ //gets the ascii table value of pressed char

        }
    }
}

void Logic(){

}

int main(){
    srand(time(NULL));
    
    Setup();
    Draw();

    return 0;
}