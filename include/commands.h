#pragma once
#include <string>
#include <vector>

class CommandsShell {
private:
    std::string command;
    int argc;
    std::vector<std::string> args;
public:
    CommandsShell() {}
};