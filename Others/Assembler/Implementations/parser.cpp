#include "../Headers/parser.h"
#include "../Headers/utils.h"
#include <string>
#include <vector>
#include <fstream>

namespace parser {
    std::vector<std::vector<std::string>> parseFile(std::string &fileName)
    {
        std::vector<std::string> crudeLines = readInputFile(fileName);
        std::vector<std::string> noWhiteSpaceLines = deleteWhiteSpace(crudeLines);
        std::vector<std::vector<std::string>> parsedLines = parseAllLines(noWhiteSpaceLines);

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

    std::vector<std::vector<std::string>> parseAllLines(std::vector<std::string> &lines)
    {
        std::vector<std::vector<std::string>> parsedLines =std::vector<std::vector<std::string>>();

        for(int i = 0; i < lines.size(); i++)
        {
            std::vector<std::string> parsedLine = parseLine(lines[i]);
            parsedLines.push_back(parsedLine);
        }

        return parsedLines;
    }

    std::vector<std::string> parseLine(std::string &str)
    {
        if(str[0] == '@')
            return parseAInstruction(str);

        return parseCInstruction(str);
    }

    std::vector<std::string> parseAInstruction(std::string &str)
    {
        std::vector<std::string> parsedInstruction = std::vector<std::string>();
        parsedInstruction.push_back("@");
        parsedInstruction.push_back(str.substr(1, str.length() - 1));

        return parsedInstruction;
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