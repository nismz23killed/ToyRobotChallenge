#ifndef __ROBOT_REPORT_COMMAND_H__
#define __ROBOT_REPORT_COMMAND_H__

#include "RobotCommand.h"
#include "Robot.h"

#include <string>

class RobotReportCommand : public RobotCommand
{
private:
    Robot & _robot;
    std::string _report;

public:
    RobotReportCommand(Robot & Robot);
    virtual ~RobotReportCommand() = default;

    virtual void execute(const Board & board) override;

    std::string getReport() const;
};

#endif // __ROBOT_REPORT_COMMAND_H__