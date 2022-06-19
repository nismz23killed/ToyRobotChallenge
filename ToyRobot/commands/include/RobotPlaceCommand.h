#ifndef __ROBOT_PLACE_COMMAND_H__
#define __ROBOT_PLACE_COMMAND_H__

#include "RobotCommand.h"
#include "Robot.h"

class RobotPlaceCommand : public RobotCommand
{
private:
    Robot & _robot;
    RobotPosition _position;

public:
    RobotPlaceCommand(Robot & Robot, const RobotPosition & position);
    virtual ~RobotPlaceCommand() = default;

    virtual void execute(const Board & board) override;
};

#endif // __ROBOT_PLACE_COMMAND_H__