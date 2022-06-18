#include "ToyRobot.h"

#include <sstream>

ToyRobot::ToyRobot(Board * board)
{
    _board.reset(board);
}

bool ToyRobot::place(const Coordinate & coord, const Facing & facing)
{
    if (_board && _board->isPositionWithinBounds(coord)) {
        _robot.setPosition(coord);
        _robot.setFacing(facing);
        return true;
    }
    return false;
}

bool ToyRobot::move()
{
    if (!_robot.getPosition() || !_robot.getFacing() || !_board) return false;

    auto newPosition = _robot.getPosition()->next(*_robot.getFacing());
    if (_board->isPositionWithinBounds(newPosition)) {
        _robot.setPosition(newPosition);
        return true;
    }

    return false;
}

bool ToyRobot::left()
{
    if (_robot.getFacing()) {
        _robot.setFacing(_robot.getFacing()->left());
        return true;
    }

    return false;
}

bool ToyRobot::right()
{
    if (_robot.getFacing()) {
        _robot.setFacing(_robot.getFacing()->right());
        return true;
    }

    return false;
}

std::string ToyRobot::report() const
{
    std::stringstream ss;
    auto position = _robot.getPosition();
    auto facing = _robot.getFacing();
    if (position && facing) {
        ss << position->getX() << "," << position->getY();
        ss << "," << _robot.getFacing()->toString();
    } else {
        ss << "Robot hasn't been placed yet!";
    }

    return ss.str();
}