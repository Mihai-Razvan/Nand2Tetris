#include "../Headers/utils.h"
#include <string>
#include <bitset>
#include <fstream>

namespace utils {
    void trim(std::string &str)
    {
        int i = 0;

        //trim the start
        while(str[i] == ' ')
            i++;

        str = str.substr(i, str.length() - i);

        //trim the end
        i = str.length() - 1;
        while(str[i] == ' ')
        {
            str = str.substr(0, str.length() - 1);
            i--;
        }
    }

    void deleteComment(std::string &str)
    {
        for(int i = 0; i < str.length(); i++)
            if(str[i] == '/' && i + 1 < str.length() && str[i + 1] == '/')
            {
                str = str.substr(0, i);
                break;
            }
    }

    std::string intToBinaryString(int x)
    {
        return std::bitset<15>(x).to_string();
    }

    void writeMachineCodeToFile(std::string fileName, std::vector<std::string> data)
    {
        std::ofstream fout(fileName);
        for(int i = 0; i < data.size(); i++)
            fout << data[i] << std::endl;
    }
}