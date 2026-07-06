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
    std::vector<std::string> parseInput = {""};
    std::vector<std::string> res = {""};
    std::string option = "";
    int ex ;

    std::cout << "Welcom" << std::endl;

    while(isRunning){

        std::cout << "editor" << std::endl;
        std::cout << "exit" << std::endl;
        std::cout << "Enter the option: ";

        std::getline(std::cin, option);

        if(option == "editor"){
            std::cout << std::endl << '>';
            std::getline(std::cin, input);
            spaces = spacesOnly(input);

            if(spaces != ""){
                parseInput = CommandParser::parse(input);
                 for(std::string word : parseInput){
		            std::cout << word << " ";
	            }

                std::cout << std::endl << std::endl;
                //res = processCommand(parseInput);
            }
        }else if(option == "exit"){

            isRunning = false;
            std::cout << "Goodbye!" ;
        }else{
        std::cout << "Invalid input" << std::endl;;
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

std::string CommandInterface::spacesOnly(const std::string& input1){
    std::string input = input1;

    input.erase(
            std::remove(input.begin(), input.end(), ' '),
            input.end()
        );
        return input;
}

/*std::vector<std::string> processCommand(const std::vector<std::string>& args){
        std::string cmd = args[0];

        if(cmd == "help"){
            std::cout << "new - create a new canvas| (typs of input (string(new)) (int) (int))" << std::endl;
            std::cout << "set - set pixel color" << std::endl;
            std::cout << "help - show this help| (typs of input (string(help)))" << std::endl;
            std::cout << "exit - quit the program" << std::endl;
        } else if(cmd == "new"){
            if (args.size() == 3 &&
            std::all_of(args[1].begin(), args[1].end(), ::isdigit) &&
            std::all_of(args[2].begin(), args[2].end(), ::isdigit)){
                int num1 = std::stoi(args[1]);
                int num2 = std::stoi(args[2]);
                
            }else{
                std::cout << "Useage: new" << std::endl;
                return {};
            }

        }
    
}*/