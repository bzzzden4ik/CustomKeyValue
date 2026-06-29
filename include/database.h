#pragma once
#include <string>
#include <fstream>
#include <unordered_map>

class Database {
private:
    std::ifstream dbstream;
    std::string name;
    std::unordered_map<std::string, int> table;
public:
    Database(std::ifstream& file, const std::string& name) {

    }
    std::string get() {
        
    }
    bool set() {

    }
    bool drop() {

    }
    ~Database() {}
};