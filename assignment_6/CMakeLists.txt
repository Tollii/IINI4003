cmake_minimum_required(VERSION 3.15)
project(assignment_6)

set(CMAKE_CXX_STANDARD 20)

add_executable(chess task_1/chess.cpp)


find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(web task_2/web.cpp)
target_link_libraries(web ${Boost_LIBRARIES})
