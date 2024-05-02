#ifndef TOOL_H
#define TOOL_H

#include <iostream> 
#include <string> 
#include <termios.h>
#include <unistd.h>


class Tool{
    public: 
        void slow_print(const std::string& message);
        void delay();
        void Windelay();
        int getKeypress();
};

void enableRawMode();

void disableRawMode();



extern Tool Too;

#endif //TOOL_H