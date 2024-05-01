#include "Tool.h"
#include <iostream> 
#include <limits> 
#include <chrono>
#include <thread>
#include <string> 

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


void slow_print(const std::string& message) {
    for (const char c : message) {
        std::cout << c << std::flush;  
        std::this_thread::sleep_for(std::chrono::milliseconds(25)); 
    } 
}

void delay(){
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
}


void Windelay(){
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
