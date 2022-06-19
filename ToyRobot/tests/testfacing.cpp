#include "Facing.h"

#include <cassert>
#include <string>

static void testFacingToString()
{
    assert(std::string(FacingToStr(Facing::NORTH)) == "NORTH");
    assert(std::string(FacingToStr(Facing::SOUTH)) == "SOUTH");
    assert(std::string(FacingToStr(Facing::EAST)) == "EAST");
    assert(std::string(FacingToStr(Facing::WEST)) == "WEST");
}

static void testFacingFromString()
{
    assert(FacingFromStr("NORTH") == Facing::NORTH);
    assert(FacingFromStr("SOUTH") == Facing::SOUTH);
    assert(FacingFromStr("EAST") == Facing::EAST);
    assert(FacingFromStr("WEST") == Facing::WEST);

    // north will be returned for invalid input
    assert(FacingFromStr("ANYWHERE") == Facing::NORTH);
}

int main(int /* argc */, char ** /* argv */)
{
    testFacingToString();
    testFacingFromString();
    return 0;
}