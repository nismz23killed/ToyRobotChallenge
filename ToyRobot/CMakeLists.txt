cmake_minimum_required(VERSION 3.13)
project(ToyRobot)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        Facing
        Coordinate
        RobotPosition
        Robot
        Board2D
        RobotCommandParser
        ${CMAKE_CURRENT_SOURCE_DIR}/commands/RobotPlaceCommand
        ${CMAKE_CURRENT_SOURCE_DIR}/commands/RobotLeftCommand
        ${CMAKE_CURRENT_SOURCE_DIR}/commands/RobotRightCommand
        ${CMAKE_CURRENT_SOURCE_DIR}/commands/RobotMoveCommand
        ${CMAKE_CURRENT_SOURCE_DIR}/commands/RobotReportCommand
)

enable_testing()
add_subdirectory(tests)

add_library(ToyRobot ${SOURCE_FILES})
target_include_directories(ToyRobot PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/commands/include
)

add_executable(ToyRobotApp  ${CMAKE_CURRENT_SOURCE_DIR}/bin/ToyRobotApp)
target_link_libraries(ToyRobotApp ToyRobot)