#include <vector>
#include <string>

#ifndef VMTRANSLATOR_TRANSLATOR_H
#define VMTRANSLATOR_TRANSLATOR_H


class Translator {
private:
    std::vector<std::string> parsedVmInstruction;
    std::string instructionType;
    std::vector<std::string> translatedVmInstruction;

    void translateVmInstruction();
    void translate_ARITHMETIC_Instruction();
    void translateOneParameterArithmetic();
    void translateTwoParametersArithmetic();

public:
    Translator(std::vector<std::string> &parsedVmInstruction);
};


#endif //VMTRANSLATOR_TRANSLATOR_H
