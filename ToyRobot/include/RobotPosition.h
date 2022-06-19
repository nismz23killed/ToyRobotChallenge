#ifndef __ROBOT_POSITION_H__
#define __ROBOT_POSITION_H__

#include "Coordinate.h"
#include "Facing.h"

class RobotPosition
{
private:
    Coordinate _coordinate;
    Facing _facing;

public:
    RobotPosition(const Coordinate & coord, Facing facing);
    virtual ~RobotPosition() = default;

    void setCoordinate(const Coordinate & coordinate);
    void setFacing(Facing facing);

    const Coordinate & getCoordinate() const;
    Facing getFacing() const;
};

#endif //__ROBOT_POSITION_H__