#ifndef TOOL_H
#define TOOL_H

#include <iostream> 
#include <string> 
#include <termios.h>
#include <unistd.h>


int getNumericInput();

void slow_print(const std::string& message);

void delay();

void Windelay();


void enableRawMode();

void disableRawMode();

int getKeypress();

#endif //TOOL_H