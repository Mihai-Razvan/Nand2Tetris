#include "../Headers/Parser.h"
#include <vector>
#include <string.h>
#include <iostream>

std::vector<std::string> Parser::parseVmInstruction(std::string &vmInstruction)
{
    std::vector<std::string> parsedVmInstructions = std::vector<std::string>();

    if(vmInstruction[0] == ' ' || vmInstruction[0] == '/')
        return parsedVmInstructions;

    char vmInstruction_array[vmInstruction.length() + 1];
    strcpy(vmInstruction_array, vmInstruction.c_str());

    char *token = strtok(vmInstruction_array, " ");

    while (token != nullptr)
    {
        parsedVmInstructions.push_back(token);
        token = strtok(nullptr, " ");
    }

    return parsedVmInstructions;
}

const std::string Parser::getInstructionType(std::vector<std::string> parsedVmInstruction)
{
    if(parsedVmInstruction[0] == "push")
        return "C_PUSH";
    else if(parsedVmInstruction[0] == "pop")
        return "C_POP";
    else
        return "C_ARITHMETIC";
}