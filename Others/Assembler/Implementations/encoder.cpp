#include "../Headers/encoder.h"
#include "../Headers/utils.h"
#include <string>
#include <vector>
#include <iostream>

namespace encoder {
    std::vector<std::string> encodeAllInstructions(std::vector<std::vector<std::string>> &instructions)
    {
        std::vector<std::string> encodedInstructions = std::vector<std::string>();
        for(int i = 0; i < instructions.size(); i++)
        {
            std::string encodedInstruction = encodeInstruction(instructions[i]);
            encodedInstructions.push_back(encodedInstruction);
        }

//        for(int i = 0; i < encodedInstructions.size(); i++)
//            std::cout << encodedInstructions[i] << std::endl;

        return encodedInstructions;
    }

    std::string encodeInstruction(std::vector<std::string> &instruction)
    {
        if(instruction[0] == "@")
            return encodeAInstruction(instruction);

        return encodeCInstruction(instruction);
    }

    std::string encodeAInstruction(std::vector<std::string> &instruction)
    {
        int value = std::stoi(instruction[1]);
        std::string encodedInstruction = std::string("0") + utils::intToBinaryString(value);

        return encodedInstruction;
    }

    std::string encodeCInstruction(std::vector<std::string> &instruction)
    {
        if(instruction[1] == "=")
            return encodeAssignCInstruction(instruction);

        return encodeJumpCInstruction(instruction);
    }

    std::string encodeAssignCInstruction(std::vector<std::string> &instruction)
    {
        std::string comp = encodeComp(instruction[2]);
        std::string dest = encodeDest(instruction[0]);

        std::string encodedInstruction = "111" + comp + dest + "000";

        return encodedInstruction;
    }

    std::string encodeJumpCInstruction(std::vector<std::string> &instruction)
    {
        std::string comp = encodeComp(instruction[0]);
        std::string jmp = encodeJmp(instruction[2]);

        std::string encodedInstruction = "111" + comp + "000" + jmp;

        return encodedInstruction;
    }

    std::string encodeComp(std::string &comp)
    {
        if(comp == "0")
            return "0101010";
        else if(comp == "1")
            return "0111111";
        else if(comp == "-1")
            return "0111010";
        else if(comp == "D")
            return "0001100";
        else if(comp == "A")
            return "0110000";
        else if(comp == "!D")
            return "0001101";
        else if(comp == "!A")
            return "0110001";
        else if(comp == "-D")
            return "0001111";
        else if(comp == "-A")
            return "0110011";
        else if(comp == "D+1")
            return "0011111";
        else if(comp == "A+1")
            return "0110111";
        else if(comp == "D-1")
            return "0001110";
        else if(comp == "A-1")
            return "0110010";
        else if(comp == "D+A")
            return "0000010";
        else if(comp == "D-A")
            return "0010011";
        else if(comp == "A-D")
            return "0000111";
        else if(comp == "D&A")
            return "0000000";
        else if(comp == "D|A")
            return "0010101";
        else if(comp == "M")
            return "1110000";
        else if(comp == "!M")
            return "1110001";
        else if(comp == "-M")
            return "1110011";
        else if(comp == "M+1")
            return "1110111";
        else if(comp == "M-1")
            return "1110010";
        else if(comp == "D+M")
            return "1000010";
        else if(comp == "D-M")
            return "1010011";
        else if(comp == "M-D")
            return "1000111";
        else if(comp == "D&M")
            return "1000000";
        else if(comp == "D|M")
            return "1010101";
    }

    std::string encodeDest(std::string &dest)
    {
        if(dest == "null")
            return "000";
        else if(dest == "M")
            return "001";
        else if(dest == "D")
            return "010";
        else if(dest == "MD")
            return "011";
        else if(dest == "A")
            return "100";
        else if(dest == "AM")
            return "101";
        else if(dest == "AD")
            return "110";
        else if(dest == "AMD")
            return "111";
    }

    std::string encodeJmp(std::string &jmp)
    {
        if(jmp == "null")
            return "000";
        else if(jmp == "JGT")
            return "001";
        else if(jmp == "JEQ")
            return "010";
        else if(jmp == "JGE")
            return "011";
        else if(jmp == "JLT")
            return "100";
        else if(jmp == "JNE")
            return "101";
        else if(jmp == "JLE")
            return "110";
        else if(jmp == "JMP")
            return "111";
    }
}