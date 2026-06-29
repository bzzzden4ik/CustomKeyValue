#pragma once
#include <string>
#include <vector>
#include "../include/database.h"

class ICommand {
protected:
    std::string command;
    int paramsCount;
    std::string *params;
    ICommand *inputer = nullptr;
public:
    ICommand(const std::string& command, int paramsCount, std::string *params) {
        
    }
    virtual ~ICommand () {}
};
class OutCommand : public ICommand {
public:
    OutCommand(const std::string& command, int paramsCount, std::string *params) : ICommand(command, paramsCount, params) {
        
    }
    bool help () {

    }
    Database createDb() {

    }
    Database useDb() {

    }
    bool dropDb() {

    }
    std::vector<std::string> anage() {

    }
};
class InnerCommand : public ICommand {
private:
    InnerCommand(const std::string& command, int paramsCount, std::string *params) : ICommand(command, paramsCount, params) {
        
    }
};