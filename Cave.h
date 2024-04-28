#ifndef CAVE_H
#define CAVE_H

#include "enemy.h"


#include <iostream> 
#include <string> 


class Cave{
    public:
        Cave();
        Cave(int id, std::string name, int gold, bool cleared);
        void addEnemy(Enemy &Enemy);
        void printCaves();
        int getid() const;
        std::string getName() const;
        int getGold() const;
        bool isCleared();
        void markCleared();
        const std::vector<Enemy> & getEnemies() const;
        //void printCaveEnemies(); 


    private:
        int _id;
        std::string _name;
        int _gold; 
        bool _cleared;
        std::vector<Enemy> Cave_Enemy; 

}; 


std::vector<Cave> setupCaves();

void cave_select();

#endif //CAVE_H