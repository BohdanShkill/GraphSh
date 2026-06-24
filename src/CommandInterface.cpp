#include <iostream>
#include <CommandInterface.h>
#include <CommandParser.h>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

void CommandInterface::run(){
    bool isRunning = true;
    std::string input = "";
    std::string spaces = "";
    std::vector<std::string> res = {""};
    std::string trash = "";
    int choose;

    while(isRunning){

        std::cout << "1.Text Editor" << std::endl;
        std::cout << "0.Exit" << std::endl;
        std::cout << "Enter the option: ";

        std::cin >> choose;
        std::getline(std::cin, trash);

        switch (choose)
        {
        case 1: 
            std::cout << std::endl << '>';
            std::getline(std::cin, input);
            spaces = spacesOnly(input);

            if(spaces != ""){
            res = CommandParser::parse(input);

            for(const std::string& word : res){
                std::cout << word << " ";
             }
             std::cout << std::endl;
            }
            break;

        case 0: 
            isRunning = false;
            std::cout << "Goodbye!" ;
            break;
        
        default:std::cout << "Error " << std::endl;;
            break;
        

         
        }
    }
}

/*std::string CommandInterface::toLowerCase(std::string& input){
    std::transform(
        input.begin(),
        input.end(),
        input.begin(),
        [](unsigned char c) { return std::tolower(c); }
    );
    return input;
}*/

std::string CommandInterface::spacesOnly(std::string& input1){
    std::string input = input1;

    input.erase(
            std::remove(input.begin(), input.end(), ' '),
            input.end()
        );
        return input;
}

CommandInterface::~CommandInterface(){};