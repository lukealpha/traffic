cmake_minimum_required(VERSION 3.20)
project(traffic)

set(CMAKE_CXX_STANDARD 17)

add_executable(traffic main.cpp graphtools.cpp graphtools.h routeCounter.cpp)
