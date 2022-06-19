#include "Robot.h"
#include "Facing.h"

#include <cassert>
#include <sstream>
#include <iostream>

static int robot_id = 0;

Robot::Robot()
    : _id(++robot_id)
    , _position(nullptr)
{
}

int Robot::getId() const
{
    return _id;
}

void Robot::place(const RobotPosition & position, const Board & board)
{
    if (board.isCoordinateWithinBounds(position.getCoordinate())) {
        _position.reset(new RobotPosition(position));
    }
}

void Robot::turnLeft()
{
    // robot hasn't been placed yet
    if (!_position) return;

    Facing facing = Facing::NORTH;

    switch (_position->getFacing())  {
        case Facing::NORTH: facing = Facing::WEST; break;
        case Facing::WEST: facing = Facing::SOUTH; break;
        case Facing::SOUTH: facing = Facing::EAST; break;
        case Facing::EAST: facing = Facing::NORTH; break;
        default:
            assert("Unhandled facing!!!");
    }

    _position->setFacing(facing);
}

void Robot::turnRight()
{
    // robot hasn't been placed yet
    if (!_position) return;

    Facing facing = Facing::NORTH;

    switch (_position->getFacing())  {
        case Facing::NORTH: facing = Facing::EAST; break;
        case Facing::EAST: facing = Facing::SOUTH; break;
        case Facing::SOUTH: facing = Facing::WEST; break;
        case Facing::WEST: facing = Facing::NORTH; break;
        default:
            assert("Unhandled facing!!!");
    }

    _position->setFacing(facing);
}

void Robot::move(const Board & board)
{
    // robot hasn't been placed yet
    if (!_position) return;

    int x = _position->getCoordinate().getX();
    int y = _position->getCoordinate().getY();

    switch(_position->getFacing()) {
        case Facing::NORTH: y++; break;
        case Facing::SOUTH: y--; break;
        case Facing::EAST: x++; break;
        case Facing::WEST: x--; break;
        default:
            assert("Unhandled facing");
    }

    auto moveCoordinate = Coordinate(x, y);

    if (board.isCoordinateWithinBounds(moveCoordinate)) {
        _position->setCoordinate(Coordinate(x, y));
    }
}

std::string Robot::report() const
{
    if (!_position) {
        return "Robot hasn't been placed yet!";
    }

    std::stringstream ss;
    ss << _position->getCoordinate().toString() << "," << FacingToStr(_position->getFacing());

    return ss.str();
}