#include <iostream> 
#include <string> 
#include "hero.h"


Hero::Hero() : _name("Unknown"), _xp(0), _level(1), _maxHP(10), _currentHP(_maxHP), _damage(_strength), _strength(2){}
Hero::Hero(std::string name, int level, int xp, int maxHP, int strength) : _name(name), _level(level), _xp(xp), _maxHP(maxHP), _currentHP(_maxHP), _damage(_strength), _strength(strength){}


int Hero::getDamage(){
    return  _strength; 
}

int Hero::getlevel(){
    return _level;
}

int Hero::getXP(){
    return _xp;
}

int Hero::getStrength(){
    return _strength;
}

int Hero::getMaxHP(){
    return _maxHP;
}


std::string Hero::getName(){
    return _name;
}

int Hero::getCurrentHP(){
    return _currentHP;
}

void Hero::resetHealth(){
    _currentHP = _maxHP; 
}

int Hero::XPreward(int XP){
    std::cout << "Current XP: " << _xp << ", Adding XP: " << XP << std::endl;
    _xp += XP;
    std::cout << "New XP: " << _xp << std::endl;
    return _xp;
}

void Hero::levelup(){
    
    while(_xp >= 1000){
        _xp -= 1000;
        _level += 1;
        _strength += 1; 
        _maxHP += 2; 
        std::cout << " You have leveled up " << std::endl;
        std::cout << " You are now level: " << _level << std::endl;    
    }

}


void Hero::takeDamage(int damage){
    _currentHP -= damage;
}