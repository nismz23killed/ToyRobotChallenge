#include "RobotReportCommand.h"

RobotReportCommand::RobotReportCommand(Robot & robot)
    : _robot(robot)
{
}

void RobotReportCommand::execute(const Board & /* board */)
{
    _report = _robot.report();
}

std::string RobotReportCommand::getReport() const
{
    return _report;
}