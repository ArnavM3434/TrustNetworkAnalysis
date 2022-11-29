/**
 * @file main.cpp
 * A simple program that allocates students to rooms.
 */


#include <vector>
#include <iostream>


#include "DataParsing.h"
#include "AdjList.h"
#include "BFS.h"


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

    BFS traversal(a);
    traversal.Traverse();
    //print first 50 nodes in traversal
    std::vector<int> & output = traversal.Output();
    for(int i = 0; i < output.size(); i++){
        std::cout << output[i] << std::endl;
    }

    return 0;
}