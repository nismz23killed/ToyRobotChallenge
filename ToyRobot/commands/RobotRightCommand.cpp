#include "RobotRightCommand.h"

RobotRightCommand::RobotRightCommand(Robot & robot)
    : _robot(robot)
{
}

void RobotRightCommand::execute(const Board & /* board */)
{
    _robot.turnRight();
}