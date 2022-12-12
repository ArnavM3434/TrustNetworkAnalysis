#pragma once

#include "DataParsing.h"
#include "AdjList.h"
#include "BFS.h"
#include <vector>


class BetweennessCentrality{

    public:
    /*
    * BetweennessCentrality constructor takes an adjacency list as an input, and runs
    * the Betweenness Centrality Algorithm to find the node in the network
    * which has the most nodes running through it.
    */
    BetweennessCentrality(AdjList graph);

    /*
    * Public variable for most important node
    */
    int mostImportant;

    /*
    * Vector that holds how many paths pass through node i at index i
    */
    std::vector<int> scores;



   

    private:

   




};