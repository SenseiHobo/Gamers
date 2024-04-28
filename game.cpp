#include <iostream> 

#include "hero.h"
#include "menu.h"
#include "database.h"
#include "Tool.h"
#include "game.h"





// Modify start_game to use a loop instead of recursion
void start_game(Hero &god) {
    int choice = 0;
    bool gameRunning = true;
        std::cout << "The game has now begun and you are playing as " << god.getName() << std::endl << std::endl;
    while (gameRunning) {
        std::cout << "1. Checkout stats " << std::endl;
        std::cout << "2. Fight an enemy " << std::endl;
        std::cout << "3. Save your character " << std::endl; 
        std::cout << "4. Exit game " << std::endl;   
        std::cout << "Enter your choice: ";
        choice = getNumericInput();
        std::cout << std::endl;

        switch (choice) {
            case 1:
                std::cout << god.getName() << " - " << "Level: " << god.getlevel() << "   XP: " << god.getXP() << "     Current Health " << god.getCurrentHP() << "/" << god.getMaxHP() << "     Damage: " <<  god.getDamage() << std::endl;
                break;
            case 2:
                break;
            case 3:
                saveCharacter(god);
                break;
            case 4:
                gameRunning = false;  // Set flag to false to exit the loop
                break;
            default:
                std::cout << "Invalid input try again" << std::endl;
                break;
        }
    }
}

