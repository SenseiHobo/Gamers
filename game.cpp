#include <iostream> 
#include <sstream>
#include "hero.h"
#include "menu.h"
#include "database.h"
#include "Tool.h"
#include "game.h"
#include "enemy.h"
#include "fight.h"
#include "game.h"
#include "Cave.h"
#include "shop.h"



void start_game(Hero &god, std::vector<Enemy> &enemies) {

    std::vector<std::shared_ptr<Spell>> availableSpells = createSpells();
    Shop spellShop(availableSpells);

    int choice = 0;
    bool gameRunning = true;
        slow_print("The game has now begun and you are playing as ");
        std::cout << god.getName() << std::endl << std::endl;
    while (gameRunning) {
        std::cout << "____________________" << std::endl;
        std::cout << "1. Checkout stats " << std::endl;
        std::cout << "____________________" << std::endl;
        std::cout << "2. Fight an enemy " << std::endl;
        std::cout << "____________________" << std::endl;
        std::cout << "3. Enter a cave" << std::endl; 
        std::cout << "____________________" << std::endl;
        std::cout << "4. Buy spells" << std::endl;
        std::cout << "____________________" << std::endl;
        std::cout << "5. Take a nap" << std::endl;
        std::cout << "____________________" << std::endl;
        std::cout << "6. Save your character  " << std::endl;
        std::cout << "____________________" << std::endl;
        std::cout << "7. Exit game " << std::endl;
        std::cout << "____________________" << std::endl << std::endl; 
        std::cout << "Enter your choice: ";
        choice = getNumericInput();
        std::cout << std::endl;

        switch (choice) {
            case 1:
                god.showStats();
                break;
            case 2:
                printEnemies();
                battleEnemy(enemies);
                break;
            case 3:
                printCaves();
                cave_select();
                break;
            case 4:
                slow_print("Welcome to the Spell Shop!");
                delay();
                spellShop.displayAndBuySpells(god);
                break;
            case 5: 
                slow_print("You took a nap and feel energized");
                god.resetHealth();
                god.resetMana();
                break;
            case 6: 
                saveCharacter(god);
                break;
            case 7:
                system("clear");
                gameRunning = false; 
                break;
            
            default:
                std::cout << "Invalid input try again" << std::endl;
                break;
        }
    }
}


void victory(){

    std::ostringstream message;
    message << "You have defeated the dragon congrats " << std::endl; 
    slow_print(message.str());
    Windelay();
    saveCharacter(god);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press Enter when you are ready for the game to shut down" << std::endl;
    exit(0);
}