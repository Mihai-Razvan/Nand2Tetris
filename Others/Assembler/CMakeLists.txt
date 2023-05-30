cmake_minimum_required(VERSION 3.25)
project(Assembler)

set(CMAKE_CXX_STANDARD 17)

add_executable(Assembler main.cpp Headers/parser.h Implementations/parser.cpp Headers/utils.h Implementations/utils.cpp)
