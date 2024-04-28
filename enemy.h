#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <string>
#include <vector>


class Enemy {
public:
    Enemy(int id, std::string name, int health, int strength, int xp);
    std::string getName() const;
    int getHealth() const;
    int getStrength() const;
    int getXP() const;
    int getID() const;
    void takeDamage(int damage);
    void HealthReset();

private:
    std::string _name;
    int _health;
    int _currentHP;
    int _strength;
    int _xp;
    int _id;
};

std::vector<Enemy> setupEnemies();

void printEnemies();

#endif // ENEMY_H