#include "Tool.h"
#include <iostream> 
#include <limits> 
#include <chrono>
#include <thread>
#include <string> 


void Tool::slow_print(const std::string& message) {
    for (const char c : message) {
        std::cout << c << std::flush;  
        std::this_thread::sleep_for(std::chrono::milliseconds(25)); 
    } 
}

void Tool::delay(){
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
}


void Tool::Windelay(){
    std::this_thread::sleep_for(std::chrono::seconds(2));
}



void enableRawMode() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void disableRawMode() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO); 
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int Tool::getKeypress() {
    char c = 0;
    enableRawMode();
    c = getchar();
    disableRawMode();
    return c;
}

Tool Too;