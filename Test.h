#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "DataParsing.h"
#include "AdjList.h"
#include "BFS.h"
#include "Test.h"
#include "PageRank.h"
#include "BetweennessCentrality.h"

/**
 * test is a function that is used to test the working capacity of our functions
 * @param testNumber is the testNumber that we want to run;
 * @return bool which is true if test casses pass and false otherwise
 */
bool test(int testNumber);

/**
 * testHelper is a helper function that takes in the file with the test data and test all functions
 * that we have implemented
 * @param filename The name of the file that holds the test data
 * @return bool which is true if test casses pass and false otherwise
 */
bool testHelper(const std::string & filename);