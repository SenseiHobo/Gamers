#include <iostream> 
#include <cstdlib> 
#include "menu.h"
#include "database.h"
#include "Intro.h"
#include "Tool.h"

auto spell = DB1.createSpells();


void Menu::start(){
    system("clear");
    
    std::cout << std::endl << std::endl;
    Too.slow_print("Welcome to Hobo Adventure ");
    std::cout << std::endl << std::endl;
    Too.slow_print("Press 1 to continue: ");
   
    int a = Too.getKeypress();

    std::cout << std::endl<<std::endl;

    if(a == '1'){
        system("clear");
        T1.tutorial();
    } else {
        start();
    }

}   




void Menu::selector() {
    char a = 0;
    do {
        Too.slow_print("Select your action");
        std::cout << std::endl << std::endl;
        std::cout << "Type 1 to create a new hero" << std::endl;
        std::cout << "Type 2 to see current heroes" << std::endl;
        std::cout << "Type 3 to load a hero" << std::endl;
        std::cout << "Type 4 to delete a hero" << std::endl;
        std::cout << "Type 5 to exit game" << std::endl << std::endl;
        std::cout << "Enter your choice: ";

        a = Too.getKeypress();
        std::cout << std::endl;

        switch (a) {
            case '1':
                DB1.createHero();
                break;
            case '2':
                DB1.ShowHeroes();
                break;
            case '3':
                DB1.loadHero(spell);
                break;
            case '4':
                DB1.deleteHero();
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

Menu M1;