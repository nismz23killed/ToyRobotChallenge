#include<ToyRobot.h>
#include<Robot.h>
#include<ToyRobotCommandInvoker.h>

#include <string>
#include <iostream>

int main(int  /* argc */, char ** /* argv */)
{
    ToyRobot toyRobot(new Board(5, 5));
    ToyRobotCommandInvoker commander(toyRobot);

    while(true) {
        std::string input;
        getline(std::cin, input);

        auto result = commander.processCommand(input);
        if (!result.empty()) {
            std::cout << "Output: " << result << std::endl;
        }
    }

    return 0;
}