#include <unordered_map>
#include <vector>
#include <iostream>
#include <cassert>
#include <string>

#include "read.h"
#include "unit_test_framework.h"

using namespace std;

//a basic test for readParse
TEST(readParse) {
    unordered_map<string, int> cookies = {};
    unordered_map<string, int> correct = {
        {"AtY0laUfhglK3lC7" , 2},
        {"SAZuXPGUrfbcn5UA" , 1},
        {"5UAVanZf6UtGyKVS" , 1}
    };
    string date = "2018-12-09";
    readParse(cookies, date);
    ASSERT_EQUAL(cookies, correct);
}

TEST_MAIN()