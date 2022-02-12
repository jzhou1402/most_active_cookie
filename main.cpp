//most active cookie

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "algorithms.h"
#include "read.h"

using namespace std;

int main(int argc, char* argv[]) {
	//getting selected date from command line
	string date;
	getOptions(date, argc, argv);

	//reading cookies into map given date
	//unordererd map: O(n) vs. vector: O(n log n) for the maxElements function
	unordered_map<string, int> cookies;
	readParse(cookies, date);

	//storing frequent cookies in output
	vector<string> output;
	maxElements(cookies, output);
	
	for (string& i : output) {
		cout << i << endl;
	}
}

