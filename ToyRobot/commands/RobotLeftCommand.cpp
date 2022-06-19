#include "RobotLeftCommand.h"

RobotLeftCommand::RobotLeftCommand(Robot & robot)
    : _robot(robot)
{
}

void RobotLeftCommand::execute(const Board & /* board */)
{
    _robot.turnLeft();
}