#ifndef SPELL_H
#define SPELL_H

#include <string> 
#include <iostream>
#include <vector> 
#include <memory> 
#include "element.h"



class Spell{

    public:
        Spell(int id, std::string name, int damage, Element element, int gold_price, std::shared_ptr<Spell> require = nullptr); 


        int getID() const;
        int getDamage() const;
        Element getElement() const;
        int getGoldPrice() const;
        std::shared_ptr<Spell> getRequired() const;
        std::string getName() const;

    private:
        int spell_id;
        std::string _name;
        int _damage;
        Element _element;
        int _gold_price;
        std::shared_ptr<Spell> _require; 

};


std::vector<std::shared_ptr<Spell>> createSpells(); 


#endif //SPELL_H