#ifndef __ROBOT_MOVE_COMMAND_H__
#define __ROBOT_MOVE_COMMAND_H__

#include "RobotCommand.h"
#include "Robot.h"

class RobotMoveCommand : public RobotCommand
{
private:
    Robot & _robot;

public:
    RobotMoveCommand(Robot & Robot);
    virtual ~RobotMoveCommand() = default;

    virtual void execute(const Board & board) override;
};

#endif // __ROBOT_MOVE_COMMAND_H__