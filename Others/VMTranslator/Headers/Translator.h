#include <vector>
#include <string>

#ifndef VMTRANSLATOR_TRANSLATOR_H
#define VMTRANSLATOR_TRANSLATOR_H


class Translator {
private:
    std::vector<std::string> parsedVmInstruction;
    std::string instructionType;
    std::vector<std::string> translatedVmInstruction;

    void translate_ARITHMETIC_Instruction();
    void translateOneParameterArithmetic();
    void translateTwoParametersArithmetic();
    void translate_PUSH_Instruction();
    void translatePushConstant(int value);
    void translatePushStatic(int value);
    void translatePushTemp(int value);
    void translatePushPointer(int value);
    void translatePushSegmentPointers(int value, std::string segmentAddress);   //local, argument, this, that
    void translate_POP_Instruction();
    void translatePopStatic(int value);
    void translatePopTemp(int value);
    void translatePopPointer(int value);
    void translatePopSegmentPointers(int value, std::string segmentAddress);   //local, argument, this, that

public:
    static int compareLabelIndex;

    Translator(std::vector<std::string> &parsedVmInstruction);
    void translateVmInstruction();
    std::vector<std::string>& getTranslatedVmInstruction();
};


#endif //VMTRANSLATOR_TRANSLATOR_H
