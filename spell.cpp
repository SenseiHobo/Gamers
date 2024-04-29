
#include "spell.h"

Spell::Spell(int id, std::string name, int damage, Element element, int gold_price, std::shared_ptr<Spell> require) : spell_id(id), _name(name), _damage(damage), _element(element), _gold_price(gold_price), _require(require) {}


int Spell::getID() const{
    return spell_id;
}

std::string Spell::getName() const{
    return _name;
}

int Spell::getDamage() const{
    return _damage;
}

Element Spell::getElement() const{
    return _element;
}

int Spell::getGoldPrice() const{
    return _gold_price;
}

std::shared_ptr<Spell> Spell::getRequired() const { 
    return _require; 
}


std::vector<std::shared_ptr<Spell>> createSpells() {
    std::vector<std::shared_ptr<Spell>> spellList; 

    //Basic spells - no requirement
    spellList.push_back(std::make_shared<Spell>(1, "Flame Burst", 15, stringToElement("Fire"), 500, nullptr));
    spellList.push_back(std::make_shared<Spell>(2, "Aqua Shot", 15, stringToElement("Water"), 500, nullptr));
    spellList.push_back(std::make_shared<Spell>(3, "Bark Spear", 15, stringToElement("Wood"), 500, nullptr));
    spellList.push_back(std::make_shared<Spell>(4, "Stone fist", 15, stringToElement("Earth"), 500, nullptr));
    spellList.push_back(std::make_shared<Spell>(5, "Metal shard", 15, stringToElement("Metal"), 500, nullptr));


     //Intermediate spells - have requirements 
    auto flameburst = spellList[0];
    auto aquaShot = spellList[1];
    auto barkSpear = spellList[2];
    auto stoneFist = spellList[3];
    auto metalShard = spellList[4];

    spellList.push_back(std::make_shared<Spell>(6, "Inferono Swipe", 30, stringToElement("Fire"), 750, flameburst));
    spellList.push_back(std::make_shared<Spell>(7, "Tidal Wave", 30, stringToElement("Water"), 750, aquaShot));
    spellList.push_back(std::make_shared<Spell>(8, "Vine Grasp", 30, stringToElement("Wood"), 750, barkSpear));
    spellList.push_back(std::make_shared<Spell>(9, "Earthquake", 30, stringToElement("Earth"), 750, stoneFist));
    spellList.push_back(std::make_shared<Spell>(10, "Iron Maiden", 30, stringToElement("Metal"), 750, metalShard));


    //Advanced spells - have Intermediate requirements
    auto infernoSwipe = spellList[5];
    auto tidalWave = spellList[6];
    auto vineGrasp = spellList[7];
    auto earthquake = spellList[8];
    auto ironMaiden = spellList[9];

    spellList.push_back(std::make_shared<Spell>(11, "Dragon's Breath", 50, stringToElement("Fire"), 1250, infernoSwipe));
    spellList.push_back(std::make_shared<Spell>(12, "Monsoon", 50, stringToElement("Water"), 1250, tidalWave));
    spellList.push_back(std::make_shared<Spell>(13, "Entangle", 50, stringToElement("Wood"), 1250, vineGrasp));
    spellList.push_back(std::make_shared<Spell>(14, "LandSlide", 50, stringToElement("Earth"), 1250, earthquake));
    spellList.push_back(std::make_shared<Spell>(15, "Steel Storm", 50, stringToElement("Metal"), 1250, ironMaiden));

    
    //God Spells - have Advanced requirements 
    auto dragonBreath = spellList[10];
    auto monsoon = spellList[11];
    auto entangle = spellList[12];
    auto landslide = spellList[13];
    auto steelStorm = spellList[14];

    spellList.push_back(std::make_shared<Spell>(16, "Helios' Inferno", 70, stringToElement("Fire"), 1500, dragonBreath));
    spellList.push_back(std::make_shared<Spell>(17, "Poseidon's Tsunami", 70, stringToElement("Water"), 1500, monsoon));
    spellList.push_back(std::make_shared<Spell>(18, "Dionysus' vine", 70, stringToElement("Wood"), 1500, entangle));
    spellList.push_back(std::make_shared<Spell>(19, "Gaia's Tremor", 70, stringToElement("Earth"), 1500, landslide));
    spellList.push_back(std::make_shared<Spell>(20, "Hephaestus' Forge", 70, stringToElement("Metal"), 1500, steelStorm));


    return spellList;
}