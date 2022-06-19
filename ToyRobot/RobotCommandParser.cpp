#include "RobotCommandParser.h"
#include "RobotPosition.h"
#include "RobotPlaceCommand.h"
#include "RobotLeftCommand.h"
#include "RobotRightCommand.h"
#include "RobotMoveCommand.h"
#include "RobotReportCommand.h"

#include <regex>
#include <map>
#include <functional>
#include <iostream>

using namespace std;

static map<string, function<void (const smatch & match)> > regexCmds;

RobotCommandParser::RobotCommandParser(Robot & robot, const Board & board)
    : _robot(robot)
    , _board(board)
{
    registerCommands();
}

bool RobotCommandParser::processCommand(string strCommand)
{
    for (auto & it: regexCmds) {
        std::regex rgx(it.first, std::regex_constants::icase);
        std::smatch match;
        if (it.second && std::regex_search(strCommand, match, rgx)) {
            it.second(match);
            return true;
        }
    }

    return false;
}

void RobotCommandParser::registerCommands()
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
            Facing facing = FacingFromStr(match[4].str().c_str());

            auto position = RobotPosition(Coordinate(x, y), facing);
            RobotPlaceCommand(_robot, position).execute(_board);
        }
    ));

    // Left command
    regexCmds.insert(pair(
        "^\\s*(LEFT)\\s*$",
        [&] (const smatch & match) {
            RobotLeftCommand(_robot).execute(_board);
        }
    ));

    // Right command
    regexCmds.insert(pair(
        "^\\s*(RIGHT)\\s*$",
        [&] (const smatch & match) {
            RobotRightCommand(_robot).execute(_board);
        }
    ));

    // Move command
    regexCmds.insert(pair(
        "^\\s*(MOVE)\\s*$",
        [&] (const smatch & match) {
            RobotMoveCommand(_robot).execute(_board);
        }
    ));

    // Report command
    regexCmds.insert(pair(
        "^\\s*(REPORT)\\s*$",
        [&] (const smatch & match) {
            auto command = RobotReportCommand(_robot);
            command.execute(_board);
            std::cout << "Output: " << command.getReport() << std::endl;
        }
    ));

}