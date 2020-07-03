cmake_minimum_required(VERSION 3.16)
project(console_rpg)

set(CMAKE_CXX_STANDARD 14)

add_executable(console_rpg main.cpp GameOjbect.h Enemy.h Player.h Game.cpp Game.h)