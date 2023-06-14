#include <vector>
#include <string>

#ifndef VMTRANSLATOR_UTILS_H
#define VMTRANSLATOR_UTILS_H

namespace utils {
    std::vector<std::string> readFile(std::string &fileName);
    std::string getFileName(std::string functionName);   //being provided a function name it can extract the file name (the fileName is before . and after is function name)
}

#endif //VMTRANSLATOR_UTILS_H
