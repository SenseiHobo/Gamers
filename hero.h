#ifndef HERO_H
#define HERO_H

#include <iostream> 
#include <string> 


class Hero{

    public:
        Hero();
        Hero(std::string name, int xp, int level, int maxHP, int strength, int gold);
        
        std::string getName();

        //Damage;
        int getStrength();
        int getDamage();


        //Awarded xp and current1
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

    private: 
        std::string _name;
        int _xp;
        int _level;
        int _maxHP;
        int _currentHP;
        int _damage;
        int _strength; 
        int _gold;



};

extern Hero god; 

#endif //HERO_H