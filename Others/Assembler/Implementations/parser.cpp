#include "../Headers/parser.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

namespace parser {
    std::vector<std::string> readInputFile(std::string fileName)
    {
        std::ifstream fin(fileName);
        std::ofstream fout("Resources/output.txt");
        std::string line;

        while(std::getline(fin, line))
        {
            std::cout << line << std::endl;
            fout << line << "\n";
        }
    }
}