#include <limits>
#include <sstream>
#include "fight.h"
#include "enemy.h"
#include "hero.h"
#include "menu.h"
#include "game.h"
#include "Tool.h"
#include "Cave.h"
#include "element.h"

void fight(Hero& god, Enemy& enemy) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press Enter to continue..." << std::endl;
    while (god.getCurrentHP() > 0 && enemy.getHealth() > 0) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Display current health
        std::cout << god.getName() << " HP: " << god.getCurrentHP() << "    Mana: " << god.getCurrentMana() << " | " 
                  << enemy.getName() << " HP: " << enemy.getHealth() << std::endl << std::endl;

        // Player chooses attack type
        std::cout << "Choose your action:\n1. Regular Attack\n2. Cast Spell\nEnter choice (1-2): ";
        int choice;
        choice = getNumericInput();

    

        int damage = 0;
        if (choice == 1) {
            system("clear");
            // Regular attack
            damage = god.getStrength();
            std::ostringstream message;
            message << god.getName() << " attacks " << enemy.getName() << " for " << damage << " damage." << std::endl;
            slow_print(message.str());
            
            enemy.takeDamage(damage);
        } else if (choice == 2) {
            system("clear");
            // Cast spell


            if (!god.getSpells().empty()) {
                std::cout << "Select a spell to cast:" << std::endl;
                for (int i = 0; i < god.getSpells().size(); ++i) {
                    std::cout << i + 1 << ". " << god.getSpells()[i]->getName() 
                              << " (Damage: " << god.getSpells()[i]->getDamage() 
                              << ", Mana Cost: " << god.getSpells()[i] -> getManaCost() << ")" <<std::endl;
                }
                int spellIndex;
                std::cin >> spellIndex;
                spellIndex--;  
                if (spellIndex >= 0 && spellIndex < god.getSpells().size()) {
                    auto& spell = god.getSpells()[spellIndex];
                    if(god.getCurrentMana() >= spell->getManaCost()){
                        god.useMana(spell->getManaCost());
                        float mult = getDamageMultiplier(spell->getElement(), enemy.getElement());
                        damage = spell->getDamage() * mult;
                        std::ostringstream message;
                        message << god.getName() << " casts " << spell->getName() 
                                << ", dealing " << damage << " damage." << std::endl;
                        slow_print(message.str());
                        enemy.takeDamage(damage);
                    } else {
                        std::cout << "Not enough mana to cast " << spell->getName() << "." << std::endl;
                        continue; 
                    }
                } else {
                    std::cout << "Invalid spell selection." << std::endl;
                    continue;  // Skip enemy turn if input is invalid
                }
            } else {
                std::ostringstream message;
                message << "No spells available to cast!" << std::endl << std::endl;
                slow_print(message.str());
                continue;  // Skip enemy turn if no spells are available
            }
        } else {
            std::cout << "Invalid choice. Please choose a valid action." << std::endl;
            continue;  // Skip enemy turn if input is invalid
        }

        // Check enemy status
        if (enemy.getHealth() <= 0) {
            std::ostringstream message;
            message << enemy.getName() << " has been defeated!" << std::endl << std::endl;
            slow_print(message.str());

            message.str("");
            message.clear();
            
            message << god.getName() << " wins with " << god.getCurrentHP() << " HP remaining." << std::endl << std::endl;
            slow_print(message.str());
            god.XPreward(enemy.getXP());
            std::cout << "XP rewarded: " << enemy.getXP() << std::endl << std::endl;
            god.levelup();

            if (enemy.getName() == "Jungle Dragon") {
                victory();  
            }

            enemy.HealthReset();
            break;
        }

        //Enemy turn
        damage = enemy.getStrength(); 
        std::ostringstream message;
        message << enemy.getName() << " attacks " << god.getName() << " for " << damage << " damage." << std::endl;
        slow_print(message.str());
        std::cout << std::endl;
        god.takeDamage(damage);

        if (god.getCurrentHP() <= 0) {
            message << god.getName() << " has been defeated!" << std::endl << std::endl;
            slow_print(message.str());
            message << enemy.getName() << " wins with " << enemy.getHealth() << " HP remaining." << std::endl << std::endl;
            slow_print(message.str());
            delay();
            system("clear");
            selector(); 
            break;
        }
    }
}



void Cavefight(Hero& god, const Cave& caveEnemies) {
    
  const std::vector<Enemy>& enemies = caveEnemies.getEnemies();


  for (const Enemy& enemy : enemies) {
    std::cout << "Entering battle with " << enemy.getName() << std::endl;

    Enemy copyOfEnemy = enemy;
    fight(god, copyOfEnemy); 

    if (god.getCurrentHP() <= 0) {
      return; 
    }

    if (enemy.getHealth() <= 0) {
      god.XPreward(enemy.getXP());
      std::cout << "Defeated " << enemy.getName() << " and gained " << enemy.getXP() << " XP!" << std::endl;
    }
  }

  if (enemies.empty()) {
    std::cout << "You have cleared all enemies in " << caveEnemies.getName() << "!" << std::endl;
  }
}




void battleEnemy(std::vector<Enemy>& enemies) {
    int choice = 0;
    std::cout << "Pick an Enemy to battle by their ID or 0 to exit: ";
    choice = getNumericInput();
    std::cout << std::endl;

    if (choice > 0 && choice <= enemies.size()) {
        Enemy& opp = enemies[choice -1];  
        slow_print("You are fighting ");
        std::cout << opp.getName() << std::endl; 
        fight(god, opp);
    } else if(choice == 0) {}
    else {
        battleEnemy(enemies);
    }
}


