#include "../Headers/Translator.h"
#include "../Headers/Parser.h"
#include <iostream>

Translator::Translator(std::vector<std::string> &parsedVmInstruction) {
    this->parsedVmInstruction = parsedVmInstruction;
    this->instructionType = Parser::getInstructionType(parsedVmInstruction);
}

void Translator::translateVmInstruction() {
    translatedVmInstruction = std::vector<std::string>();

    if(instructionType == "C_ARITHMETIC")
        translate_ARITHMETIC_Instruction();
}

void Translator::translate_ARITHMETIC_Instruction() {
    if(parsedVmInstruction[0] == "neg" || parsedVmInstruction[0] == "not")
        translateOneParameterArithmetic();
    else
        translateTwoParametersArithmetic();
}

void Translator::translateOneParameterArithmetic() {

}

void Translator::translateTwoParametersArithmetic() {
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("A=M-1");
    translatedVmInstruction.push_back("D=M");
    translatedVmInstruction.push_back("A=A-1");
    translatedVmInstruction.push_back("A=M");

    if(parsedVmInstruction[0] == "add")
        translatedVmInstruction.push_back("D=A+D");
    else if(parsedVmInstruction[0] == "sub")
        translatedVmInstruction.push_back("D=A-D");
    else if(parsedVmInstruction[0] == "and")
        translatedVmInstruction.push_back("D=D&A");
    else if(parsedVmInstruction[0] == "or")
        translatedVmInstruction.push_back("D=D|A");

    translatedVmInstruction.push_back("M=D");
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("M=M-1");
}

