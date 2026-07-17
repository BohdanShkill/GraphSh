#pragma once
#include <Canvas.h>

class CommandInterface{
    private:
    Canvas* currentCanvas_;

    void processCommand(const std::vector<std::string>& args);

    public:
    CommandInterface();

    void run();

    std::string toLowerCase(std::string& input);
    std::string spacesOnly(std::string& input1);

    

    ~CommandInterface();
};