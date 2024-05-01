#include <iostream> 

#include "enemy.h"
#include "database.h"
#include "element.h"


Enemy::Enemy(int id, std::string name, int health, int strength, int xp, Element element) : _id(id) ,_name(name), _health(health), _strength(strength), _xp(xp), _currentHP(_health), _element(element) {}


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

Element Enemy::getElement() const{
    return _element;
}


std::vector<Enemy> setupEnemies(){
    
    std::vector<Enemy> enemies;

    Enemy e1(1, "slime", 4, 1, 100, stringToElement("Water"));
    enemies.push_back(e1);
    
    Enemy e2(2, "zombie", 6, 2, 200, stringToElement("Metal"));
    enemies.push_back(e2);

    Enemy e3(3, "Blood Crawler", 8, 3, 400, stringToElement("Wood"));
    enemies.push_back(e3);

    Enemy e4(4, "Harpy", 15, 4, 500, stringToElement("Metal"));
    enemies.push_back(e4);

    Enemy e5(5, "Corruptor", 20, 5, 800, stringToElement("Earth"));
    enemies.push_back(e5);

    Enemy e6(6, "Golem", 30, 5, 1000, stringToElement("Earth"));
    enemies.push_back(e6);

    Enemy e7(7, "Unicorn", 30, 8, 1500, stringToElement("Wood"));
    enemies.push_back(e7);

    Enemy e8(8, "Jungle Dragon", 150, 15, 3000, stringToElement("Fire"));
    enemies.push_back(e8);

    return enemies;
}



void printEnemies(){
    system("clear");
    std::vector<Enemy> enemies = setupEnemies();
    
    for (const Enemy& enemy : enemies) {
        std::cout<< "Id: " << enemy.getID() << ", Name: " << enemy.getName() << ", Health: " << enemy.getHealth()
                << ", Strength: " << enemy.getStrength() << ", Element: " <<  elementToString(enemy.getElement()) <<", XP: " << enemy.getXP() << std::endl;
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


