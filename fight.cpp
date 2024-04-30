#include <limits>
#include "fight.h"
#include "enemy.h"
#include "hero.h"
#include "menu.h"
#include "game.h"
#include "Tool.h"
#include "Cave.h"

void fight(Hero& god, Enemy& enemy) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (god.getCurrentHP() > 0 && enemy.getHealth() > 0) {
        std::cout << "Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Display current health
        std::cout << god.getName() << " HP: " << god.getCurrentHP() << " | " 
                  << enemy.getName() << " HP: " << enemy.getHealth() << std::endl;

        // Player chooses attack type
        std::cout << "Choose your action:\n1. Regular Attack\n2. Cast Spell\nEnter choice (1-2): ";
        int choice;
        choice = getNumericInput();

        int damage = 0;
        if (choice == 1) {
            // Regular attack
            damage = god.getStrength();
            std::cout << god.getName() << " attacks " << enemy.getName() << " for " << damage << " damage." << std::endl;
            enemy.takeDamage(damage);
        } else if (choice == 2) {
            // Cast spell
            if (!god.getSpells().empty()) {
                std::cout << "Select a spell to cast:" << std::endl;
                for (int i = 0; i < god.getSpells().size(); ++i) {
                    std::cout << i + 1 << ". " << god.getSpells()[i]->getName() 
                              << " (Damage: " << god.getSpells()[i]->getDamage() << ")" << std::endl;
                }
                int spellIndex;
                std::cin >> spellIndex;
                spellIndex--;  
                if (spellIndex >= 0 && spellIndex < god.getSpells().size()) {
                    auto& spell = god.getSpells()[spellIndex];
                    damage = spell->getDamage();
                    std::cout << god.getName() << " casts " << spell->getName() 
                              << ", dealing " << damage << " damage." << std::endl;
                    enemy.takeDamage(damage);
                } else {
                    std::cout << "Invalid spell selection." << std::endl;
                    continue;  // Skip enemy turn if input is invalid
                }
            } else {
                std::cout << "No spells available to cast!" << std::endl;
                continue;  // Skip enemy turn if no spells are available
            }
        } else {
            std::cout << "Invalid choice. Please choose a valid action." << std::endl;
            continue;  // Skip enemy turn if input is invalid
        }

        // Check enemy status
        if (enemy.getHealth() <= 0) {
            std::cout << enemy.getName() << " has been defeated!" << std::endl;
            std::cout << god.getName() << " wins with " << god.getCurrentHP() << " HP remaining." << std::endl;
            god.XPreward(enemy.getXP());
            std::cout << "XP rewarded: " << enemy.getXP() << std::endl;
            god.levelup();

            if (enemy.getName() == "Jungle Dragon") {
                victory();  
            }

            enemy.HealthReset();
            god.resetHealth();
            break;
        }

        //Enemy turn
        damage = enemy.getStrength(); 
        std::cout << enemy.getName() << " attacks " << god.getName() << " for " << damage << " damage." << std::endl;
        god.takeDamage(damage);

        if (god.getCurrentHP() <= 0) {
            std::cout << god.getName() << " has been defeated!" << std::endl;
            std::cout << enemy.getName() << " wins with " << enemy.getHealth() << " HP remaining." << std::endl;
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
    std::cout << "Pick an Enemy to battle by their ID: ";
    choice = getNumericInput();
    std::cout << std::endl;

    if (choice > 0 && choice <= enemies.size()) {
        Enemy& opp = enemies[choice -1];  // Use a reference here
        std::cout << "You are fighting " << opp.getName() << std::endl; 
        fight(god, opp);
    } else {
        std::cout << "Invalid choice, try again" << std::endl;
    }
}


