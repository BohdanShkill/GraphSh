#include <sstream>
#include <string>
#include <CommandParser.h>
#include <vector>

std::vector<std::string> CommandParser::parse(const std::string& input){
    std::vector<std::string> tokens;
    std::istringstream stream(input);
    std::string word;
    while(stream >> word){
        tokens.push_back(word);
    }
    return tokens;
} 