#include "Robot.h"

#include <cassert>


static void testRobot()
{
    Robot robot;

    assert(robot.getPosition() == nullptr);
    assert(robot.getFacing() == nullptr);

    robot.setFacing(Facing::WEST);
    assert(robot.getFacing());
    assert(*robot.getFacing() == Facing::WEST);
    robot.setFacing(Facing::EAST);
    assert(*robot.getFacing() == Facing::EAST);

    robot.setPosition(Coordinate(5, 5));
    assert(robot.getPosition());
    assert(*robot.getPosition() == Coordinate(5, 5));
    robot.setPosition(Coordinate(20, -5));
    assert(*robot.getPosition() == Coordinate(20, -5));
}

int main(int /* argc */, char ** /* argv */)
{
    testRobot();
    return 0;
}