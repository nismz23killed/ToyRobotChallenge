#ifndef __BOARD_H__
#define __BOARD_H__

#include "Coordinate.h"
#include "Facing.h"

class Board
{
public:
    virtual ~Board() = default;

    /*
     * Validate if the give coordinate is within the board's bound
     */
    virtual bool isCoordinateWithinBounds(const Coordinate & coord) const = 0;


};

#endif // __BOARD_H__