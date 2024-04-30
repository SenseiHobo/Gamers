
#include "spell.h"

Spell::Spell(int id, std::string name, int damage, Element element, int gold_price, std::shared_ptr<Spell> require, int mana) : spell_id(id), _name(name), _damage(damage), _element(element), _gold_price(gold_price), _require(require), _mana_cost(mana) {}


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

int Spell::getManaCost() const{
    return _mana_cost;
}

std::shared_ptr<Spell> Spell::getRequired() const { 
    return _require; 
}

