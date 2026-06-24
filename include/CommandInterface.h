#pragma once

class CommandInterface{

    public:

    void run();

    std::string toLowerCase(std::string& input);
    std::string spacesOnly(std::string& input1);

    ~CommandInterface();
};