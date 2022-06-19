#include "ToyRobot.h"
#include "Board2D.h"

#include <cassert>
#include <sstream>
#include <string>
#include <iostream>


static void testPlaceRobot()
{
    ToyRobot toyRobot(new Board2D(10, 20));
    assert(!toyRobot.place(Coordinate(-1, 5), Facing::EAST));
    assert(!toyRobot.place(Coordinate(1000, -5), Facing::WEST));
    assert(!toyRobot.place(Coordinate(10, 20), Facing::NORTH));

    assert(toyRobot.place(Coordinate(5, 10), Facing::NORTH));
    assert(toyRobot.place(Coordinate(2, 8), Facing::EAST));
    assert(toyRobot.place(Coordinate(0, 0), Facing::WEST));
    assert(toyRobot.place(Coordinate(9, 19), Facing::SOUTH));
}

static void testTurnRobotLeft()
{
    ToyRobot toyRobot(new Board2D(10, 20));

    assert(!toyRobot.left());
    assert(toyRobot.report() == "Robot hasn't been placed yet!");

    assert(toyRobot.place(Coordinate(2,2), Facing::EAST));
    assert(toyRobot.report() == "2,2,EAST");

    assert(toyRobot.left());
    assert(toyRobot.report() == "2,2,NORTH");

    assert(toyRobot.left());
    assert(toyRobot.report() == "2,2,WEST");

    assert(toyRobot.left());
    assert(toyRobot.report() == "2,2,SOUTH");

    assert(toyRobot.left());
    assert(toyRobot.report() == "2,2,EAST");
}

static void testTurnRobotRight()
{
    ToyRobot toyRobot(new Board2D(10, 20));

    assert(!toyRobot.right());
    assert(toyRobot.report() == "Robot hasn't been placed yet!");

    assert(toyRobot.place(Coordinate(2,2), Facing::EAST));
    assert(toyRobot.report() == "2,2,EAST");

    assert(toyRobot.right());
    assert(toyRobot.report() == "2,2,SOUTH");

    assert(toyRobot.right());
    assert(toyRobot.report() == "2,2,WEST");

    assert(toyRobot.right());
    assert(toyRobot.report() == "2,2,NORTH");

    assert(toyRobot.right());
    assert(toyRobot.report() == "2,2,EAST");
}

static void testMoveRobot()
{
    unsigned int boardSize = 5;
    ToyRobot toyRobot(new Board2D(boardSize, boardSize));

    assert(!toyRobot.move());
    assert(toyRobot.report() == "Robot hasn't been placed yet!");

    int x = 0;
    int y = 0;
    Facing facing = Facing::NORTH;
    std::stringstream ss;

    assert(toyRobot.place(Coordinate(x,y), facing));
    assert(toyRobot.report() == "0,0,NORTH");

    for (; y <  boardSize - 1; y++) {
        assert(toyRobot.move());
        ss.str("");
        ss << x << "," << y + 1 << "," << facing.toString();
        assert(toyRobot.report() == ss.str());
    }
    assert(!toyRobot.move()); // invalid move
    assert(toyRobot.report() == ss.str()); // no movement,last move is expected

    assert(toyRobot.right());
    facing = Facing::EAST; //Expected direction after turning the robot
    for (; x <  boardSize - 1; x++) {
        assert(toyRobot.move());
        ss.str("");
        ss << x + 1 << "," << y << "," << facing.toString();
        assert(toyRobot.report() == ss.str());
    }
    assert(!toyRobot.move()); // invalid move
    assert(toyRobot.report() == ss.str()); // no movement,last move is expected

    toyRobot.right();
    facing = Facing::SOUTH; //Expected direction after turning the robot
    for (; y > 0; y--) {
        assert(toyRobot.move());
        ss.str("");
        ss << x << "," << y - 1 << "," << facing.toString();
        assert(toyRobot.report() == ss.str());
    }
    assert(!toyRobot.move()); // invalid move
    assert(toyRobot.report() == ss.str()); // no movement,last move is expected

    assert(toyRobot.right());
    facing = Facing::WEST; //Expected direction after turning the robot
    for (; x > 0; x--) {
        assert(toyRobot.move());
        ss.str("");
        ss << x - 1 << "," << y << "," << facing.toString();
        assert(toyRobot.report() == ss.str());
    }
    assert(!toyRobot.move()); // invalid move
    assert(toyRobot.report() == ss.str()); // no movement,last move is expected
}

int main(int /* argc */, char ** /* argv */)
{
    testPlaceRobot();
    testTurnRobotLeft();
    testTurnRobotRight();
    testMoveRobot();
    return 0;
}