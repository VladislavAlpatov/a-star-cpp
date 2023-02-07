cmake_minimum_required(VERSION 3.24)
project(a_star)

set(CMAKE_CXX_STANDARD 23)

add_executable(a_star main.cpp Pathing/Vec2.cpp Pathing/Vec2.h)
target_sources(a_star PRIVATE Pathing/AStar.cpp)