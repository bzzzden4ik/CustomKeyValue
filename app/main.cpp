#include "../include/commands.h"
#include "../include/database.h"
#include "../include/help.h"
#include "../include/init.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main (int argc, char* argv[]) {
    try {
        std::ifstream config("config.txt");
        std::string db_path_str; config >> db_path_str;
        int a, b;
        a = db_path_str.find("path:\"");
        b = db_path_str.find("\";", a + 6);
        if (a == -1 || b == -1) {
            throw std::invalid_argument("Wrong config.txt file recieved. Please check that config is filled correctrlly and locates at the top-directory level:\nCustomKeyValue\\\n  .\\app\n  .\\databases\n  .\\include\n  .\\src\n  config.txt <-- here is\n  README.md");
        }
        std::string db_path = db_path_str.substr(a + 6, b - a - 6);
        if (argc == 1) {
            throw std::invalid_argument("No command recieved. Use <help> to learn more.");
        }
        std::string command = std::move(argv[1]);
        argc = argc - 2;
        std::vector<std::string> args (argc);
        for (int i = 2; i < argc + 2; i++) {
            args[i - 2] = std::move(argv[i]);
        }
        if (command == "help") {
            printInfo(args);
            return 0;
        } else if (command == "manage") {
            printManage(db_path);
            return 0;
        } else if (command == "drop") {
            if (argc == 0) {
                throw std::invalid_argument("No parameters recieved. Use <help> <drop> to learn more about \"drop\".");
            }
            throw std::runtime_error("Developing...");
            return 0;
        } else if (command == "use") {
            if (argc == 0) {
                throw std::invalid_argument("No parameters recieved. Use <help> <use> to learn more about \"use\".");
            }
            if (!std::filesystem::exists(db_path + "/" + args[0])) {
                throw std::invalid_argument("No such database found.");
            }
            // Берём бд
            init(command, argc, args);
        } else if (command == "create") {
            if (argc == 0) {
                throw std::invalid_argument("No parameters recieved. Use <help> <create> to learn more about \"create\".");
            }
            if (std::filesystem::exists(db_path + "/" + args[0])) {
                throw std::invalid_argument("Database with name \"" + args[0] + "\"already exists");
            }
            // Создаём бд
            init(command, argc, args);
        } else {
            throw std::invalid_argument("Wrong command recieved. Use <help> to learn more");
        }
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}