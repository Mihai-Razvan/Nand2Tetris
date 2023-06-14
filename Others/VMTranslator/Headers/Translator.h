#include <vector>
#include <string>

#ifndef VMTRANSLATOR_TRANSLATOR_H
#define VMTRANSLATOR_TRANSLATOR_H


class Translator {
private:
    std::vector<std::string> parsedVmInstruction;
    std::string instructionType;
    std::vector<std::string> translatedVmInstruction;
    static std::vector<std::pair<std::string, int>> functionReturnCounter;
    static std::string currentFunctionName;

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
    void translate_LABEL_Instruction();
    void translate_GOTO_Instruction();
    void translate_IF_Instruction();
    void translate_FUNCTION_Instruction();
    void translate_RETURN_Instruction();
    void translate_CALL_Instruction();

    int getFunctionReturnCounter(std::string functionName);  //it also increases the counter

public:
    static int compareLabelIndex;

    Translator(std::vector<std::string> &parsedVmInstruction);
    static std::vector<std::string> boot();
    void translateVmInstruction();
    std::vector<std::string>& getTranslatedVmInstruction();
};


#endif //VMTRANSLATOR_TRANSLATOR_H
