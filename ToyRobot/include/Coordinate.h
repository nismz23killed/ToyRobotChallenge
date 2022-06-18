#ifndef __COORDINATE_H__
#define __COORDINATE_H__

#include "Facing.h"

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

    Coordinate next(const Facing & direction) const;
};

#endif // __COORDINATE_H__