cmake_minimum_required(VERSION 3.13)
project(ToyRobot)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        Facing
        Coordinate
)

enable_testing()
add_subdirectory(tests)

add_library(ToyRobot SHARED ${SOURCE_FILES})
target_include_directories(ToyRobot PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)