#include "PageRank.h"

PageRank::PageRank(AdjList graph) {
	V2D currAdjList = graph.getAdjListFrom();
	int numMaxNodes = graph.getMaxNode();
	V2D tempAdjMat;
	std::vector<std::vector<double>> tempMarkovMatrix;
	numNodes_ = numMaxNodes;

	//Convert adjacency list into adjacency matrix
	for(int i = 0; i < numNodes_; i++) {
		std::vector<int> tempAdjRow{std::vector<int>(numNodes_, 0)};
		std::vector<double> tempMarkRow{std::vector<double>(numNodes_, 0.0)};
		for(int j = 0; j < static_cast<int>(currAdjList[i].size()); j++) {
			tempAdjRow[currAdjList[i][j]] = 1;
			tempMarkRow[currAdjList[i][j]] = 1.0;
		}
		tempAdjMat.push_back(tempAdjRow);
		tempMarkovMatrix.push_back(tempMarkRow);
	}

	adjMat_ = tempAdjMat;
	//Initialize Markov Matrix with 1/di where di is the outdegree of vertex i
	for(int col = 0; col < static_cast<int>(adjMat_.size()); col++) {
		int degreeI = 0;
		for(int row = 0; row < static_cast<int>(adjMat_.size()); row++) {
			degreeI += adjMat_[row][col];
		}
		if(degreeI == 0) {
			//no outgoing trust so initalize all outgoing as 1/number of nodes
			for(int row = 0; row < static_cast<int>(adjMat_.size()); row++) {
				tempMarkovMatrix[row][col] = (1/numNodes_);
				std::cout<<"here"<<std::endl;
			}
		} else if(degreeI > 0) {
			for(int row = 0; row < static_cast<int>(adjMat_.size()); row++) {
				if(tempMarkovMatrix[row][col] > 0.0) {
					tempMarkovMatrix[row][col] = (1/degreeI);
				}
			}
		}
	}
	markovMatrix_ = tempMarkovMatrix;
	std::cout<<"PageRank initialized"<<std::endl;
	for(size_t i = 0; i < adjMat_.size(); i++) {
        for(size_t j = 0; j < adjMat_.size(); j++) {
            std::cout<< adjMat_[i][j];
            std::cout<<" ";	
        }
        std::cout<<"\n";
    }
    std::cout<<"Done\n";
	for(size_t i = 0; i < markovMatrix_.size(); i++) {
        for(size_t j = 0; j < markovMatrix_.size(); j++) {
            std::cout<< markovMatrix_[i][j];
            std::cout<<" ";	
        }
        std::cout<<"\n";
    }
    std::cout<<"Done\n";
}

void PageRank::runPageRank(int numPower) {
	return;
}

std::vector<std::vector<std::string>> PageRank::getPageRank() {
	std::vector<std::vector<std::string>> toReturn = {{"Hold"}};
	return toReturn;
}