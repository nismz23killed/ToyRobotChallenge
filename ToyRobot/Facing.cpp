#include "Facing.h"

#include <map>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <string>

static std::map<Facing::Direction, const char *> facingMap = {
    { Facing::NORTH, "NORTH" },
    { Facing::SOUTH, "SOUTH" },
    { Facing::EAST, "EAST" },
    { Facing::WEST, "WEST" },
};

Facing::Facing(Direction direction)
    : _direction(direction)
{
}

Facing & Facing::operator=(Direction direction)
{
    _direction = direction;
    return *this;
}

bool Facing::operator==(const Direction other) const
{
    return _direction == other;
}

const char * Facing::toString() const
{
    return facingMap[_direction];
}

Facing Facing::left() const
{
    switch(_direction) {
        case NORTH: return WEST;
        case SOUTH: return EAST;
        case EAST: return NORTH;
        case WEST: return SOUTH;
    }
}

Facing Facing::right() const
{
    switch(_direction) {
        case NORTH: return EAST;
        case SOUTH: return WEST;
        case EAST: return SOUTH;
        case WEST: return NORTH;
    }
}

Facing::Direction Facing::fromStr(const char * facingStr)
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

    return NORTH; // default
}