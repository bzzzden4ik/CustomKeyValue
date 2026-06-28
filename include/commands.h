#pragma once
#include <string>
#include "../include/database.h"

enum class Commands {
    help,
    use,
    drop,
    create
};
class ICommand {
private:
    std::string command;
    int paramsCount;
    std::string *params;
public:
    ICommand(const std::string& command, int paramsCount, std::string *params) {
        
    }
    virtual ~ICommand () {}
};
class OutCommand : public ICommand {
public:
    OutCommand(const std::string& command, int paramsCount, std::string *params) : ICommand(command, paramsCount, params) {}
};
class InnerCommand : public ICommand {
private:

};