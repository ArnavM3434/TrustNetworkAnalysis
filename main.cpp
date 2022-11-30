/**
 * @file main.cpp
 * A simple program that allocates students to rooms.
 */


#include <vector>
#include <iostream>


#include "DataParsing.h"
#include "AdjList.h"
#include "BFS.h"

using namespace std;
/**
 * Main routine for the Trust Network Project
 */
int main()
{
    // const std::vector<std::vector<int>> & vect
    // {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };
    // AdjList peep(vect, 5);
    

    V2D inputNodes = getNodes();
    std::cout << "" << std::endl;
    AdjList a(inputNodes, 5);
    a.print();

    int num = a.getMaxNode();
    std::cout << "Max Node: " << num << std::endl;

    BFS traversal(a);
    traversal.Traverse();
    //print first 50 nodes in traversal
    std::vector<int> & output = traversal.Output();
    for(int i = 0; i < output.size(); i++){
        std::cout << output[i] << std::endl;
    }



    return 0;
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