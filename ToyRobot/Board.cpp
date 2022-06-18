#include "Board.h"


Board::Board(unsigned int length, unsigned int height)
    : _length(length)
    , _height(height)
{
}


bool Board::isPositionWithinBounds(const Coordinate & coord) const
{
    return (coord.getX() >= 0
            && coord.getY() >= 0
            && coord.getX() < _length
            && coord.getY() < _height);
}

unsigned int Board::getLength() const
{
    return _length;
}

unsigned int Board::getHeight() const
{
    return _height;
}