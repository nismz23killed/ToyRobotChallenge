#ifndef __ROBOT_LEFT_COMMAND_H__
#define __ROBOT_LEFT_COMMAND_H__

#include "RobotCommand.h"
#include "Robot.h"

class RobotLeftCommand : public RobotCommand
{
private:
    Robot & _robot;

public:
    RobotLeftCommand(Robot & Robot);
    virtual ~RobotLeftCommand() = default;

    virtual void execute(const Board & board) override;
};

#endif // __ROBOT_LEFT_COMMAND_H__