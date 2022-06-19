#ifndef __TOY_ROBOT_H__
#define __TOY_ROBOT_H__

#include "Coordinate.h"
#include "Facing.h"
#include "Robot.h"
#include "Board.h"

#include <memory>
#include <string>

class ToyRobot
{
private:
    Robot _robot;
    std::unique_ptr<Board> _board;

public:
    ToyRobot(Board * board);
    virtual ~ToyRobot() = default;

    bool place(const Coordinate & coord, const Facing & facing);
    bool move();
    bool left();
    bool right();

    std::string report() const;

    void processCommand(std::string command);
};

#endif // __TOY_ROBOT_H__