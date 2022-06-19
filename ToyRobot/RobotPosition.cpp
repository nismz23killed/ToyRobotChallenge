#include "RobotPosition.h"

RobotPosition::RobotPosition(const Coordinate & coord, Facing facing)
    : _coordinate(coord)
    , _facing(facing)
{
}

void RobotPosition::setCoordinate(const Coordinate & coordinate)
{
    _coordinate = coordinate;
}

void RobotPosition::setFacing(Facing facing)
{
    _facing = facing;
}

const Coordinate & RobotPosition::getCoordinate() const
{
    return _coordinate;
}

Facing RobotPosition::getFacing() const
{
    return _facing;
}