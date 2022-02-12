#include <unordered_map>
#include <vector>
#include <iostream>
#include <cassert>
#include <string>

#include "algorithms.h"
#include "unit_test_framework.h"

using namespace std;

//a basic test for maxElements
TEST(maxElements) {
    unordered_map<string, int> cookies = {
        {"cookie", 32},
        {"brownie", 24},
        {"cupcake", 43},
        {"cake", 43},
        {"other", 42},
    };
    vector<string> empty = {};
    vector<string> output = { "cupcake", "cake" };
    maxElements(cookies, empty);
    ASSERT_EQUAL(empty, output);
}

TEST_MAIN()