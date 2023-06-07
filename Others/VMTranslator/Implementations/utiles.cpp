#include "../Headers/utils.h"
#include <string>
#include <vector>
#include <fstream>

namespace utils {
    std::vector<std::string> readFile(std::string &fileName)
    {
        std::ifstream fin(fileName);
        std::vector<std::string> lines =::std::vector<std::string>();
        std::string line;

        while(std::getline(fin, line))
            lines.push_back(line);

        return lines;
    }
}
