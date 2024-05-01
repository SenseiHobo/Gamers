#include <iostream> 
#include <cstdlib> 
#include "menu.h"
#include "database.h"
#include "Tool.h"

auto spell = createSpells();
int getNumericInput();


void start(){
    system("clear");
    int a = 0;
    std::cout << std::endl << std::endl;
    slow_print("Welcome to Hobo Adventure ");
    std::cout << std::endl << std::endl;
    slow_print("Press 1 to continue: ");
    a = getNumericInput();
    std::cout << std::endl<<std::endl;

    if(a == 1){
        system("clear");
        selector();
    } else {
        start();
    }

}   




void selector(){
    int a = 0; 

    slow_print("Select your action");
    std::cout << std::endl << std::endl;
    std::cout << "type 1 to create a new hero " << std::endl;
    std::cout << "type 2 to see current hero's" << std::endl;
    std::cout << "type 3 to load a hero" << std::endl;
    std::cout << "type 4 to delete a hero" << std::endl << std::endl;
    std::cout << "Enter your choice: "; 

    a = getNumericInput();   

    switch(a){
        case 1:  
            createHero();
            break; 
        case 2: 
            ShowHeroes();
            break;
        case 3: 
            loadHero(spell);
            break;
        case 4:
            deleteHero();
            break; 
        default:
            std::cout << "Invalid input, please try again" << std::endl;
            system("clear");
            selector();
    }

}