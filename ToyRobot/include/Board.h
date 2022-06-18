#ifndef __BOARD_H__
#define __BOARD_H__

#include "Coordinate.h"
#include "Facing.h"

class Board
{
private:
    unsigned int _length;
    unsigned int _height;

public:
    Board(unsigned int length, unsigned int width);
    virtual ~Board() = default;

    /*
     * Validate if the give coordinate is within the board's bound
     */
    virtual bool isPositionWithinBounds(const Coordinate & coord) const;

    virtual unsigned int getLength() const;
    virtual unsigned int getHeight() const;
};

#endif // __BOARD_H__