#include "Cave.h"


Cave::Cave() {}

Cave::Cave(int id, std::string name, int gold) : _id(id), _name(name), _gold(gold) {}

int Cave::getid() const{
    return _id;
}

int Cave::getGold() const{
    return _gold;
}

std::string Cave::getName() const{
    return _name;
}


void Cave::addEnemy(Enemy &Enemy){
    Cave_Enemy.push_back(Enemy);
}

void printCaves(){

    std::vector<Cave> Caves = setupCaves();

    for(const Cave &Cave : Caves){
        std::cout << "Id: " << Cave.getid() << ", Name: " << Cave.getName() << ", Gold: " << Cave.getGold() << std::endl;
    }

    std::cout << std::endl << std::endl;


}


std::vector<Cave> setupCaves(){

    std::vector<Cave> caves; 

    Cave C1(1, " Slime grotto ", 100);
    caves.push_back(C1);

    Cave C2(2, " The forgotten cave ", 200 );
    caves.push_back(C2);

    Cave C3(3, " Unicorn cave ", 1000);
    caves.push_back(C3);

    return caves; 
}