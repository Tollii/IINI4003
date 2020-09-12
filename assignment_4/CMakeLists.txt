cmake_minimum_required(VERSION 3.15)
project(assignment_4)

set(CMAKE_CXX_STANDARD 20)

INCLUDE(FindPkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(task_1 task_1.cpp)
add_executable(task_2 task_2.cpp)

target_link_libraries(task_2 ${GTKMM_LIBRARIES})