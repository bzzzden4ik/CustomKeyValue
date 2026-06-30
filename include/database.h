#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

// T/0\\M!B<S>T0!N_3

class Database {
private:
    std::ifstream idbstream;
    std::ofstream odbstream;
    std::string path;
    std::unordered_map<std::string, std::string> table;
public:
    Database(const std::string& path) : idbstream(path) {
        // Инициализация map
        this->path = path;
        std::string line;
        while (std::getline(idbstream, line)) {
            int start = 0, end = line.find(';');
            while (end != -1) {
                std::string pair = line.substr(start, end - start);
                int split = pair.find(':');
                std::string key = pair.substr(0, split), value = pair.substr(split + 1, pair.length() - split - 1);
                if (value != "T/0\\M!B<S>T0!N_3") {
                    table[key] = value;
                } else {
                    table.erase(key);
                }
                start = end + 1;
                end = line.find(';', start);
            }
        }
        idbstream.close();
        odbstream = std::ofstream(path, std::ios::app);
    }
    std::string get(const std::string& key) {
        return table.at(key);
    }
    void set(const std::string& key, const std::string& value) {
        table[key] = value;
        odbstream << key << ":" << value << ";";
        odbstream.flush();
    }
    void drop(const std::string& key) {
        table.erase(key);
        odbstream << key << ":T/0\\M!B<S>T0!N_3;";
        odbstream.flush();
    }
    ~Database() {
        odbstream.close();
        std::string tempPath = path + ".tmp";
        std::ofstream newOut(tempPath);
        if (newOut.is_open()) {
            for (const auto& [key, value] : table) {
                newOut << key << ":" << value << ";";
            }
            newOut.close();
            std::remove(path.c_str());
            std::rename(tempPath.c_str(), path.c_str());
        }
    }
};