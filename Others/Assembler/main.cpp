#include "Headers/parser.h"
#include <string>

using namespace std;

int main() {
    std::string inputFileName = "Resources/input.txt";
    parser::parseFile(inputFileName);
}
