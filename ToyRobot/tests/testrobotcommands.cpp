#include "Robot.h"
#include "Board2D.h"
#include "RobotCommandParser.h"

#include <cassert>

static void testRobotCommandParser()
{
    Robot robot;
    Board2D board(5, 4);
    RobotCommandParser parser(robot, board);

    assert(parser.processCommand("PLACE 1,1,NORTH"));
    assert(parser.processCommand("PLACE 1,1,SOUTH"));
    assert(parser.processCommand("PLACE 1,1,EAST"));
    assert(parser.processCommand("PLACE 1,1,WEST"));
    assert(parser.processCommand("   PLace 1 , 1 ,    NoRtH"));
    assert(!parser.processCommand("PLACE 1,1,NOR"));
    assert(!parser.processCommand("PLACE 1,1,1"));
    assert(!parser.processCommand("PLACE A,A,NORTH"));
    assert(!parser.processCommand("PLACE 1-1,1,NORTH"));

    assert(parser.processCommand("LEFT"));
    assert(parser.processCommand("Left"));
    assert(parser.processCommand("lEFT"));
    assert(parser.processCommand("   LEFT       "));
    assert(!parser.processCommand("LEF"));

    assert(parser.processCommand("RIGHT"));
    assert(parser.processCommand("righT   "));
    assert(parser.processCommand("    Right    "));
    assert(!parser.processCommand("RIGH T"));

    assert(parser.processCommand("MOVE"));
    assert(parser.processCommand("  mOvE   "));
    assert(parser.processCommand("LEFt"));
    assert(!parser.processCommand(" l E F T"));

    assert(parser.processCommand("REPORT"));
    assert(parser.processCommand("RePorT"));
    assert(parser.processCommand("    rePoRT    "));
    assert(!parser.processCommand("R EPORT"));
}

int main(int /* argc */, char ** /* argv */)
{
    testRobotCommandParser();
    return 0;
}