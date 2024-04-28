#include "Cave.h"
#include "Tool.h"
#include "enemy.h"
#include "fight.h"

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
    caves.push_back(C1);

    Cave C2(2, " The forgotten cave ", 200 );
    caves.push_back(C2);

    Cave C3(3, " Unicorn cave ", 1000);
    caves.push_back(C3);

    for(int i = 0; i < 5; i++){
        C1.addEnemy(enemy[0]);
        C2.addEnemy(enemy[1]);
        C3.addEnemy(enemy[6]);
    }

    return caves; 
}

const std::vector<Enemy> & Cave::getEnemies() const{
    return Cave_Enemy;
}



bool Cave::isCleared(){
    std::cout << "Cave Cleared Flag: " << _cleared << std::endl;
    return _cleared;
}

void Cave::markCleared(){
    _cleared = true;
}


void cave_select(){

    int choice = 0; 
    std::cout << "Enter the id of the cave you want to clear: ";
    choice = getNumericInput();
    std::cout << std::endl;

    std::vector<Cave> caves = setupCaves();
    if(choice > 0 && choice <= caves.size()){
        Cave& selectedCave = caves[choice - 1];
        if(selectedCave.isCleared() == true){
            std::cout << "This cave has not been reset" << std::endl;
        } else {
            std::cout << "Entering " << selectedCave.getName() << std::endl;

            
            Cavefigth(god, const_cast<std::vector<Enemy>&>(selectedCave.getEnemies()));

            std::cout << "You have cleared " << selectedCave.getName() << " and earned " << selectedCave.getGold() << " gold!" << std::endl;
            selectedCave.markCleared();  
            god.addGold(selectedCave.getGold());           
        }
    } else {
        std::cout << "Invalid choice, try again" << std::endl;
    }
    

}