#include "Tool.h"
#include <iostream> 
#include <limits> 

int getNumericInput() { 
    int input;
    while (true) { 
        if (std::cin >> input) {
            break;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, please try again." << std::endl;
        }
    }
    return input;
}