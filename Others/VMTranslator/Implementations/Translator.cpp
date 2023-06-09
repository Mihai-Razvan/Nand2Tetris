#include "../Headers/Translator.h"
#include "../Headers/Parser.h"
#include <iostream>

int Translator::compareLabelIndex = 0;

Translator::Translator(std::vector<std::string> &parsedVmInstruction) {
    this->parsedVmInstruction = parsedVmInstruction;
    this->instructionType = Parser::getInstructionType(parsedVmInstruction);
}

void Translator::translateVmInstruction() {
    translatedVmInstruction = std::vector<std::string>();

    if(instructionType == "C_ARITHMETIC")
        translate_ARITHMETIC_Instruction();
    else if(instructionType == "C_PUSH")
        translate_PUSH_Instruction();
    else if(instructionType == "C_POP")
        translate_POP_Instruction();
}

void Translator::translate_ARITHMETIC_Instruction() {
    if(parsedVmInstruction[0] == "neg" || parsedVmInstruction[0] == "not")
        translateOneParameterArithmetic();
    else
        translateTwoParametersArithmetic();
}

void Translator::translateOneParameterArithmetic() {
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("A=M-1");   //M=y

    if(parsedVmInstruction[0] == "neg")
        translatedVmInstruction.push_back("M=-M");
    else if(parsedVmInstruction[0] == "not")
        translatedVmInstruction.push_back("M=!M");
}

void Translator::translateTwoParametersArithmetic() {
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("A=M-1");
    translatedVmInstruction.push_back("D=M");    //D=y
    translatedVmInstruction.push_back("A=A-1");  //M=x

    if(parsedVmInstruction[0] == "add")
        translatedVmInstruction.push_back("D=D+M");
    else if(parsedVmInstruction[0] == "sub")
        translatedVmInstruction.push_back("D=M-D");
    else if(parsedVmInstruction[0] == "and")
        translatedVmInstruction.push_back("D=D&M");
    else if(parsedVmInstruction[0] == "or")
        translatedVmInstruction.push_back("D=D|M");
    else   //comparing operations
    {
        std::string compareTrueLabel = "COMPARE_TRUE_LABEL_" + std::to_string(compareLabelIndex);
        std::string compareContinueLabel = "COMPARE_CONTINUE_LABEL_" + std::to_string(compareLabelIndex);
        Translator::compareLabelIndex++;

        translatedVmInstruction.push_back("D=M-D");
        translatedVmInstruction.push_back("@" + compareTrueLabel);                  //@COMPARE_TRUE_LABEL_0

        if(parsedVmInstruction[0] == "eq")
            translatedVmInstruction.push_back("D;JEQ");
        else if(parsedVmInstruction[0] == "gt")
            translatedVmInstruction.push_back("D;JGT");
        else if(parsedVmInstruction[0] == "lt")
            translatedVmInstruction.push_back("D;JLT");

        translatedVmInstruction.push_back("D=0");
        translatedVmInstruction.push_back("@" + compareContinueLabel);              //@COMPARE_CONTINUE_LABEL_0
        translatedVmInstruction.push_back("0;JMP");
        translatedVmInstruction.push_back("(" + compareTrueLabel + ")");            //(COMPARE_TRUE_LABEL_)
        translatedVmInstruction.push_back("D=-1");
        translatedVmInstruction.push_back("(" + compareContinueLabel + ")");        //(COMPARE_CONTINUE_LABEL_0)
    }

    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("A=M-1");
    translatedVmInstruction.push_back("A=A-1");
    translatedVmInstruction.push_back("M=D");
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("M=M-1");
}

void Translator::translate_PUSH_Instruction()
{
    int value = std::stoi(parsedVmInstruction[2]);

    if(parsedVmInstruction[1] == "constant")
        translatePushConstant(value);
    else if(parsedVmInstruction[1] == "static")
        translatePushStatic(value);
    else if(parsedVmInstruction[1] == "temp")
        translatePushTemp(value);
    else if(parsedVmInstruction[1] == "pointer")
        translatePushPointer(value);
    else if(parsedVmInstruction[1] == "local")
        translatePushSegmentPointers(value, "LCL");
    else if(parsedVmInstruction[1] == "argument")
        translatePushSegmentPointers(value, "ARG");
    else if(parsedVmInstruction[1] == "this")
        translatePushSegmentPointers(value, "THIS");
    else if(parsedVmInstruction[1] == "that")
        translatePushSegmentPointers(value, "THAT");
}

void Translator::translatePushConstant(int value)
{
    translatedVmInstruction.push_back("@" + std::to_string(value));
    translatedVmInstruction.push_back("D=A");               //D=value
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("A=M");
    translatedVmInstruction.push_back("M=D");
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("M=M+1");
}

void Translator::translatePushStatic(int value)
{
    translatedVmInstruction.push_back("@Foo." + std::to_string(value));
    translatedVmInstruction.push_back("D=M");
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("A=M");
    translatedVmInstruction.push_back("M=D");
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("M=M+1");
}

void Translator::translatePushTemp(int value)
{
    value += 5;

    translatedVmInstruction.push_back("@" + std::to_string(value));
    translatedVmInstruction.push_back("D=M");
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("A=M");
    translatedVmInstruction.push_back("M=D");
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("M=M+1");
}

void Translator::translatePushPointer(int value)
{
    if(value == 0)
        translatedVmInstruction.push_back("@THIS");
    else
        translatedVmInstruction.push_back("@THAT");

    translatedVmInstruction.push_back("D=M");
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("A=M");
    translatedVmInstruction.push_back("M=D");
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("M=M+1");
}

void Translator::translatePushSegmentPointers(int value, std::string segmentAddress)
{
    translatedVmInstruction.push_back("@" + segmentAddress);
    translatedVmInstruction.push_back("D=M");
    translatedVmInstruction.push_back("@" + std::to_string(value));
    translatedVmInstruction.push_back("A=D+A");
    translatedVmInstruction.push_back("D=M");
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("A=M");
    translatedVmInstruction.push_back("M=D");
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("M=M+1");
}

void Translator::translate_POP_Instruction()
{
    int value = std::stoi(parsedVmInstruction[2]);

    //pop constant doesn't exist
    if(parsedVmInstruction[1] == "static")
        translatePopStatic(value);
    else if(parsedVmInstruction[1] == "temp")
        translatePopTemp(value);
    else if(parsedVmInstruction[1] == "pointer")
        translatePopPointer(value);
    else if(parsedVmInstruction[1] == "local")
        translatePopSegmentPointers(value, "LCL");
    else if(parsedVmInstruction[1] == "argument")
        translatePopSegmentPointers(value, "ARG");
    else if(parsedVmInstruction[1] == "this")
        translatePopSegmentPointers(value, "THIS");
    else if(parsedVmInstruction[1] == "that")
        translatePopSegmentPointers(value, "THAT");
}

void Translator::translatePopStatic(int value)
{
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("A=M");
    translatedVmInstruction.push_back("A=A-1");
    translatedVmInstruction.push_back("D=M");   //D=top stack value
    translatedVmInstruction.push_back("@Foo." + std::to_string(value));
    translatedVmInstruction.push_back("M=D");
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("M=M-1");
}

void Translator::translatePopTemp(int value)
{
    value += 5;

    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("A=M");
    translatedVmInstruction.push_back("A=A-1");
    translatedVmInstruction.push_back("D=M");   //D=top stack value
    translatedVmInstruction.push_back("@" + std::to_string(value));
    translatedVmInstruction.push_back("M=D");
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("M=M-1");
}

void Translator::translatePopPointer(int value)
{
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("A=M");
    translatedVmInstruction.push_back("A=A-1");
    translatedVmInstruction.push_back("D=M");   //D=top stack value

    if(value == 0)
        translatedVmInstruction.push_back("@THIS");
    else
        translatedVmInstruction.push_back("@THAT");

    translatedVmInstruction.push_back("M=D");
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("M=M-1");
}

void Translator::translatePopSegmentPointers(int value, std::string segmentAddress)
{
    translatedVmInstruction.push_back("@" + segmentAddress);
    translatedVmInstruction.push_back("D=M");
    translatedVmInstruction.push_back("@" + std::to_string(value));
    translatedVmInstruction.push_back("D=D+A");
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("A=M");
    translatedVmInstruction.push_back("M=D");     //on the address pointed by SP will be the address on our segment
    translatedVmInstruction.push_back("A=A-1");
    translatedVmInstruction.push_back("D=M");     //D is now the second value on the stack (the one to be popped)
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("A=M");
    translatedVmInstruction.push_back("A=M");
    translatedVmInstruction.push_back("M=D");
    translatedVmInstruction.push_back("@SP");
    translatedVmInstruction.push_back("M=M-1");
}

std::vector<std::string> &Translator::getTranslatedVmInstruction() {
    return translatedVmInstruction;
}
