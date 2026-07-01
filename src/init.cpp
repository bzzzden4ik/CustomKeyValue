#include "../include/init.h"
#include "../include/database.h"
#include "../include/commands.h"

void init (std::vector<std::string>& args, Database& db) {
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        std::istringstream str (line);
        std::string element;
        while (str >> element) {
            args.push_back(element);
        }
        if (args.size() != 0) {
            try {
                if (args[0] == "get") {
                    std::string value = db.get(args.at(1));
                } else if (args[0] == "set") {
                    db.set(args.at(1), args.at(2));
                    std::cout << "Pair pasted!\n";
                } else if (args[0] == "drop") {
                    db.drop(args.at(1));
                    std::cout << "Pair deleted!\n";
                } else {
                    std::cout << "Wrong command recieved. Use <help> to learn more.\n";
                }
            } catch(const std::out_of_range& e) {
                std::cerr << "Wrong parametr recieved. Use <help> to learn more.\n";
            }
        }
        args.clear();
    }
}