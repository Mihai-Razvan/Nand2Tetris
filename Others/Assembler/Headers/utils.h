#include <string>
#include <vector>

#ifndef ASSEMBLER_UTILS_H
#define ASSEMBLER_UTILS_H

namespace utils {
    void trim(std::string &str);
    void deleteComment(std::string &str);  //deletes a comment from a given line; if the line starts with a comment str will become an empty string
    std::string intToBinaryString(int x);
    bool isNumber(std::string str);
    void writeMachineCodeToFile(std::string fileName, std::vector<std::string> data);
}

#endif //ASSEMBLER_UTILS_H
