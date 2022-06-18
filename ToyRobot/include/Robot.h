#ifndef __ROBOT_H__
#define __ROBOT_H__

#include "Coordinate.h"
#include "Facing.h"

#include <memory>

class Robot
{
private:
    // unique id of the robot
    int _id;

    // Direction where the rboot is facing
    std::unique_ptr<Facing> _facing;

    // Position of the robot on the scene
    std::unique_ptr<Coordinate> _position;

public:
    Robot();
    virtual ~Robot() = default;

    // Place a robot to a give position
    void setPosition(const Coordinate & coord);

    // Change the facing direction of the robot
    void setFacing(const Facing & facing);

    // getters
    int getId() const;
    const Coordinate * getPosition() const;
    const Facing * getFacing() const;
};

#endif // __ROBOT_H__