cmake_minimum_required(VERSION 3.25)
project(VMTranslator)

set(CMAKE_CXX_STANDARD 17)

add_executable(VMTranslator main.cpp Implementations/Parser.cpp Headers/Parser.h Headers/utils.h Implementations/utiles.cpp Implementations/Translator.cpp Headers/Translator.h)
