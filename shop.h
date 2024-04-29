#ifndef SHOP_H
#define SHOP_H



#include "hero.h"
#include "spell.h"
#include <memory>
#include <vector> 

class Shop{
    public:
        Shop(const std::vector<std::shared_ptr<Spell>>& spellsAvailable);

        void displayAndBuySpells(Hero& god);

    private: 
        std::vector<std::shared_ptr<Spell>> spells; 

};

#endif //SHOP_H