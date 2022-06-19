#ifndef __ROBOT_COMMAND_H__
#define __ROBOT_COMMAND_H__

#include "Board.h"

class RobotCommand
{
public:
    virtual ~RobotCommand() = default;

    virtual void execute(const Board & board) = 0;
};

#endif // __ROBOT_COMMAND_H__