cmake_minimum_required(VERSION 3.27)
project(MaxFlowOptimCPP)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_FOLDER ./include)

include_directories(${INCLUDE_FOLDER})

add_executable(MaxFlowOptimCPP main.cpp
        util/GraphGenerator.cpp
        util/GraphGenerator.hpp)
