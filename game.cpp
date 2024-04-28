#include <iostream> 

#include "hero.h"
#include "menu.h"
#include "database.h"
#include "Tool.h"
#include "game.h"
#include "enemy.h"
#include "fight.h"




void start_game(Hero &god, std::vector<Enemy> &enemies) {
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
                printEnemies();
                battleEnemy(enemies);
                break;
            case 3:
                saveCharacter(god);
                break;
            case 4:
                gameRunning = false; 
                break;
            default:
                std::cout << "Invalid input try again" << std::endl;
                break;
        }
    }
}


void victory(){

    std::cout << "You have defeated the dragon congrats " << std::endl; 
    exit(0);
}