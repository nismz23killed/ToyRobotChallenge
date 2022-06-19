#include "Robot.h"
#include "Board2D.h"
#include "RobotPosition.h"

#include <cassert>
#include <iostream>


static void testRobotPosition()
{
    Robot robot;
    Board2D board(5, 5);
    assert(robot.report() == "Robot hasn't been placed yet!");

    RobotPosition position(Coordinate(4, 4), Facing::NORTH);
    robot.place(position, board);
    assert(robot.report() == "4,4,NORTH");

    position.setCoordinate(Coordinate(2, 3));
    robot.place(position, board);
    assert(robot.report() == "2,3,NORTH");

    position.setCoordinate(Coordinate(0, 0));
    robot.place(position, board);
    assert(robot.report() == "0,0,NORTH");

    position.setCoordinate(Coordinate(0, 4));
    robot.place(position, board);
    assert(robot.report() == "0,4,NORTH");

    position.setCoordinate(Coordinate(-2, 4));
    robot.place(position, board);
    assert(robot.report() == "0,4,NORTH");

    position.setCoordinate(Coordinate(5, 5));
    robot.place(position, board);
    assert(robot.report() == "0,4,NORTH");

    position.setCoordinate(Coordinate(200, 200));
    robot.place(position, board);
    assert(robot.report() == "0,4,NORTH");

    position.setCoordinate(Coordinate(0, 4));
    position.setFacing(Facing::EAST);
    robot.place(position, board);
    assert(robot.report() == "0,4,EAST");

    position.setFacing(Facing::WEST);
    robot.place(position, board);
    assert(robot.report() == "0,4,WEST");

    position.setFacing(Facing::SOUTH);
    robot.place(position, board);
    assert(robot.report() == "0,4,SOUTH");
}

static void testRobotTurn()
{
    Robot robot;
    Board2D board(5, 5);

    robot.turnLeft();
    assert(robot.report() == "Robot hasn't been placed yet!");

    RobotPosition position(Coordinate(4, 4), Facing::NORTH);
    robot.place(position, board);

    robot.turnLeft();
    assert(robot.report() == "4,4,WEST");

    robot.turnLeft();
    assert(robot.report() == "4,4,SOUTH");

    robot.turnLeft();
    assert(robot.report() == "4,4,EAST");

    robot.turnLeft();
    assert(robot.report() == "4,4,NORTH");

    robot.turnRight();
    assert(robot.report() == "4,4,EAST");

    robot.turnRight();
    assert(robot.report() == "4,4,SOUTH");

    robot.turnRight();
    assert(robot.report() == "4,4,WEST");

    robot.turnRight();
    assert(robot.report() == "4,4,NORTH");
}

static void testRobotMove()
{
    Robot robot;
    Board2D board(5, 5);

    robot.move(board);
    assert(robot.report() == "Robot hasn't been placed yet!");

    RobotPosition position(Coordinate(4, 4), Facing::NORTH);
    robot.place(position, board);

    // already on top north east, move is invalid
    robot.move(board);
    assert(robot.report() == "4,4,NORTH");
    robot.turnRight();
    robot.move(board);
    assert(robot.report() == "4,4,EAST");

    robot.turnRight();
    robot.move(board);
    assert(robot.report() == "4,3,SOUTH");

    robot.move(board);
    assert(robot.report() == "4,2,SOUTH");

    robot.move(board);
    assert(robot.report() == "4,1,SOUTH");

    robot.move(board);
    assert(robot.report() == "4,0,SOUTH");

    // already on bottom south east, move is invalid
    robot.move(board);
    assert(robot.report() == "4,0,SOUTH");
    robot.turnLeft();
    robot.move(board);
    assert(robot.report() == "4,0,EAST");

    robot.turnRight();
    robot.turnRight();
    robot.move(board);
    assert(robot.report() == "3,0,WEST");

    robot.move(board);
    assert(robot.report() == "2,0,WEST");

    robot.move(board);
    assert(robot.report() == "1,0,WEST");

    robot.move(board);
    assert(robot.report() == "0,0,WEST");

    // already on bottom south west, move is invalid
    robot.move(board);
    assert(robot.report() == "0,0,WEST");
    robot.turnLeft();
    robot.move(board);
    assert(robot.report() == "0,0,SOUTH");

    robot.turnRight();
    robot.turnRight();
    robot.move(board);
    assert(robot.report() == "0,1,NORTH");

    robot.move(board);
    assert(robot.report() == "0,2,NORTH");

    robot.move(board);
    assert(robot.report() == "0,3,NORTH");

    robot.move(board);
    assert(robot.report() == "0,4,NORTH");

    // already on top north west, move is invalid
    robot.move(board);
    assert(robot.report() == "0,4,NORTH");
    robot.turnLeft();
    robot.move(board);
    assert(robot.report() == "0,4,WEST");
}

int main(int /* argc */, char ** /* argv */)
{
    testRobotPosition();
    testRobotTurn();
    testRobotMove();
    return 0;
}