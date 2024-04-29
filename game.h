#ifndef GAME_H
#define GAME_H 
#include "menu.h"
#include "database.h"
#include "hero.h"
#include "enemy.h"
#include "Cave.h"
#include "shop.h"

void start_game(Hero &god, std::vector<Enemy> &enemies);

void victory();



void printCaves();
void displayAndBuySpells(Hero& god);

#endif //GAME_H
