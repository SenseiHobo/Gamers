#include <iostream> 
#include <cstdlib> 
#include "menu.h"
#include "database.h"
#include "Intro.h"
#include "Tool.h"

auto spell = createSpells();
int getNumericInput();


void start(){
    system("clear");
    
    std::cout << std::endl << std::endl;
    slow_print("Welcome to Hobo Adventure ");
    std::cout << std::endl << std::endl;
    slow_print("Press 1 to continue: ");
   
    int a = getKeypress();

    std::cout << std::endl<<std::endl;

    if(a == '1'){
        system("clear");
        tutorial();
    } else {
        start();
    }

}   




void selector() {
    char a = 0;
    do {
        slow_print("Select your action");
        std::cout << std::endl << std::endl;
        std::cout << "Type 1 to create a new hero" << std::endl;
        std::cout << "Type 2 to see current heroes" << std::endl;
        std::cout << "Type 3 to load a hero" << std::endl;
        std::cout << "Type 4 to delete a hero" << std::endl;
        std::cout << "Type 5 to exit game" << std::endl << std::endl;
        std::cout << "Enter your choice: ";

        a = getKeypress();
        std::cout << std::endl;

        switch (a) {
            case '1':
                createHero();
                break;
            case '2':
                ShowHeroes();
                break;
            case '3':
                loadHero(spell);
                break;
            case '4':
                deleteHero();
                break;
            case '5':
                exit(0);
                break;
            default:
                std::cout << "Invalid input, press enter twice to try again" << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                system("clear");
                continue;
        }
    } while (a < '1' || a > '5');
}
