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
#include "PageRank.h"

using namespace std;
/**
 * Main routine for the Trust Network Project
 */
int main()
{
    int setMaxNodes = 10;

    //Data Parsing
    V2D cleanedNodes = getNodes("Dataset/soc-Epinions1.txt", setMaxNodes);
	std::cout<<"\n";
    std::cout<<"First 10 lines of cleaned data set:"<<std::endl;
    for(int i = 0; i < 10; i++){
         std::cout<<std::to_string(cleanedNodes[i][0]) + " " + std::to_string(cleanedNodes[i][1])<<std::endl;
    }

    //Get Adjacency List
    AdjList dataAdjList(cleanedNodes, setMaxNodes);

    //Run BFS
    int bfsStartNode = 0;
    BFS bfsTraversal(dataAdjList);
    bfsTraversal.Traverse(bfsStartNode);
    std:vector<int>& bfsTraversalOutput = bfsTraversal.Output();
	std::cout<<"\n";
    std::cout<<"Portion of Traversal Starting at Node " + std::to_string(bfsStartNode) + ":"<<std::endl;
    for(int i = 0; i < 9; i++){
         std::cout<<bfsTraversalOutput[i]<<std::endl;
    }

	//Run Page Rank
	double dampingFactor = 0.85;
	PageRank currPageRank(dataAdjList, dampingFactor);
	currPageRank.runPageRank(10, true);
	std::vector<std::vector<std::string>> dataPageRank = currPageRank.getPageRank();
	std::cout<<"\n";
	std::cout<<"Page Rank Results:"<<std::endl;
	for(auto iter : dataPageRank) {
		std::cout<<"Node: " + iter[0] + ", Rank: " + iter[1]<<std::endl;
	}
    
    //Test Cases
	std::cout<<"\n";
    std::cout<<"Now Running Tests!"<<std::endl;
    test(1);

    return 0;
}