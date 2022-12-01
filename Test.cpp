#include "Test.h"


bool test(int testNumber) {
    std::vector<std::string> testHold;
    std::string testOne = "Tests/TestOne.txt";
    //Add tests strings as more tests are added
    testHold.push_back(testOne);
    return testHelper(testHold[testNumber]);
}

bool testHelper(const std::string & filename) {
    return true;
}