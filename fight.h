#ifndef FIGHT_H
#define FIGHT_H

#include "hero.h"
#include "enemy.h"


void fight(Hero& hero, Enemy& enemy);

void battleEnemy(std::vector<Enemy>& enemies);

void Cavefigth(Hero& god, std::vector<Enemy> & caveEnemies);

#endif 