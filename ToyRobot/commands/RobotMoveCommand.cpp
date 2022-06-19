#include "RobotMoveCommand.h"

RobotMoveCommand::RobotMoveCommand(Robot & robot)
    : _robot(robot)
{
}

void RobotMoveCommand::execute(const Board & board)
{
    _robot.move(board);
}