#ifndef __ROBOT_RIGHT_COMMAND_H__
#define __ROBOT_RIGHT_COMMAND_H__

#include "RobotCommand.h"
#include "Robot.h"

class RobotRightCommand : public RobotCommand
{
private:
    Robot & _robot;

public:
    RobotRightCommand(Robot & Robot);
    virtual ~RobotRightCommand() = default;

    virtual void execute(const Board & board) override;
};

#endif // __ROBOT_RIGHT_COMMAND_H__