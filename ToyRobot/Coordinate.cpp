#include "Coordinate.h"

#include <sstream>

Coordinate::Coordinate(int x, int y)
    : _x_axis(x)
    , _y_axis(y)
{
}

bool Coordinate::operator==(const Coordinate & other) const
{
    return _x_axis == other._x_axis && _y_axis == other._y_axis;
}

int Coordinate::getX() const
{
    return _x_axis;
}

int Coordinate::getY() const
{
    return _y_axis;
}

Coordinate Coordinate::next(const Facing & direction) const
{
    int x = _x_axis;
    int y = _y_axis;

    switch (direction) {
        case Facing::NORTH: y++; break;
        case Facing::SOUTH: y--; break;
        case Facing::EAST: x++; break;
        case Facing::WEST: x--; break;
    }

    return Coordinate(x, y);
}

std::string Coordinate::toString() const
{
    std::stringstream ss;
    ss << _x_axis << "," << _y_axis;

    return ss.str();
}