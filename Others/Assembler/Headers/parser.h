#include <string>
#include <vector>

#ifndef ASSEMBLER_PARSER_H
#define ASSEMBLER_PARSER_H

namespace parser {
    std::vector<std::vector<std::string>> parseFile(std::string &fileName);
    std::vector<std::string> readInputFile(std::string &fileName);
    std::vector<std::string> deleteWhiteSpace(std::vector<std::string> &lines);
    std::vector<std::string> deleteEmptyLines(std::vector<std::string> &lines);
    std::vector<std::string> trimLines(std::vector<std::string> &lines);
    std::vector<std::string> deleteComments(std::vector<std::string> &lines);
    std::vector<std::vector<std::string>> parseAllLines(std::vector<std::string> &lines, std::vector<std::pair<std::string, int>> &symbolTable, int &variablesNumber);
    std::vector<std::string> parseLine(std::string &str, std::vector<std::pair<std::string, int>> &symbolTable, int &variablesNumber);
    std::vector<std::string> parseAInstruction(std::string &str, std::vector<std::pair<std::string, int>> &symbolTable, int &variablesNumber);
    std::string parseSymbolToValue(std::string symbol, std::vector<std::pair<std::string, int>> &symbolTable, int &variablesNumber);
    std::vector<std::string> parseCInstruction(std::string &str);
    std::vector<std::string> parseAssignCInstruction(std::string &str);
    std::vector<std::string> parseJumpCInstruction(std::string &str);
    void parseSymbols(std::vector<std::string> &lines, std::vector<std::pair<std::string, int>> &symbolTable);
    void writePreDefinedSymbols(std::vector<std::pair<std::string, int>> &symbolTable);
    void writeLabelsAddress(std::vector<std::string> &lines, std::vector<std::pair<std::string, int>> &symbolTable);   //initial pass
    int getSymbolValue(std::string symbol, std::vector<std::pair<std::string, int>> &symbolTable);
    int addVariableSymbolToTable(std::string symbol, std::vector<std::pair<std::string, int>> &symbolTable, int &variablesNumber);
}

#endif //ASSEMBLER_PARSER_H
