#ifndef __COORDINATE_H__
#define __COORDINATE_H__

#include "Facing.h"

#include <string>

class Coordinate
{
private:
    int _x_axis;
    int _y_axis;

public:
    Coordinate(int x, int y);
    virtual ~Coordinate() = default;
    virtual bool operator==(const Coordinate & other) const;

    int getX() const;
    int getY() const;

    std::string toString() const;
};

#endif // __COORDINATE_H__