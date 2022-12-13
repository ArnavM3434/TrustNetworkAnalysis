/**
 * @file main.cpp
 * Program that runs algorithms on a Trust Network
 */

#include <vector>
#include <iostream>
#include <fstream>

#include "DataParsing.h"
#include "AdjList.h"
#include "BFS.h"
#include "Test.h"
#include "PageRank.h"

/**
 * Main routine for the Trust Network Project
 */
int main()
{
	std::ofstream ofs;
	ofs.open("output.txt", std::ofstream::out | std::ofstream::trunc);

	ofs<<"------------------------------";
	ofs<<"\n";

	//Set a low number that kees runtime low and is easily readable
	int setMaxNodes = 25;

	//Factors that can be changes as desired
	int bfsStartNode = 0;
	double dampingFactor = 0.85;
	int numPowerIter = 100;
	bool restartRank = true;

	std::cout<<"----------"<<std::endl;
	std::cout<<"Running Algorithms on Bigger Dataset!"<<std::endl;

	//Data Parsing
	DataParsing parseData(0);
	V2D cleanedNodes = parseData.getNodes("Dataset/soc-Epinions1.txt", setMaxNodes);
	int numLinClean = parseData.getNumLinesCleaned();
	int numEdgeClean = parseData.getNumEdgesCleaned();
	int numNodeClean = parseData.getNumNodesCleaned();
	ofs<<"Cleaned "<<numLinClean<<" lines from the data set";
	ofs<<"\n";
	ofs<<"Number of Nodes: "<<numNodeClean<<"\t"<<"Number of Edges: "<<numEdgeClean;
	ofs<<"\n";

	//Get Adjacency List
	AdjList dataAdjList(cleanedNodes, setMaxNodes);

	//Run BFS
	BFS bfsTraversal(dataAdjList);
	bfsTraversal.Traverse(bfsStartNode);
	std::vector<int>& bfsTraversalOutput = bfsTraversal.Output();
	ofs<<"\n";
	ofs<<"BFS Traversal Starting at Node "<<bfsStartNode<<":";
	ofs<<"\n";
	ofs<<bfsTraversalOutput[0];
	int newLineCount = 1;
	for(int i = 1; i < setMaxNodes; i++){
		ofs<<" --> ";
		if(newLineCount % 10 == 0) {
			ofs<<"\n";
		}
		ofs<<bfsTraversalOutput[i];
		newLineCount++;
	}
	ofs<<"\n";

	//Run Page Rank
	PageRank currPageRank(dataAdjList, dampingFactor);
	currPageRank.runPageRank(numPowerIter, restartRank);
	std::vector<std::vector<std::string>> dataPageRank = currPageRank.getPageRank();
	ofs<<"\n";
	ofs<<"Page Rank Results:";
	ofs<<"\n";
	for(auto iter : dataPageRank) {
		ofs<<"Node: "<<iter[0]<<",\tRank: "<<iter[1];
		ofs<<"\n";
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
	ofs<<"Node with highest Rank: "<<currMax;
	ofs<<"\n";

	//Run Betweenness Centrality
	BetweennessCentrality betweenness(dataAdjList);
	unsigned int mostImportant = betweenness.mostImportant;
	ofs<<"\n";
	ofs<<"Betweenness Centrality Test: ";
	ofs<<"\n";
	ofs<<"Most Important Node: "<<mostImportant;
	ofs<<"\n";

	std::cout<<"Output of algorithms are in output.txt"<<std::endl;
	std::cout<<"----------"<<std::endl;

	//Test Cases
	std::cout<<"Now Running Smaller Tests on Smaller Graph!"<<std::endl;
	test(1);

	ofs<<"------------------------------";

	std::cout<<"----------"<<std::endl;

	ofs.close();

	return 0;
}