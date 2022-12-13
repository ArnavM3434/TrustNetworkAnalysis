#pragma once

#include "DataParsing.h"
#include "AdjList.h"
#include "BFS.h"
#include <vector>


class BetweennessCentrality{

    public:
	/*
	* This constructor handles the Betweenness Centrality Algorithm. It relies
	* on a BFS traversal to find the shortest path. It updates the class level
	* variable "MostImportant" with the node that has the most paths running through
	* it.
	* @param graph The graph dataset we are running Page Rank on
	*/
    BetweennessCentrality(AdjList graph);

    /*
    * Public variable for most important node
    */
    unsigned int mostImportant;

    /*
    * Vector that holds how many paths pass through node i at index i
    */
    std::vector<unsigned int> scores;


    private:
};