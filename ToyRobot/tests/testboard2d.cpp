#include "Board2D.h"

#include <cassert>


static void testBoard()
{
    Board2D board(5, 20);

    assert(board.getLength() == 5);
    assert(board.getHeight() == 20);

    assert(board.isPositionWithinBounds(Coordinate(0, 0)));
    assert(board.isPositionWithinBounds(Coordinate(2, 4)));
    assert(board.isPositionWithinBounds(Coordinate(4, 19)));
    assert(board.isPositionWithinBounds(Coordinate(0, 19)));

    assert(!board.isPositionWithinBounds(Coordinate(-1, 0)));
    assert(!board.isPositionWithinBounds(Coordinate(5, 20)));
    assert(!board.isPositionWithinBounds(Coordinate(1000, -100)));
    assert(!board.isPositionWithinBounds(Coordinate(-100, -100)));
}

int main(int /* argc */, char ** /* argv */)
{
    testBoard();
    return 0;
}