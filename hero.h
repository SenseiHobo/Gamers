#ifndef HERO_H
#define HERO_H

#include <iostream> 
#include <string> 
#include <vector>
#include <memory> 
#include "spell.h"


class Hero{

    public:
        Hero();
        Hero(std::string name, int xp, int level, int maxHP, int strength, int gold, int mana);
        
        std::string getName();

        //Damage;
        int getStrength();
        int getDamage();



        //Awarded xp and current
        int getXP();
        int XPreward(int XP);

        //Max health and current
        int getMaxHP();
        int getCurrentHP();

        //Damage taken & Reset
        void takeDamage(int damage);
        void resetHealth();

        //Level 
        int getlevel();
        void levelup();

        //Money
        void addGold(int money);
        int getGold();

        //Spells;

        int getMana();
        int resetMana();
        int useMana(int mana);
        int getCurrentMana();

        void learnSpell(std::shared_ptr<Spell> spell);
        bool hasSpell(int spellId) const;
        const std::vector<std::shared_ptr<Spell>>& getSpells() const;

    private: 
        std::string _name;
        int _xp;
        int _level;
        int _maxHP;
        int _currentHP;
        int _damage;
        int _strength; 
        int _gold;
        int _mana;
        int _currentMana;
        std::vector<std::shared_ptr<Spell>> spells;



};

extern Hero god; 

#endif //HERO_H