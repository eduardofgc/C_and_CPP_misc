#include <iostream>
#include <conio.h>

const int height = 20;
const int width = 20;
int x, y, fruit_x, fruit_y, score = 0;
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

    std::cout << "score: " << score;
}

void Simulate(){ //handles user input via keyboard

    if (_kbhit){ //part of conio.h, detects if key is pressed

        switch(_getch()){ //gets the ascii table value of pressed char

            case 'a':
                dir = LEFT;
                break;

            case 'd':
                dir = RIGHT;
                break;

            case 'w':
                dir = UP;
                break;

            case 's':
                dir = DOWN;
                break;

            case 'x':
                endGame = true;
                break;
        }
    }
}

void Logic(){
    switch (dir){
        case LEFT:
            y--;
            break;

        case RIGHT:
            y++;
            break;

        case UP:
            x--;
            break;

        case DOWN:
            x++;
            break;
    }

    if (x > width || x < 0 || y > height ||y < 0){ //ends if out of bounds
        endGame = true;
    }
    else if (x == fruit_x && y == fruit_y){ //if eats fruit
        score++;

        fruit_x = rand() % width;
        fruit_y = rand() % height;
    }
}

int main(){
    srand(time(NULL));

    Setup();
    
    while (!endGame){
        Draw();
        Simulate();
        Logic();
    }

    return 0;
}