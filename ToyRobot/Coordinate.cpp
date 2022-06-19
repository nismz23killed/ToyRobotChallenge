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

std::string Coordinate::toString() const
{
    std::stringstream ss;
    ss << _x_axis << "," << _y_axis;

    return ss.str();
}