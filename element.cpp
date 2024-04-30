#include "element.h"

float ElementLogic::getDamageMultiplier(Element attacker, Element defender) {
    

    //Fire Attack and defend
    if (attacker == Element::Fire && defender == Element::Metal) {
        return 2.0f;
    }

    if (attacker == Element::Fire && defender == Element::Earth) {
        return 2.0f;
    }

    if (attacker == Element::Metal && defender == Element::Fire) {
        return 0.5f;
    }

    if (attacker == Element::Earth && defender == Element::Fire) {
        return 0.5f;
    }


    //Earth Attack and defend
    if (attacker == Element::Earth && defender == Element::Water) {
        return 2.0f;
    }

    if (attacker == Element::Earth && defender == Element::Metal) {
        return 2.0f;
    }

    if (attacker == Element::Water && defender == Element::Earth) {
        return 0.5f;
    }

    if (attacker == Element::Metal && defender == Element::Earth) {
        return 0.5f;
    }


    //Metal Attack and defend
    if (attacker == Element::Metal && defender == Element::Wood) {
        return 2.0f;
    }

    if (attacker == Element::Metal && defender == Element::Water) {
        return 2.0f;
    }

    if (attacker == Element::Wood && defender == Element::Metal) {
        return 0.5f;
    }

    if (attacker == Element::Water && defender == Element::Metal) {
        return 0.5f;
    }


    //Water Attack and defend
    if (attacker == Element::Water && defender == Element::Wood) {
        return 2.0f;
    }

    if (attacker == Element::Water && defender == Element::Fire) {
        return 2.0f;
    }

    if (attacker == Element::Wood && defender == Element::Water) {
        return 0.5f;
    }

    if (attacker == Element::Fire && defender == Element::Water) {
        return 0.5f;
    }


    //Wood Attack and defend
    if (attacker == Element::Wood && defender == Element::Earth) {
        return 2.0f;
    }

    if (attacker == Element::Wood && defender == Element::Fire) {
        return 2.0f;
    }

    if (attacker == Element::Earth && defender == Element::Wood) {
        return 0.5f;
    }

    if (attacker == Element::Fire && defender == Element::Wood) {
        return 0.5f;
    }




    return 1.0f;
}

Element stringToElement(const std::string& element) {
    if (element == "Fire") {return Element::Fire;}
    if (element == "Water") {return Element::Water;}
    if (element == "Wood") {return Element::Wood; }
    if (element == "Earth") {return Element::Earth;}
    if (element == "Metal") {return Element::Metal;}
    throw std::invalid_argument("Unknown element: " + element);
}

std::string elementToString(Element element) {
    switch (element) {
        case Element::Fire:  return "Fire";
        case Element::Water: return "Water";
        case Element::Earth: return "Earth";
        case Element::Metal: return "Metal";
        case Element::Wood:  return "Wood";
        default: throw std::invalid_argument("Unknown Element");
    }
}
