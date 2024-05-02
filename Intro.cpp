#include <sstream>
#include <limits> 
#include "menu.h"
#include "Intro.h"
#include "Tool.h"


void Tutorial::tutorial(){

    char cho;
    int choice; 

    Too.slow_print("do you wanna skip the tutorial?\n Press 1 for no\n Press 2 for Yes");
    std::cout << std::endl;
    std::cout << "Enter your choice: ";

    cho = Too.getKeypress();
    choice = cho - '0';
    std::cout << std::endl;
    if(choice == 1){
    std::ostringstream message;

    message << "Made by Casper Jensen\n\n"
    << "Welcome to Hobo Adventure! Let's get started on how to play the game:\n\n"
    << "After this message, you will be brought to a screen looking like this:\n\n";

    Too.slow_print(message.str());
    message.str("");
    message.clear();

    std::cout << "Type 1 to create a new hero" << std::endl;
    std::cout << "Type 2 to see current heroes" << std::endl;
    std::cout << "Type 3 to load a hero" << std::endl;
    std::cout << "Type 4 to delete a hero" << std::endl;
    std::cout << "Type 5 to exit game" << std::endl << std::endl;

    message << "\nCreate hero will bring you to the hero creation screen where you can type the name of the hero you want to create.\n"
    << "See current heroes will display a list of all heroes along with their stats.\n"
    << "Load a hero allows you to load your created hero by typing their name.\n"
    << "Delete a hero lets you delete a hero by name.\n\n"
    << "Once you load your character, you will be brought to this screen:\n\n";
   

    Too.slow_print(message.str());
    message.str("");
    message.clear();


    std::cout << "____________________" << std::endl;
    std::cout << "1. Checkout stats " << std::endl;
    std::cout << "____________________" << std::endl;
    std::cout << "2. Fight an enemy " << std::endl;
    std::cout << "____________________" << std::endl;
    std::cout << "3. Enter a cave" << std::endl;
    std::cout << "____________________" << std::endl;
    std::cout << "4. Buy spells" << std::endl;
    std::cout << "____________________" << std::endl;
    std::cout << "5. Take a nap" << std::endl;
    std::cout << "____________________" << std::endl;
    std::cout << "6. Element table" << std::endl;
    std::cout << "____________________" << std::endl;
    std::cout << "7. Save your character  " << std::endl;
    std::cout << "____________________" << std::endl;
    std::cout << "8. Exit game " << std::endl;
    std::cout << "____________________" << std::endl << std::endl;


     message << "\nHere's what each option does:\n"
            << "Checkout stats: Displays your hero's current level, XP, health, damage, mana, and gold. Heroes level up at every 1000 XP, enhancing their attributes.\n"
            << "Fight an enemy: Engage in battle with enemies. You can choose a normal attack or a magic attack (if available). Battles continue until one party is defeated.\n"
            << "Enter a cave: Choose from 3 different caves, each containing 5 identical monsters and a gold reward upon completion.\n"
            << "Buy spells: Purchase spells in 4 tiers (Basic, Intermediate, Advanced, Godly) at the spell shop. Higher tier spells require owning the previous tier spell of the same element.\n"
            << "Take a nap: Restores your hero’s health and mana to full.\n"
            << "Element table: Provides a reference for elemental strengths and weaknesses. (Elements that are stronger against others deal double damage and half the other way around).\n"
            << "Save your character: Saves your game progress. Useful as a backup in case of defeat.\n"
            << "Exit game: Quits the game.\n"
            << "\nThe game concludes once you defeat the Jungle Dragon.\n\nGood luck, adventurer!\n";

    Too.slow_print(message.str());
    message.str("");
    message.clear();

    std::cout << "Press Enter to continue..." << std::endl;  
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    system("clear");
    M1.selector();
    } else if(choice == 2){
        system("clear");
        M1.selector();
    } else {
        std::cout << "Invalid input try again " << std::endl;
        tutorial();
    }

}


void Tutorial::weakness(){

    std::ostringstream message;

    message 
    << "Fire is strong against Metal & Earth\n"
    << "Earth is strong against Water & Metal\n"
    << "Metal is strong against Wood & Water\n"
    << "Water is strong against Wood & Fire\n"
    << "Wood is strong against Earth & Fire" << std::endl << std::endl;

    Too.slow_print(message.str());
    message.str("");
    message.clear();

    std::cout << "Press Enter to continue..." << std::endl;  
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}


Tutorial T1;


