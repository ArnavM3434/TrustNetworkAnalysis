#pragma once

#include "DataParsing.h"
#include "AdjList.h"
#include "BFS.h"

#include <vector>

class PageRank {
	public:
	/**
	 * PageRank is a cuntructor that convert the given graph's adjacency list into an 
	 * adjacency matrix, creates and initializes the markov matrix, and creates the 
	 * initial rank of the graph
	 * @param graph The graph dataset we are running Page Rank on
	 * @param dampingFactor The damping factor used to calculate page rank
	 */
	PageRank(AdjList graph, double dampingFactor);

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
	std::vector<std::vector<std::string>> runPageRank(int numPower, bool reset);

	/**
	 * getPageRank returns the current page rank of the graph that has already been calculated
	 * @return a two dimensional vector of strings of the current page rank
	 */
	std::vector<std::vector<std::string>> getPageRank();

	/**
	 * getMarkovMatrix returns the Markov Matrix that was caluclated for the graph for which
	 * the current page rank object was created for
	 * @return a two dimensional vector of doubles of the Markov Matrix
	 */
	std::vector<std::vector<double>> getMarkovMatrix();

	/**
	 * getRank returns the current page rank of the graph that has already been calculated
	 * @return a one dimensional vector of doubles
	 */
	std::vector<double> getRank();


	private:
	/**
	 * powerIteration is a helper function that is used to computer one power iteration 
	 * on the current page rank
	 * @return void
	 */
	void powerIteration();

	/**
	 * setPageRank is a helper function that is used to convert the internal page rank
	 * vector into a 2 dimensional vector of strings to that the results of the page rank 
	 * can be exported and displayed easily
	 * @return void
	 */
	void setPageRank();

	/**
	 * adjMat_ is the adjacency matrix created from the adjacnecy from list for the graph
	 * for which the page rank object was created for
	 */
	V2D adjMat_;

	/**
	 * markovMatrix_ stores the computed markov matrix
	 */
	std::vector<std::vector<double>> markovMatrix_;

	/**
	 * currPageRank_ stores the current computed page rank
	 */
	std::vector<double> currPageRank_;

	/**
	 * initialRank_ stores the initial page rank of the graph with zero power iterations
	 */
	std::vector<double> initialRank_;

	/**
	 * pageRank_ stores the page rank output that can easily be exported and displayed
	 */
	std::vector<std::vector<std::string>> pageRank_;

	/**
	 * numNodes_ stores the number of nodes in the current graph
	 */
	int numNodes_;

	/**
	 * dampingFactor_ stores the damping factor used in the computation of the page rank
	 */
	double dampingFactor_;
};