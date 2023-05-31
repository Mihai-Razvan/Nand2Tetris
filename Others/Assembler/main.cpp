#include "Headers/parser.h"
#include "Headers/encoder.h"
#include "Headers/utils.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;


void test(std::vector<std::vector<std::string>> &parsedInstructions)
{
    for(int i = 0; i < parsedInstructions.size(); i++)
    {
        for(int j = 0; j < parsedInstructions[i].size(); j++)
            std::cout << parsedInstructions[i][j] << " ";
        std::cout << std::endl;
    }

    std::cout << "----- END OF FILE -----\n";
}

int main() {
    std::string inputFileName = "Resources/input.txt";
    std::vector<std::vector<std::string>> parsedInstructions = parser::parseFile(inputFileName);

  //  test(parsedInstructions);

    std::vector<std::string > encodedInstructions = encoder::encodeAllInstructions(parsedInstructions);
    utils::writeMachineCodeToFile("Resources/output.hack", encodedInstructions);
}

