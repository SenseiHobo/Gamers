#ifndef FIGHT_H
#define FIGHT_H

#include "hero.h"
#include "enemy.h"
#include "Cave.h" 


class fighter{
    public: 
        void fight(Hero& hero, Enemy& enemy);
        void battleEnemy(std::vector<Enemy>& enemies);
        void Cavefight(Hero& god, const Cave& caveEnemies);

};


extern fighter F1;

#endif 
