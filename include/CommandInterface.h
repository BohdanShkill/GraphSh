#pragma once

#include <vector>
#include <string>

class Canvas;

class CommandInterface{
    private:
    Canvas* curentCanvas_;

    std::vector<std::string> processCommand(const std::vector<std::string>& args);

    public:

    void run();

    std::string toLowerCase(const std::string& input);
    std::string spacesOnly(const std::string& input1);


    ~CommandInterface(){};
};