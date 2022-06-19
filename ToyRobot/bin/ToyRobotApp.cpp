#include "Robot.h"
#include "Board2D.h"
#include "RobotCommandParser.h"

#include <string>
#include <iostream>

int main(int  /* argc */, char ** /* argv */)
{
    Robot robot;
    Board2D board(5, 5);
    RobotCommandParser parser(robot, board);

    while(true) {
        std::string input;
        getline(std::cin, input);
        parser.processCommand(input);
    }

    return 0;
}