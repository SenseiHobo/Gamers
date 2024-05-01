#include <sstream>
#include "fight.h"
#include "Cave.h"
#include "Tool.h"
#include "enemy.h"


Cave::Cave() {}

Cave::Cave(int id, std::string name, int gold, bool cleared = false) : _id(id), _name(name), _gold(gold), _cleared(cleared) {}



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
    system("clear");
    std::vector<Cave> Caves = setupCaves();

    for(const Cave &Cave : Caves){
        std::cout << "Id: " << Cave.getid() << ", Name: " << Cave.getName() << ", Gold: " << Cave.getGold() << std::endl;
    }

    std::cout << std::endl << std::endl;
}


std::vector<Cave> setupCaves(){

    std::vector<Enemy> enemy = setupEnemies();
    std::vector<Cave> caves; 

    Cave C1(1, " Slime grotto ", 100);
    for(int i = 0; i < 5; i++){
        C1.addEnemy(enemy[0]);
    }
    caves.push_back(C1);

    Cave C2(2, " The forgotten cave ", 200 );
    for(int i = 0; i < 5; i++){
        C2.addEnemy(enemy[1]);
    }
    caves.push_back(C2);

    Cave C3(3, " Unicorn cave ", 1000);
    for(int i = 0; i < 5; i++){
        C3.addEnemy(enemy[6]);
    }
    caves.push_back(C3);

    return caves; 
}


const std::vector<Enemy> & Cave::getEnemies() const{
    return Cave_Enemy;
}



bool Cave::isCleared(){
    return _cleared;
}

void Cave::markCleared(){
    _cleared = true;
}


void cave_select(){

    char cho;
    int choice; 
    std::cout << "Enter the id of the cave you want to clear or 0 to exit: ";
    cho = getKeypress();
    choice = cho - '0';
    std::cout << std::endl;

    std::vector<Cave> caves = setupCaves();
    if(choice > 0 && choice <= caves.size()){
        Cave& selectedCave = caves[choice - 1];
        if(selectedCave.isCleared() == true){
            std::cout << "This cave has not been reset" << std::endl;
        } else {
            std::ostringstream message;
            message << "Entering " << selectedCave.getName() << std::endl << std::endl;
            slow_print(message.str());
            selectedCave.printCaveEnemies();
            
            Cavefight(god, selectedCave);

            message << "";
            message.clear();
            message << "You have cleared " << selectedCave.getName() << " and earned " << selectedCave.getGold() << " gold!" << std::endl;
            slow_print(message.str());
            selectedCave.markCleared();  
            god.addGold(selectedCave.getGold());           
        }
    } else if(choice == 0){
    } else {
         std::cout << "Invalid choice, try again" << std::endl;
         cave_select();
    }
    

}

void Cave::printCaveEnemies() const {
    if (Cave_Enemy.empty()) {
        std::cout << "This cave is currently free of enemies." << std::endl;
    } else {
        std::cout << "List of Enemies in " << _name << ":" << std::endl;
        for (const Enemy& enemy : Cave_Enemy) {
            std::cout << "- " << enemy.getName() << " (HP: " << enemy.getHealth() << ")" << std::endl;
        }
    }
}


void print();