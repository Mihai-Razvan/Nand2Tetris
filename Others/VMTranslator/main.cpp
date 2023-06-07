#include "Headers/utils.h"
#include "Headers/Parser.h"
#include "Headers/Translator.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string inputFileName = "Resources/input.vm";
    std::vector<std::string> fileLines = utils::readFile(inputFileName);

    for(int i = 0; i < fileLines.size(); i++)
    {
        std::vector<std::string> parsedVmInstruction = Parser::parseVmInstruction(fileLines[i]);

        if(parsedVmInstruction.size() != 0)
        {
            Translator translator = Translator(parsedVmInstruction);

//            for(int j = 0; j < parsedVmInstruction.size(); j++)
//                std::cout << parsedVmInstruction[j] << " ";
//            std::cout << std::endl;
        }
    }
}
