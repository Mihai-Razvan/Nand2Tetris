#include <vector>
#include <string>

#ifndef VMTRANSLATOR_PARSER_H
#define VMTRANSLATOR_PARSER_H


class Parser {
public:
    static std::vector<std::string> parseVmInstruction(std::string &vmInstruction);
    static const std::string getInstructionType(std::vector<std::string> parsedVmInstruction);
};


#endif //VMTRANSLATOR_PARSER_H
