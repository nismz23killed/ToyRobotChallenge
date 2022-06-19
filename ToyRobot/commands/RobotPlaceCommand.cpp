#include "RobotPlaceCommand.h"

RobotPlaceCommand::RobotPlaceCommand(Robot & robot, const RobotPosition & position)
    : _robot(robot)
    , _position(position)
{
}

void RobotPlaceCommand::execute(const Board & board)
{
    _robot.place(_position, board);
}