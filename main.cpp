/**
 * @file main.cpp
 * Program that runs algorithms on a Trust Network
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
    std::cout<<"------------------------------"<<std::endl;
	//set any number between 1-10 to get output that is easily readable
	int setMaxNodes = 200;

	//Factors that can be changes as desired
	int bfsStartNode = 0;
	double dampingFactor = 0.85;
	int numPowerIter = 100;
	bool restartRank = true;

    std::cout<<"Running Algorithms on Bigger Dataset!"<<std::endl;

    //Data Parsing
    V2D cleanedNodes = getNodes("Dataset/soc-Epinions1.txt", setMaxNodes);
	std::cout<<"\n";
    std::cout<< std::to_string(setMaxNodes) + " lines of cleaned data set:"<<std::endl;
    for(int i = 0; i < setMaxNodes; i++){
         std::cout<<std::to_string(cleanedNodes[i][0]) + " " + std::to_string(cleanedNodes[i][1])<<std::endl;
    }

    //Get Adjacency List
    AdjList dataAdjList(cleanedNodes, setMaxNodes);

    //Run BFS
    BFS bfsTraversal(dataAdjList);
    bfsTraversal.Traverse(bfsStartNode);
    std:vector<int>& bfsTraversalOutput = bfsTraversal.Output();
	std::cout<<"\n";
    std::cout<<"BFS Traversal Starting at Node " + std::to_string(bfsStartNode) + ":"<<std::endl;
	std::cout<<bfsTraversalOutput[0];
	int newLineCount = 1;
    for(int i = 1; i < setMaxNodes; i++){
		std::cout<<" --> ";
		if(newLineCount % 10 == 0) {
			std::cout<<"\n";
		}
        std::cout<<bfsTraversalOutput[i];
		newLineCount++;
    }
	std::cout<<"\n";
    
	//Run Page Rank
	PageRank currPageRank(dataAdjList, dampingFactor);
	currPageRank.runPageRank(numPowerIter, restartRank);
	std::vector<std::vector<std::string>> dataPageRank = currPageRank.getPageRank();
	std::cout<<"\n";
	std::cout<<"Page Rank Results:"<<std::endl;
	for(auto iter : dataPageRank) {
		std::cout<<"Node: " + iter[0] + ", Rank: " + iter[1]<<std::endl;
	}
	std::vector<double> calcRank = currPageRank.getRank();
	double maxRank = calcRank[0];
	int currMax = 0;
	for(int i = 0; i < static_cast<int>(calcRank.size()); i++) {
		if(calcRank[i] > maxRank) {
			maxRank = calcRank[0];
			currMax = i;
		}
	}
	std::cout<<"Node with highest Rank: " + std::to_string(currMax);
    
    //run Betweenness Centrality
    BetweennessCentrality betweenness(dataAdjList);
    unsigned int mostImportant = betweenness.mostImportant;
    std::cout<<std::endl;
	std::cout<<"\n";
    std::cout<<"Betweenness Centrality Test: "<<std::endl;
    std::cout<<"Most Important Node: "<<mostImportant<<std::endl;
    
    
    //Test Cases
	std::cout<<"\n";
    std::cout<<"Now Running Smaller Tests on Smaller Graph!"<<std::endl;
    test(1);

	std::cout<<"------------------------------"<<std::endl;
    return 0;
}