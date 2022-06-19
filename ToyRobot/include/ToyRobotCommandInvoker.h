#ifndef __TOY_ROBOT_COMMAND_INVOKER_H__
#define __TOY_ROBOT_COMMAND_INVOKER_H__

#include "ToyRobot.h"

#include <memory>
#include <string>
#include <regex>

class ToyRobotCommandInvoker
{
private:
    ToyRobot & _toyRobot;

    void registerCommands();

public:
    ToyRobotCommandInvoker(ToyRobot & toyRobot);
    virtual ~ToyRobotCommandInvoker() = default;

    // return the result of the command after execution
    std::string processCommand(std::string rawCommand);
};

#endif // __TOY_ROBOT_COMMAND_PARSER_H__