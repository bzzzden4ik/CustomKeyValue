#include "../include/help.h"
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

void printInfo(const std::vector<std::string>& args) {
    std::string text;
    if (args.size() != 0) {
        if (args[0] == "create") {
            text = "create - used to create new database. After that it get you in database command shell. Flags:\n<db_name> set your database name (Necessarily).\n<value type> set type of values in your database (Necessarily).\n<custom_location> allows to create database in your custom location (optional). By default db creates at config setted directory.";
        } else if (args[0] == "use") {
            text = "use - used to enter database shell. After that it get you in database command shell. Flags:\n<db_name> your database name (Necessarily).\n<custom_location> allows to use database in your custom location (optional). By default db chosen at config setted directory.";
        } else if (args[0] == "drop") {
            text = "not ready... yet";
        } else if (args[0] == "manage") {
            text = "manage - get list of existing databases in chosen directory. Flags:\n<custom_location> allows check dbs in chosen location (optional). Checks config path by default";
        } else {
            text = "Call compiled file with next flags:\n1. create <db_name> <value_type> <custom_location>\n\t1.1. get <key>\n\t1.2. set <key> <value>\n\t1.3. drop <key>\n2. use <db_name> <custom_location>\n\t2.1. get <key>\n\t2.2. set <key> <value>\n\t2.3. drop <key>\n3. drop <db_name> <custom_location>\n4. manage <custom_location>\n5. help <command>";
        }
    } else {
        text = "Call compiled file with next flags:\n1. create <db_name> <value_type> <custom_location>\n\t1.1. get <key>\n\t1.2. set <key> <value>\n\t1.3. drop <key>\n2. use <db_name> <custom_location>\n\t2.1. get <key>\n\t2.2. set <key> <value>\n\t2.3. drop <key>\n3. drop <db_name> <custom_location>\n4. manage <custom_location>\n5. help <command>";
    }
    std::cout << text;
}
void printManage(const std::string& db_path) {
    if (!std::filesystem::exists(db_path) || !std::filesystem::is_directory(db_path)) {
        throw std::invalid_argument("Nothing found in " + db_path);
    }
    bool found = false;
    for (const auto& entry : std::filesystem::directory_iterator(db_path)) {
        if (entry.is_regular_file() && entry.path().extension() == ".cdb") {
            std::cout << entry.path().filename().string() << std::endl;
            found = true;
        }
    }
    if (!found) {
        throw std::invalid_argument("Nothing found in " + db_path);
    }
}