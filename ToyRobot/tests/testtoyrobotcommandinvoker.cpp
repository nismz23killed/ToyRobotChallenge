#include "ToyRobot.h"
#include "ToyRobotCommandInvoker.h"
#include "Board2D.h"

#include <cassert>

static void testToyRobotCommands()
{
    ToyRobot toyRobot(new Board2D(5,5));
    ToyRobotCommandInvoker commander(toyRobot);

    commander.processCommand("PLACE 0,0,NORTH");
    commander.processCommand("MOVE");
    assert(commander.processCommand("REPORT") == "0,1,NORTH");

    commander.processCommand("PLACE 0,0,NORTH");
    commander.processCommand("LEFT");
    assert(commander.processCommand("REPORT") == "0,0,WEST");

    commander.processCommand("  place 1, 2,     east");
    commander.processCommand("mOVE  ");
    commander.processCommand("  Move");
    commander.processCommand("lefT");
    commander.processCommand("mOVe    ");
    assert(commander.processCommand("RepORT     ") == "3,3,NORTH");

    // invalid commands
    commander.processCommand("PLACE D,D,ANYDIRECTION");
    commander.processCommand("PLACE 1,1,ANYDIRECTION");
    commander.processCommand("lef");
    commander.processCommand("move anywhere");
    commander.processCommand("run");
    // the last location will be reported since the above commands are invalid
    assert(commander.processCommand("RepORT     ") == "3,3,NORTH");
}

int main (int /* argc */, char ** /* argv */)
{
    testToyRobotCommands();
    return 0;
}