#ifndef __ROBOT_COMMAND_PARSER_H__
#define __ROBOT_COMMAND_PARSER_H__

#include "Robot.h"
#include "Board.h"

#include <string>

class RobotCommandParser
{
private:
    Robot & _robot;
    const Board & _board;

    void registerCommands();

public:
    RobotCommandParser(Robot & Robot, const Board & board);
    virtual ~RobotCommandParser() = default;

    bool processCommand(std::string strCommand);
};

#endif // __ROBOT_COMMAND_PARSER_H__