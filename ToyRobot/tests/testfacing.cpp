#include "Facing.h"

#include <cassert>
#include <string>

static void testFacingToString()
{
    Facing facing = Facing::NORTH;
    assert(std::string(facing.toString()) == "NORTH");

    facing = Facing::SOUTH;
    assert(std::string(facing.toString()) == "SOUTH");

    facing = Facing::EAST;
    assert(std::string(facing.toString()) == "EAST");

    facing = Facing::WEST;
    assert(std::string(facing.toString()) == "WEST");
}

static void testFacingLeft()
{
    Facing facing = Facing::NORTH;
    assert(facing.left() == Facing::WEST);
    
    facing = Facing::WEST;
    assert(facing.left() == Facing::SOUTH);

    facing = Facing::SOUTH;
    assert(facing.left() == Facing::EAST);

    facing = Facing::EAST;
    assert(facing.left() == Facing::NORTH);
}

static void testFacingRight()
{
    Facing facing = Facing::NORTH;
    assert(facing.right() == Facing::EAST);
    
    facing = Facing::EAST;
    assert(facing.right() == Facing::SOUTH);

    facing = Facing::SOUTH;
    assert(facing.right() == Facing::WEST);

    facing = Facing::WEST;
    assert(facing.right() == Facing::NORTH);
}


int main(int /* argc */, char ** /* argv */)
{
    testFacingToString();
    testFacingLeft();
    testFacingRight();
    return 0;
}