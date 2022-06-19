#include "ToyRobotCommandInvoker.h"

#include <regex>
#include <map>
#include <functional>
#include <iostream>

using namespace std;

static map<string, function<string (const smatch & match)>> regexCmds;

ToyRobotCommandInvoker::ToyRobotCommandInvoker(ToyRobot & toyRobot)
    : _toyRobot(toyRobot)
{
    registerCommands();
}

string ToyRobotCommandInvoker::processCommand(string rawCommand)
{
    for (auto & it: regexCmds) {
        std::regex rgx(it.first, std::regex_constants::icase);
        std::smatch match;
        if (it.second && std::regex_search(rawCommand, match, rgx)) {
            return it.second(match);
        }
    }

    return string();
}

void ToyRobotCommandInvoker::registerCommands()
{
    // PLACE command
    regexCmds.insert(pair(
        "^\\s*(PLACE)\\s+([0-9]+)\\s*,\\s*([0-9]+)\\s*,\\s*(NORTH|SOUTH|EAST|WEST)\\s*$",
        [&] (const smatch & match) {
            // match[0] is the whole string match
            // match[1] is the command
            //match[2..n] are the command parameters
            int x = stoi(match[2]);
            int y = stoi(match[3]);
            Facing facing = Facing::fromStr(match[4].str().c_str());
            _toyRobot.place(Coordinate(x,y), facing);
            return string();
        }
    ));

    // Left command
    regexCmds.insert(pair(
        "^\\s*(LEFT)\\s*$",
        [&] (const smatch & match) {
            _toyRobot.left();
            return string();
        }
    ));

    // Right command
    regexCmds.insert(pair(
        "^\\s*(RIGHT)\\s*$",
        [&] (const smatch & match) {
            _toyRobot.right();
            return string();
        }
    ));

    // Move command
    regexCmds.insert(pair(
        "^\\s*(MOVE)\\s*$",
        [&] (const smatch & match) {
            _toyRobot.move();
            return string();
        }
    ));

    // Report command
    regexCmds.insert(pair(
        "^\\s*(REPORT)\\s*$",
        [&] (const smatch & match) {
            cout << "HELLO" << endl;
            return _toyRobot.report();
        }
    ));

}