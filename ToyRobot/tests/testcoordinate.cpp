#include "Coordinate.h"
#include "Facing.h"

#include <cassert>
#include <iostream>


static void testCoordinate()
{
    assert(Coordinate(-1, 2).toString() == "-1,2");
    assert(Coordinate(500, 200).toString() == "500,200");
    assert(Coordinate(-100, -100).toString() == "-100,-100");
    assert(Coordinate(150, 5).toString() == "150,5");
}

int main(int /* argc */, char ** /* argv */)
{
    testCoordinate();
    return 0;
}