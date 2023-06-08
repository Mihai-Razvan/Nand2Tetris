#include "Headers/utils.h"
#include "Headers/Parser.h"
#include "Headers/Translator.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::string inputFileName = "Resources/input.vm";
    std::vector<std::string> fileLines = utils::readFile(inputFileName);

    std::string outputFileName = "Resources/output.txt";
    std::ofstream fout(outputFileName);

    for(int i = 0; i < fileLines.size(); i++)
    {
        std::vector<std::string> parsedVmInstruction = Parser::parseVmInstruction(fileLines[i]);

        if(!parsedVmInstruction.empty())
        {
            fout << "// " << fileLines[i] << std::endl;
            Translator translator = Translator(parsedVmInstruction);
            translator.translateVmInstruction();
            std::vector<std::string> translatedVmInstruction = translator.getTranslatedVmInstruction();

            for(int j = 0; j < translatedVmInstruction.size(); j++)
                fout << translatedVmInstruction[j] << std::endl;

//            for(int j = 0; j < parsedVmInstruction.size(); j++)
//                std::cout << parsedVmInstruction[j] << " ";
//            std::cout << std::endl;
        }
    }

    return 0;
}
