#include <iostream>
#include <CommandInterface.h>
#include <CommandParser.h>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

CommandInterface::CommandInterface() 
: currentCanvas_(nullptr) {}

bool isRunning = true;

void CommandInterface::run(){
    
    std::string option = "";
    std::string input = "";
    std::string spaces = "";
    std::vector<std::string> parseInput = {""};
    std::string trash = "";

    while(isRunning){

         std::cout  << '>';
         std::getline(std::cin, input);
         spaces = spacesOnly(input);

        if(spaces != ""){
             parseInput = CommandParser::parse(input);
              /*for(std::string word : parseInput){
		         std::cout << word << " ";
	         }*/
             std::cout << std::endl;
             processCommand(parseInput);
         }
    }
}

//Methods
//**************************************************************** 
void CommandInterface::processCommand(const std::vector<std::string>& args){
        std::string cmd = args[0];

        if(cmd == "help"){
            std::cout << "new - create a new canvas| (typs of input (string(new)) (int Width) (int Height))" << std::endl;
            std::cout << "set - set pixel color| (typs of input (string(set)) (int R) (int G) (int B) (int Colum) (int Row))" << std::endl;
            std::cout << "drawLine - draw a line| (typs of input (string(drawLine)) (int R) (int G) (int B) (int x1) (int y1) (int x2) (int y2))" << std::endl;
            std::cout << "help - show this help| (typs of input (string(help)))" << std::endl;
            std::cout << "exit - quit the program" << std::endl;
        } else if(cmd == "new"){
            if (args.size() == 3 &&
            std::all_of(args[1].begin(), args[1].end(), ::isdigit) &&
            std::all_of(args[2].begin(), args[2].end(), ::isdigit)){
                int num1 = std::stoi(args[1]);
                int num2 = std::stoi(args[2]);
                
                delete currentCanvas_;
                currentCanvas_ = nullptr;

                currentCanvas_ = new Canvas(num1, num2);

                std::cout << "Canvas created: "<< currentCanvas_->getWidth() << 'x' << currentCanvas_->getHeight() << std::endl;
            }else{
                std::cout << "Useage: new" << std::endl;
            }

        }else if(cmd == "set"){
            if (args.size() == 6 &&
            std::all_of(args[1].begin(), args[1].end(), ::isdigit) &&
            std::all_of(args[2].begin(), args[2].end(), ::isdigit) &&
            std::all_of(args[3].begin(), args[3].end(), ::isdigit) &&
            std::all_of(args[4].begin(), args[4].end(), ::isdigit) &&
            std::all_of(args[5].begin(), args[5].end(), ::isdigit)){

                int r = std::stoi(args[1]);
                int g = std::stoi(args[2]);
                int b = std::stoi(args[3]);
                int col = std::stoi(args[4]);
                int row = std::stoi(args[5]);

                if(currentCanvas_ != nullptr){

                    Color color(r, g, b);
                    currentCanvas_->setPixel(col, row, color);

                    const Color& pixel = currentCanvas_->getPixel(col, row);
                    std::cout << "Pixel(" << col << "," << row << ") = ("
                              << pixel.getR() << "," << pixel.getG() << "," << pixel.getB()
                              << ")" << std::endl;
                }else{
                    std::cout << "No canvas! Use 'new' first." << std::endl;
                }
            }else{
                std::cout << "Useage: set" << std::endl;
            }
        }else if(cmd == "drawLine"){
            if (args.size() == 8 &&
            std::all_of(args[1].begin(), args[1].end(), ::isdigit) &&
            std::all_of(args[2].begin(), args[2].end(), ::isdigit) &&
            std::all_of(args[3].begin(), args[3].end(), ::isdigit) &&
            std::all_of(args[4].begin(), args[4].end(), ::isdigit) &&
            std::all_of(args[5].begin(), args[5].end(), ::isdigit) &&
            std::all_of(args[6].begin(), args[6].end(), ::isdigit) &&
            std::all_of(args[7].begin(), args[7].end(), ::isdigit)){

                int r = std::stoi(args[1]);
                int g = std::stoi(args[2]);
                int b = std::stoi(args[3]);
                int x1 = std::stoi(args[4]);
                int y1 = std::stoi(args[5]);
                int x2 = std::stoi(args[6]);
                int y2 = std::stoi(args[7]);

                if (currentCanvas_ != nullptr){

                    Color color(r, g ,b);
                    currentCanvas_->drawLine(x1, y1, x2, y2, color);

                    const Color& pixel = currentCanvas_->getPixel(x2, y2);
                    std::cout << "Pixel(" << x2 << "," << y2 << ") = ("
                              << pixel.getR() << "," << pixel.getG() << "," << pixel.getB()
                              << ")" << std::endl;

                }else{
                    std::cout << "No canvas! Use 'new' first." << std::endl;
                }
            }else{
                std::cout << "Useage: drawLine" << std::endl;
            }

        }else if(cmd == "exit"){
            isRunning = false;
            std::cout<<"Goodbye!"<<std::endl;
        }else{
            std::cout<<"Unknow command. Please use command: help"<<std::endl;
        }
}

// Change all string to lower Case, but I don´t use It now; 
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

CommandInterface::~CommandInterface(){
    delete currentCanvas_;
    currentCanvas_ = nullptr;
}

