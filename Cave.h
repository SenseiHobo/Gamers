#ifndef CAVE_H
#define CAVE_H

#include "enemy.h"

#include <iostream> 
#include <string> 

class Cave{
    public:
        Cave();
        Cave(int id, std::string name, int gold);
        void addEnemy(Enemy &Enemy);
        void printCaves();
        int getid() const;
        std::string getName() const;
        int getGold() const;
        //void printCaveEnemies(); 


    private:
        int _id;
        std::string _name;
        int _gold; 
        std::vector<Enemy> Cave_Enemy; 
}; 




std::vector<Cave> setupCaves();


#endif //CAVE_H