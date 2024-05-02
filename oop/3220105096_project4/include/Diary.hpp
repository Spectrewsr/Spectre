#ifndef _DIARY_H_
#define _DIARY_H_
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cctype>

class Diary
{
private:
    std::ofstream outfile; 

public:
    Diary();
    ~Diary();

    void add(std::string date);
    void list(std::string start, std::string);
    void show(std::string);
    int remove(std::string);
    int extractDayNumber(const std::string& dateStr) {
        std::string numStr;
        for (char c : dateStr) {
            if (std::isdigit(c)) {
                numStr.push_back(c);
            }
        }
        return std::stoi(numStr);
    }
};

#endif