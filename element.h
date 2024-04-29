#ifndef ELEMENT_H
#define ELEMENT_H


#include <string> 
#include <stdexcept> 

enum class Element{
    Fire, Water, Earth, Metal, Wood

};


class ElementLogic {
public:
    static float getDamageMultiplier(Element attacker, Element defender);
};

Element stringToElement(const std::string& element);

#endif // ELEMENT_H
