#include "../include/init.h"
#include "../include/database.h"
#include "../include/commands.h"

void init (std::vector<std::string>& args) {
    return;
    while (true) {
        std::string line; std::getline(std::cin, line);
        std::istringstream str;
        std::string element;
        while (str >> element) {
            args.push_back(element);
        }
        
    }
}