#include <iostream> 

#include "menu.h"
#include "database.h"

int getNumericInput();

void start(){
    int a = 0;
    std::cout << "Welcome to Hobo Adventure " << std::endl;
    std::cout << "Press 1 to continue: ";
    a = getNumericInput();
    std::cout << std::endl<<std::endl;

    if(a == 1){
        selector();
    } else {
        start();
    }

}   




void selector(){
    int a = 0; 

    std::cout << "Select your action" << std::endl;
    std::cout << "type 1 to create a new hero " << std::endl;
    std::cout << "type 2 to see current hero's" << std::endl;
    std::cout << "type 3 to load a hero" << std::endl;
    std::cout << "type 4 to delete a hero" << std::endl;
    std::cout << "Enter your choice: "; 

    a = getNumericInput();   

    switch(a){
        case 1:
            std::cout << "You are creating a new Hero" << std::endl;   
            createHero();
            break; 
        case 2: 
            std::cout << "You are looking at current Heroes" << std::endl;
            ShowHeroes();
            break;
        case 3: 
            std::cout << "You are loading an existing hero" << std::endl;
            loadHero();
            break;
        case 4:
            std::cout << "Type the name of the hero you want to delete" << std::endl; 
            deleteHero();
            break; 
        default:
            std::cout << "Invalid input, please try again" << std::endl;
            selector();
    }

}