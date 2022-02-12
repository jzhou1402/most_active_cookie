#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <getopt.h>
#include "read.h"

void getOptions(std::string& date, int argc, char* argv[]) {
	int gotopt;
	int option_index = 0;
	option long_opts[] = {
		{"date", required_argument, nullptr, 'd'},
		{"help", no_argument, nullptr, 'h'},
		{ nullptr, 0, nullptr, '\0' }
	};
	while ((gotopt = getopt_long(argc, argv, "d:h", long_opts, &option_index)) != -1) {
		switch (gotopt) {
		case 'd':
			date = optarg;
			break;
		case 'h':
			std::cout << "format: $ ./most_active_cookie <.csv file> -d <date>" << '\n';
			std::cout << "example: $ ./most_active_cookie cookie_log.csv -d 2018-12-08" << '\n';
			break;
		}
	}
}

void readParse(std::unordered_map<std::string, int>& cookies, std::string& date) {
	std::string line;
	std::ifstream readFile("cookie_log.csv");
	std::getline(readFile, line);

	while (std::getline(readFile, line)) {
		std::string cookie = "";
		size_t startTimeStamp = 0;
		for (size_t i = 0; i < line.size(); ++i) {
			if (line[i] == ',') {
				startTimeStamp = i + 1;
				break;
			}
			cookie.push_back(line[i]);
		}
		std::string timestamp = "";
		for (size_t i = startTimeStamp; i < line.size(); ++i) {
			if (line[i] == 'T') {
				break;
			}
			timestamp.push_back(line[i]);
		}
		if (timestamp == date) {
			cookies[cookie] += 1;
		}
	}
}