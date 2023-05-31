#include "../Headers/parser.h"
#include "../Headers/utils.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

namespace parser {
    std::vector<std::vector<std::string>> parseFile(std::string &fileName)
    {
        std::vector<std::string> crudeLines = readInputFile(fileName);
        std::vector<std::string> noWhiteSpaceLines = deleteWhiteSpace(crudeLines);
        std::vector<std::pair<std::string, int>> symbolTable = std::vector<std::pair<std::string, int>>();
        parseSymbols(noWhiteSpaceLines, symbolTable);
        int variablesNumber = 0;
        std::vector<std::vector<std::string>> parsedLines = parseAllLines(noWhiteSpaceLines, symbolTable, variablesNumber);

        return parsedLines;
    }

    std::vector<std::string> readInputFile(std::string &fileName)
    {
        std::ifstream fin(fileName);
        std::vector<std::string> lines =::std::vector<std::string>();
        std::string line;

        while(std::getline(fin, line))
            lines.push_back(line);

        return lines;
    }

    std::vector<std::string> deleteWhiteSpace(std::vector<std::string> &lines)
    {
        std::vector<std::string> noEmptyLines = deleteEmptyLines(lines);
        std::vector<std::string> trimmedLines = trimLines(noEmptyLines);
        std::vector<std::string> noCommentLines = deleteComments(trimmedLines);

        return noCommentLines;
    }

    std::vector<std::string> deleteEmptyLines(std::vector<std::string> &lines)
    {
        std::vector<std::string> noEmptyLines = std::vector<std::string>();

        for(int i = 0; i < lines.size(); i++)
            if(lines[i].size() != 0)
                noEmptyLines.push_back(lines[i]);

        return noEmptyLines;
    }

    std::vector<std::string> trimLines(std::vector<std::string> &lines)
    {
        for(int i = 0; i < lines.size(); i++)
            utils::trim(lines[i]);

        return lines;
    }

    std::vector<std::string> deleteComments(std::vector<std::string> &lines) //if a line starts with a comment it deletes the line
    {
        std::vector<std::string> noCommentLines = std::vector<std::string>();

        for(int i = 0; i < lines.size(); i++)
        {
            utils::deleteComment(lines[i]);
            if(lines[i].length() != 0)
                noCommentLines.push_back(lines[i]);
        }

        return noCommentLines;
    }

    void parseSymbols(std::vector<std::string> &lines, std::vector<std::pair<std::string, int>> &symbolTable)
    {
        writePreDefinedSymbols(symbolTable);
        writeLabelsAddress(lines, symbolTable);

//        for(int i = 0; i < symbolTable.size(); i++)
//            std::cout << symbolTable[i].first << " " << symbolTable[i].second << std::endl;
    }

    void writePreDefinedSymbols(std::vector<std::pair<std::string, int>> &symbolTable)
    {
        symbolTable.push_back(std::make_pair("R0", 0));
        symbolTable.push_back(std::make_pair("R1", 1));
        symbolTable.push_back(std::make_pair("R2", 2));
        symbolTable.push_back(std::make_pair("R3", 3));
        symbolTable.push_back(std::make_pair("R4", 4));
        symbolTable.push_back(std::make_pair("R5", 5));
        symbolTable.push_back(std::make_pair("R6", 6));
        symbolTable.push_back(std::make_pair("R7", 7));
        symbolTable.push_back(std::make_pair("R8", 8));
        symbolTable.push_back(std::make_pair("R9", 9));
        symbolTable.push_back(std::make_pair("R10", 10));
        symbolTable.push_back(std::make_pair("R11", 11));
        symbolTable.push_back(std::make_pair("R12", 12));
        symbolTable.push_back(std::make_pair("R13", 13));
        symbolTable.push_back(std::make_pair("R14", 14));
        symbolTable.push_back(std::make_pair("R15", 15));
        symbolTable.push_back(std::make_pair("SCREEN", 16384));
        symbolTable.push_back(std::make_pair("KBD", 24576));
        symbolTable.push_back(std::make_pair("SP", 0));
        symbolTable.push_back(std::make_pair("LCL", 1));
        symbolTable.push_back(std::make_pair("ARG", 2));
        symbolTable.push_back(std::make_pair("THIS", 3));
        symbolTable.push_back(std::make_pair("THAT", 4));
    }

    void writeLabelsAddress(std::vector<std::string> &lines, std::vector<std::pair<std::string, int>> &symbolTable)
    {
        int k = 0;
        for(int i = 0; i < lines.size(); i++)
            if(lines[i][0] == '(')
            {
                std::string label = lines[i].substr(1, lines[i].length() - 2);
                symbolTable.push_back(std::make_pair(label, k));
            }
            else
                k++;
    }

    int getSymbolValue(std::string symbol, std::vector<std::pair<std::string, int>> &symbolTable)
    {
        for(int i = 0; i < symbolTable.size(); i++)
            if(symbolTable[i].first == symbol)
                return symbolTable[i].second;

        return -1;
    }

    std::vector<std::vector<std::string>> parseAllLines(std::vector<std::string> &lines, std::vector<std::pair<std::string, int>> &symbolTable, int &variablesNumber)
    {
        std::vector<std::vector<std::string>> parsedLines = std::vector<std::vector<std::string>>();

        for(int i = 0; i < lines.size(); i++)
        {
            if(lines[i][0] != '(')

            {
                std::vector<std::string> parsedLine = parseLine(lines[i], symbolTable, variablesNumber);
                parsedLines.push_back(parsedLine);
            }
        }

        return parsedLines;
    }

    std::vector<std::string> parseLine(std::string &str, std::vector<std::pair<std::string, int>> &symbolTable, int &variablesNumber)
    {
        if(str[0] == '@')
            return parseAInstruction(str, symbolTable, variablesNumber);

        return parseCInstruction(str);
    }

    std::vector<std::string> parseAInstruction(std::string &str, std::vector<std::pair<std::string, int>> &symbolTable, int &variablesNumber)
    {
        std::vector<std::string> parsedInstruction = std::vector<std::string>();
        parsedInstruction.push_back("@");
        std::string valueOrSymbol = str.substr(1, str.length() - 1);

        if(utils::isNumber(valueOrSymbol))
            parsedInstruction.push_back(valueOrSymbol);  //it means is a value
        else
            parsedInstruction.push_back(parseSymbolToValue(valueOrSymbol, symbolTable, variablesNumber));

        return parsedInstruction;
    }

    std::string parseSymbolToValue(std::string symbol, std::vector<std::pair<std::string, int>> &symbolTable, int &variablesNumber)
    {
        if(getSymbolValue(symbol, symbolTable) != -1)
            return std::to_string(getSymbolValue(symbol, symbolTable));

        return std::to_string(addVariableSymbolToTable(symbol, symbolTable, variablesNumber));
    }

    int addVariableSymbolToTable(std::string symbol, std::vector<std::pair<std::string, int>> &symbolTable, int &variablesNumber)
    {
        symbolTable.push_back(std::make_pair(symbol, 16 + variablesNumber));
        variablesNumber++;
        return 15 + variablesNumber;
    }

    std::vector<std::string> parseCInstruction(std::string &str)
    {
        for(int i = 0; i < str.length(); i++)
            if(str[i] == '=')
                return parseAssignCInstruction(str);

        return parseJumpCInstruction(str);
    }

    std::vector<std::string> parseAssignCInstruction(std::string &str)
    {
        std::vector<std::string> parsedInstruction = std::vector<std::string>();

        int i = 0;
        while(str[i] != '=')
            i++;

        parsedInstruction.push_back(str.substr(0, i));
        parsedInstruction.push_back("=");
        parsedInstruction.push_back(str.substr(i + 1, str.length() - i - 1));
        return parsedInstruction;
    }

    std::vector<std::string> parseJumpCInstruction(std::string &str)
    {
        std::vector<std::string> parsedInstruction = std::vector<std::string>();

        int i = 0;
        while(str[i] != ';')
            i++;

        parsedInstruction.push_back(str.substr(0, i));
        parsedInstruction.push_back(";");
        parsedInstruction.push_back(str.substr(i + 1, str.length() - i - 1));

        return parsedInstruction;
    }
}