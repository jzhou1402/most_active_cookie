#ifndef READ_H
#define READ_H

#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>

void getOptions(std::string& date, int argc, char* argv[]);

void readParse(std::unordered_map<std::string, int>& cookies, std::string& date);

#endif