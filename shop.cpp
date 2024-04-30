#include "shop.h"
#include "Tool.h"
#include <iostream> 
#include "element.h"

Shop::Shop(const std::vector<std::shared_ptr<Spell>>& spellsAvailable) : spells(spellsAvailable) {}


void Shop::displayAndBuySpells(Hero& god){
    std::cout << "Welcome to the Spell Shop!" << std::endl;
    std::cout << "Here are the spells you can buy: " << std::endl;

    int index = 1;
    
    for(const auto& spell : spells) {
        std::string requiredSpell = spell->getRequired() ?  spell -> getRequired()->getName() : "None";
        std::cout << index++ << ". " << spell->getName() << " - Damage: " << spell-> getDamage() << "- Element: " << elementToString(spell-> getElement()) <<  " - Cost: " << spell->getGoldPrice() << " Gold" << "- requirements: " << requiredSpell << std::endl << std::endl; 
    }


    std::cout << "Enter the number of the spell you wish to purchase or 0 to exit: ";
    int choice;
    choice = getNumericInput();
    if(choice > 0 && choice <= spells.size()){
        auto selectedSpell = spells[choice - 1];
        if(god.getGold() >= selectedSpell->getGoldPrice()) {
            if(god.hasSpell(selectedSpell->getID())){
                std::cout << "You already own this spell." << std::endl;
            } else {

                if(selectedSpell->getRequired() == nullptr || god.hasSpell(selectedSpell->getRequired()->getID())){
                    god.addGold(-selectedSpell->getGoldPrice());
                    god.learnSpell(selectedSpell);
                    std::cout << "You have successfully purchased " << selectedSpell->getName() << "!" << std::endl;  
                } else {
                    std::cout << "You need to learn " << selectedSpell->getRequired()->getName() << " first. " << std::endl;
                }
            }
        } else {
            std::cout << "You do no have enough gold." << std::endl;
        }
    } else if(choice != 0){
        std::cout << "Invalid Selection.";
    }

}