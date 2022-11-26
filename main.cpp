/**
 * @file main.cpp
 * A simple program that allocates students to rooms.
 */


#include <vector>
#include <iostream>


#include "DataParsing.h"
#include "AdjList.h"


/**
 * Main routine for the Trust Network Project
 */
int main()
{
    std::cout << "Hello World\n";
    V2D inputNodes = getNodes();
    std::cout << "" << std::endl;
    AdjList a(inputNodes, 500);
    // a.print();
}