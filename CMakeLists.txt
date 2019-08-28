cmake_minimum_required(VERSION 3.14)
project(Game_of_life)

set(CMAKE_CXX_STANDARD 14)

add_executable(Game_of_life main.cpp Game.hpp Cell.cpp Cell.h Grid.hpp)