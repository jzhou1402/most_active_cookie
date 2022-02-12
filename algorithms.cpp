#include <string>
#include <vector>
#include <unordered_map>
#include "algorithms.h"

void maxElements(std::unordered_map<std::string, int> cookies, std::vector<std::string>& output) {
	// find the max frequency
	int maxCount = 0;
	for (auto i : cookies) {
		if (maxCount < i.second) {
			maxCount = i.second;
		}
	}
	// push all elements with max frequency into array
	for (auto i : cookies) {
		if (i.second == maxCount) {
			output.push_back(i.first);
		}
	}
}