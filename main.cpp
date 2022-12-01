/**
 * @file main.cpp
 * A simple program that allocates students to rooms.
 */


#include <vector>
#include <iostream>


#include "DataParsing.h"
#include "AdjList.h"
#include "BFS.h"
#include "Test.h"

using namespace std;
/**
 * Main routine for the Trust Network Project
 */
int main()
{
    int setMaxNodes = 10000;
    V2D cleanedNodes = getNodes("Dataset/soc-Epinions1.txt", setMaxNodes);
    std::cout<<"First 10 lines of cleaned data set:"<<std::endl;
    for(int i = 0; i < 10; i++){
         std::cout<<std::to_string(cleanedNodes[i][0]) + " " + std::to_string(cleanedNodes[i][1])<<std::endl;
    }
    AdjList dataAdjList(cleanedNodes, setMaxNodes);
    int bfsStartNode = 0;
    BFS bfsTraversal(dataAdjList);
    bfsTraversal.Traverse(bfsStartNode);
    std:vector<int>& bfsTraversalOutput = bfsTraversal.Output();
    std::cout<<"Portion of Traversal Starting at Node " + std::to_string(bfsStartNode) + ":"<<std::endl;
    for(int i = 0; i < 9; i++){
         std::cout<<bfsTraversalOutput[i]<<std::endl;
    }
    std::cout<<"Completed Part One"<<std::endl;
    
    std::cout<<"Now Running Tests!"<<std::endl;
    
    test(1);


    // V2D inputNodes = getNodes("Dataset/soc-Epinions1.txt", setMaxNodes);
    // std::cout << "" << std::endl;
    // AdjList a(inputNodes, 5);
    // a.print();

    // int num = a.getMaxNode();
    // std::cout << "Expected Max Node: " << 5 << std::endl;
    // std::cout << "Max Node: " << num << std::endl;

    // BFS traversal(a);
    // traversal.Traverse();
    // //print first 5 nodes in traversal
    // std::cout << "Expected Traversal Order: " << 0 << 1 << 4 << 3 << 2 << std::endl;

    // std::vector<int> & output = traversal.Output();
    // for(int i = 0; i < output.size(); i++){
    //     std::cout << output[i] << std::endl;
    // }

    // return 0;
}

// TEST_CASE("BFS Test", "[weight=2][part=1]") 
// {
//     std::vector<std::vector<int>> vect
//     {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };

//     REQUIRE(1 == 1);

// }