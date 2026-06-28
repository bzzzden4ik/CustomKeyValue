#include "../include/commands.h"
#include "../include/database.h"
#include "../include/help.h"
#include <fstream>
#include <string>
#include <iostream>

int main (int argc, char* argv[]) {
    int paramsCount = argc > 2 ? argc - 2 : 0;
    std::string *params = paramsCount ? new std::string[paramsCount] : nullptr;
    for (int i = 2; i < argc; i++) {
        
    }
    return 0; 
}