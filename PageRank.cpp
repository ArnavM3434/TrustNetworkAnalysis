#include "PageRank.h"


/**
 * PageRank is a cuntructor that convert the given graph's adjacency list into an 
 * adjacency matrix, creates and initializes the markov matrix, and creates the 
 * initial rank of the graph
 * @param graph The graph dataset we are running Page Rank on
 * @param dampingFactor The damping factor used to calculate page rank
 */
PageRank::PageRank(AdjList graph, double dampingFactor) {
	dampingFactor_ = dampingFactor;
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
				tempMarkovMatrix[row][col] = (1.0/numNodes_);
			}
		} else if(degreeI > 0) {
			//if outoing edge then intialize with 1/di
			for(int row = 0; row < static_cast<int>(adjMat_.size()); row++) {
				if(tempMarkovMatrix[row][col] > 0.0) {
					tempMarkovMatrix[row][col] = (1.0/degreeI);
				}
			}
		}
	}
	markovMatrix_ = tempMarkovMatrix;

	//set initial rank vector
	for(int row = 0; row < numNodes_; row++) {
		double currTotal = 0.0;
		for(int col = 0; col < numNodes_; col++) {
			currTotal+=markovMatrix_[row][col];
		}
		double baseRank = (1.0/numNodes_);
		double addDamping = ((1-dampingFactor_)/numNodes_) + (dampingFactor_ * (currTotal * baseRank));
		initialRank_.push_back(addDamping);
		currPageRank_.push_back(addDamping);
	}
	//initialize return vector of strings
	setPageRank();
}


/**
 * runPageRank is a public function that is called then the user wants to run the page
 * rank algorithm on the graph for which the page rank object was created for
 * @param numPower The number of power iterations we want to run on the graph
 * @param reset A boolean that determines if we want to run the power iterations from 
 * the inital rank or from the previous page rank that was calculated the last time the
 * page rank algorithm was run on the graph
 * @return a two dimentional vector of strings that holds the node and its corresponding rank
 * in each vector
 */
std::vector<std::vector<std::string>> PageRank::runPageRank(int numPower, bool reset) {
	if(reset) {
		for(size_t change = 0; change < currPageRank_.size(); change++) {
			currPageRank_[change] = initialRank_[change];
		}
	}

	for(int numIter = 0; numIter < numPower; numIter++) {
		powerIteration();
		setPageRank();
	}

	return pageRank_;
}


/**
 * getPageRank returns the current page rank of the graph that has already been calculated
 * @return a two dimensional vector of strings of the current page rank
 */
std::vector<std::vector<std::string>> PageRank::getPageRank() {
	return pageRank_;
}


/**
 * getMarkovMatrix returns the Markov Matrix that was caluclated for the graph for which
 * the current page rank object was created for
 * @return a two dimensional vector of doubles of the Markov Matrix
 */
std::vector<std::vector<double>> PageRank::getMarkovMatrix() {
	return markovMatrix_;
}


/**
 * getRank returns the current page rank of the graph that has already been calculated
 * @return a one dimensional vector of doubles
 */
std::vector<double> PageRank::getRank() {
	return currPageRank_;
}


/**
 * powerIteration is a helper function that is used to computer one power iteration 
 * on the current page rank
 * @return void
 */
void PageRank::powerIteration() {
	std::vector<double> tempPageRank_;
	for(int row = 0; row < numNodes_; row++) {
		double matrixMultiplication = 0;
		for(int col = 0; col < numNodes_; col++) {
			matrixMultiplication += (markovMatrix_[row][col] * currPageRank_[col]);
		}
		double addDamping = ((1-dampingFactor_)/numNodes_) + (dampingFactor_ * matrixMultiplication);
		tempPageRank_.push_back(addDamping);
	}
	for(size_t change = 0; change < currPageRank_.size(); change++) {
		currPageRank_[change] = tempPageRank_[change];
	}
	return;
}


/**
 * setPageRank is a helper function that is used to convert the internal page rank
 * vector into a 2 dimensional vector of strings to that the results of the page rank 
 * can be exported and displayed easily
 * @return void
 */
void PageRank::setPageRank() {
	std::vector<std::vector<std::string>> rankVect;
	for(int setRank = 0; setRank < static_cast<int>(currPageRank_.size()); setRank++) {
		std::vector<std::string> nodeRank;
		nodeRank.push_back(std::to_string(setRank));
		nodeRank.push_back(std::to_string(currPageRank_[setRank]));
		rankVect.push_back(nodeRank);
	}
	pageRank_ = rankVect;
	return;
}