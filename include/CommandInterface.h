#pragma once
#include <Canvas.h>

#include <vector>
#include <string>

class Canvas;

class CommandInterface{
    private:
    Canvas* currentCanvas_;

    void processCommand(const std::vector<std::string>& args);

    public:
    CommandInterface();

    void run();

    std::string toLowerCase(const std::string& input);
    std::string spacesOnly(const std::string& input1);


    

    ~CommandInterface();
};