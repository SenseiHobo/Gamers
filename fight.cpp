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

        // Hero attacks enemy
        int damage = god.getStrength();
        std::cout << god.getName() << " attacks " << enemy.getName() << " for " << damage << " damage." << std::endl;
        enemy.takeDamage(damage);

        if (enemy.getHealth() <= 0) {
            std::cout << enemy.getName() << " has been defeated!" << std::endl;
            std::cout << god.getName() << " wins with " << god.getCurrentHP() << " HP remaining." << std::endl;
            std::cout << god.getName() << " XP rewarded: " << enemy.getXP() << std::endl;
            std::cout << "current xp before reward: " << god.getXP() << std::endl;
            god.XPreward(enemy.getXP());
            god.levelup();

            if(enemy.getName() == "Jungle Dragon"){
                victory();
            }

            enemy.HealthReset();
            god.resetHealth();
            std::cout << std::endl;


            break;
        } else {
            std::cout << enemy.getName() << " has " << enemy.getHealth() << " HP remaining." << std::endl;
        }

        // Enemy attacks hero
        damage = enemy.getStrength(); 
        std::cout << enemy.getName() << " attacks " << god.getName() << " for " << damage << " damage." << std::endl;
        god.takeDamage(damage);

        if (god.getCurrentHP() <= 0) {
            std::cout << god.getName() << " has been defeated!" << std::endl;
            std::cout << enemy.getName() << " wins with " << enemy.getHealth() << " HP remaining." << std::endl;
            enemy.HealthReset();
            std::cout << std::endl;
            selector();
            break;
        } else {
            std::cout << god.getName() << " has " << god.getCurrentHP() << " HP remaining." << std::endl;
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


