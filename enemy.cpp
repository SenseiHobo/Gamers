#include <iostream> 

#include "enemy.h"
#include "database.h"


Enemy::Enemy(int id, std::string name, int health, int strength, int xp) : _id(id) ,_name(name), _health(health), _strength(strength), _xp(xp), _currentHP(_health) {}


std::string Enemy::getName() const{
    return _name;
}

int Enemy::getHealth() const{
    return _currentHP;
}

int Enemy::getStrength() const{
    return _strength;
}

int Enemy::getXP() const{
    return _xp;
}

int Enemy::getID() const{
    return _id;
}


std::vector<Enemy> setupEnemies(){
    
    std::vector<Enemy> enemies;

    Enemy e1(1, "slime", 4, 1, 100);
    enemies.push_back(e1);
    
    Enemy e2(2, "zombie", 4, 2, 200);
    enemies.push_back(e2);

    Enemy e3(3, "Blood Crawl", 8, 3, 400);
    enemies.push_back(e3);

    Enemy e4(4, "Harpy", 10, 4, 500);
    enemies.push_back(e4);

    Enemy e5(5, "Corruptor", 15, 5, 800);
    enemies.push_back(e5);

    Enemy e6(6, "Golem", 30, 5, 1000);
    enemies.push_back(e6);

    Enemy e7(7, "Unicorn", 5, 8, 1500);
    enemies.push_back(e7);

    Enemy e8(8, "Jungle Dragon", 100, 10, 3000);
    enemies.push_back(e8);

    return enemies;
}



void printEnemies(){
    
    std::vector<Enemy> enemies = setupEnemies();
    
    for (const Enemy& enemy : enemies) {
        std::cout<< "Id: " << enemy.getID() << ", Name: " << enemy.getName() << ", Health: " << enemy.getHealth()
                << ", Strength: " << enemy.getStrength() << ", XP: " << enemy.getXP() << std::endl;
    }
    std::cout << std::endl << std::endl; 

}

void Enemy::takeDamage(int damage) {
    _currentHP -= damage;
    if (_currentHP < 0) {
        _currentHP = 0; // Ensure health does not go below zero.
    }
}

void Enemy::HealthReset(){

    _currentHP += _health; 
}


