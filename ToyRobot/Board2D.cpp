#include "Board2D.h"


Board2D::Board2D(unsigned int length, unsigned int height)
    : _length(length)
    , _height(height)
{
}


bool Board2D::isCoordinateWithinBounds(const Coordinate & coord) const
{
    return (coord.getX() >= 0
            && coord.getY() >= 0
            && coord.getX() < _length
            && coord.getY() < _height);
}

unsigned int Board2D::getLength() const
{
    return _length;
}

unsigned int Board2D::getHeight() const
{
    return _height;
}