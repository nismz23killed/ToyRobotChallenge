#include "Coordinate.h"
#include "Facing.h"

#include <cassert>
#include <iostream>


static void testCoordinateNext()
{
    Coordinate coord(-1, 2);

    assert(coord.toString() == "-1,2");
    assert(coord.next(Facing::NORTH) == Coordinate(-1, 3));
    assert(coord.toString() == "-1,2");
    assert(coord.next(Facing::SOUTH) == Coordinate(-1, 1));
    assert(coord.next(Facing::EAST) == Coordinate(0, 2));
    assert(coord.next(Facing::WEST) == Coordinate(-2, 2));
}

int main(int /* argc */, char ** /* argv */)
{
    testCoordinateNext();
    return 0;
}