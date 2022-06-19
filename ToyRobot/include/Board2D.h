#ifndef __BOARD_2D_H__
#define __BOARD_2D_H__

#include "Coordinate.h"
#include "Board.h"

class Board2D : public Board
{
private:
    unsigned int _length;
    unsigned int _height;

public:
    Board2D(unsigned int length, unsigned int width);
    virtual ~Board2D() = default;

    /*
     * Validate if the give coordinate is within the board's bound
     */
    virtual bool isPositionWithinBounds(const Coordinate & coord) const override;

    virtual unsigned int getLength() const;
    virtual unsigned int getHeight() const;
};

#endif // __BOARD_2D_H__