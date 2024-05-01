#include <iostream> 
#include <string> 
#include <sstream>
#include "hero.h"
#include "Tool.h"


Hero::Hero() : _name("Unknown"), _xp(0), _level(1), _maxHP(10), _currentHP(_maxHP), _damage(_strength), _strength(2), _gold(0), _mana(10), _currentMana(_mana)  {}
Hero::Hero(std::string name, int level, int xp, int maxHP, int strength, int gold, int mana) : _name(name), _level(level), _xp(xp), _maxHP(maxHP), _currentHP(_maxHP), _damage(_strength), _strength(strength), _gold(gold), _mana(mana), _currentMana(_mana) {}


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

void Hero::addGold(int money){
    _gold += money;
}

int Hero::getGold(){
    return _gold;
}

int Hero::getMana(){
    return _mana;
}

int Hero::useMana(int mana){
    return _currentMana -= mana;
}

int Hero::getCurrentMana(){
    return _currentMana;
}

int Hero::resetMana(){
    return _currentMana = _mana;
}
void Hero::resetHealth(){
    _currentHP = _maxHP; 
}

int Hero::XPreward(int XP){
    _xp += XP;
    return _xp;
}

void Hero::levelup(){
    
    while(_xp >= 1000){
        _xp -= 1000;
        _level += 1;
        _strength += 1; 
        _maxHP += 3; 
        _currentHP += 3;
        _mana += 2;
        _currentMana += 2;
        std::cout << " You have leveled up " << std::endl;
        std::cout << " You are now level: " << _level << std::endl;    
    }

}

void Hero::takeDamage(int damage){
    _currentHP -= damage;
}


void Hero::learnSpell(std::shared_ptr<Spell> spell){
    spells.push_back(spell);
}

bool Hero::hasSpell(int spellId) const{
    for(const auto& spell : spells){
        if(spell->getID() == spellId){
            return true;
        }
    }
    return false; 
}

const std::vector<std::shared_ptr<Spell>>& Hero::getSpells() const {
        return spells;
    }


void Hero::showStats(){
    system("clear");
    std::ostringstream message;
    message << god.getName() << " - " << "Level: "
     << god.getlevel() << "   XP: " << god.getXP() << "     Current Health "
    << god.getCurrentHP() << "/" << god.getMaxHP() << "     Mana: " << god.getCurrentMana() << "/"<<god.getMana()  << "     Damage: " 
    <<  god.getDamage() << "      Gold: "  << god.getGold() <<  std::endl << std::endl;

    slow_print(message.str());
    delay();
}

Hero god; 