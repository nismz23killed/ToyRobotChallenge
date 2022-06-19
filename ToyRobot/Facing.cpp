#include "Facing.h"

#include <map>
#include <algorithm>

static std::map<Facing, const char *> facingMap = {
    { Facing::NORTH, "NORTH" },
    { Facing::SOUTH, "SOUTH" },
    { Facing::EAST, "EAST" },
    { Facing::WEST, "WEST" },
};


const char * FacingToStr(Facing facing)
{
    return facingMap[facing];
}

Facing FacingFromStr(const char * facingStr)
{
    if (facingStr) {
        std::string str(facingStr);
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
        for (auto & it: facingMap) {
            if (str.compare(it.second) == 0) {
                return it.first;
            }
        }
    }

    return Facing::NORTH; // default
}