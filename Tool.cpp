#include "Tool.h"
#include <iostream> 
#include <limits> 

int getNumericInput() { //Ensures that it is a numeric input and will reset the error if any char is set as input
    int input;
    while (true) { // Loop until valid input is received
        if (std::cin >> input) {
            // If a number was successfully read, break out of the loop
            break;
        } else {
            // Clear the error flag on cin
            std::cin.clear();
            // Ignore the rest of the incorrect input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, please try again." << std::endl;
        }
    }
    return input;
}