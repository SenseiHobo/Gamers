#ifndef ELEMENT_H
#define ELEMENT_H


#include <string> 
#include <stdexcept> 

enum class Element{
    Fire, Water, Earth, Metal, Wood

};




float getDamageMultiplier(Element attacker, Element defender);

Element stringToElement(const std::string& element);


std::string elementToString(Element element);



#endif // ELEMENT_H
