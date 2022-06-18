#include "Robot.h"

static int robot_id = 0;

Robot::Robot()
    : _id(++robot_id)
    , _facing(nullptr)
    , _position(nullptr)
{
}

void Robot::setPosition(const Coordinate & pos)
{
    _position.reset(new Coordinate(pos));
}

void Robot::setFacing(const Facing & facing)
{
    _facing.reset(new Facing(facing));
}

int Robot::getId() const
{
    return _id;
}

const Coordinate * Robot::getPosition() const
{
    return _position.get();
}

const Facing * Robot::getFacing() const
{
    return _facing.get();
}