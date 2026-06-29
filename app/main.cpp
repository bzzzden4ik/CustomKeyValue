#include "../include/commands.h"
#include "../include/database.h"
#include "../include/help.h"
#include <fstream>
#include <string>
#include <iostream>

int main (int argc, char* argv[]) {
    try {
        std::ifstream config("../config.txt");
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    if (argc == 1) {
        std::cout << "Ooops! Nothing recieved... Use <help> to learn more\n";
        return 0;
    }
    int paramsCount = argc > 2 ? argc - 2 : 0;
    std::string *params = paramsCount ? new std::string[paramsCount] : nullptr;
    for (int i = 2; i < argc; i++) {
        params[i] = argv[i];
    }
    ICommand *inputCommand = new OutCommand (argv[1], paramsCount, params);
    // delete inputCommand; - удаление старого контекста
    // inputCommand = new InnerCommand(); - создание нового контекста
    return 0;
}