#include "shop.h"
#include "Tool.h"
#include <iostream> 
#include <sstream>
#include "element.h"

Shop::Shop(const std::vector<std::shared_ptr<Spell>>& spellsAvailable) : spells(spellsAvailable) {}


void Shop::displayAndBuySpells(Hero& god){
    system("clear");
    slow_print("Here are the spells we sell: ");
    delay();
    std::cout << std::endl;

    int index = 1;
    
    std::cout << "_____________________________________________________________________________________________________________________" << std::endl;
    for(const auto& spell : spells) {
        std::string requiredSpell = spell->getRequired() ?  spell -> getRequired()->getName() : "None";
        std::cout << index++ << ". " << spell->getName() << " - Damage: " << spell-> getDamage() << "- Element: " << elementToString(spell-> getElement()) <<  " - Mana: " << spell->getManaCost() <<" - Cost: " << spell->getGoldPrice() << " Gold" << "- requirements: " << requiredSpell << std::endl << std::endl; 
        std::cout << "_____________________________________________________________________________________________________________________" << std::endl;
    }


    std::cout << "Enter the number of the spell you wish to purchase or 0 to exit: ";
    int choice;
    choice = getNumericInput();
    if(choice > 0 && choice <= spells.size()){
        auto selectedSpell = spells[choice - 1];
        if(god.getGold() >= selectedSpell->getGoldPrice()) {
            if(god.hasSpell(selectedSpell->getID())){
                std::ostringstream message;
                message << "You already own this spell." << std::endl;
                slow_print(message.str());
                delay();
                displayAndBuySpells(god);
            } else {

                if(selectedSpell->getRequired() == nullptr || god.hasSpell(selectedSpell->getRequired()->getID())){
                    god.addGold(-selectedSpell->getGoldPrice());
                    god.learnSpell(selectedSpell);
                    std::ostringstream message;
                    message << "You have successfully purchased " << selectedSpell->getName() << "!" << std::endl;  
                    slow_print(message.str());
                    delay();
                    displayAndBuySpells(god);
                } else {
                    std::cout << "You need to learn " << selectedSpell->getRequired()->getName() << " first. " << std::endl;
                }
            }
        } else {
            std::cout << "You do no have enough gold." << std::endl;
        }
    } else if(choice == 0){
        system("clear");
        slow_print("Come back another time!");
        std::cout << std::endl << std::endl;
    } else{
        std::cout << "Invalid Selection.";
    }

}