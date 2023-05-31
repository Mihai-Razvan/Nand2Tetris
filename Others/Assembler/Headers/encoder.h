#include <string>
#include <vector>

#ifndef ASSEMBLER_ENCODER_H
#define ASSEMBLER_ENCODER_H

namespace encoder {
    std::vector<std::string> encodeAllInstructions(std::vector<std::vector<std::string>> &instructions);
    std::string encodeInstruction(std::vector<std::string> &instruction);
    std::string encodeAInstruction(std::vector<std::string> &instruction);
    std::string encodeCInstruction(std::vector<std::string> &instruction);
    std::string encodeAssignCInstruction(std::vector<std::string> &instruction);
    std::string encodeJumpCInstruction(std::vector<std::string> &instruction);
    std::string encodeComp(std::string &comp);
    std::string encodeDest(std::string &dest);
    std::string encodeJmp(std::string &jmp);
}

#endif //ASSEMBLER_ENCODER_H
