#include <string>

#ifndef ASSEMBLER_UTILS_H
#define ASSEMBLER_UTILS_H

namespace utils {
    void trim(std::string &str);
    void deleteComment(std::string &str);  //deletes a comment from a given line; if the line starts with a comment str will become an empty string
}

#endif //ASSEMBLER_UTILS_H
