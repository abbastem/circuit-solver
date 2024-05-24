cmake_minimum_required(VERSION 3.25)
project(Circuit_design)

set(CMAKE_CXX_STANDARD 17)

add_executable(Circuit_design main.cpp Complex.cpp Complex.h Source.cpp Source.h generat.cpp generat.h)
