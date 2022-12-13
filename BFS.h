#pragma once
#include <iostream>
#include <vector>
#include "AdjList.h"
#include "DataParsing.h"


class BFS{
    public:
    /**
     * BFS constructor that will build an object on which we can run the traversal on
     * @param graph is the adjacency list that will be running BFS traversal on
     */
    BFS(AdjList graph);

    /**
     * Traverse is the function which runs BFS on the given BFS object
     * @param startNode is the starting node for BFS traversal
     * @return void
     */
    void Traverse(int startNode);

    /**
     * Explore is a helper function for Traverse that is used to explore the neighbors of
     * the given vertex
     * @param v is the current vertex of the graph to explore by looking at its neighbors
     * @return void
     */
    void Explore(int v);

    /**
    * Traversal path from specified starting node to ending node taken by BFS
    * @param v is starting node
    * @param e is ending node
    * @return void
    */
     void Explore(int v, int e);

    /**
     * Output returns the traversal path taken by BFS
     * @return std::vector<int> returns the vector that holds the path taken by the traversal
     */

    std::vector<int> & Output();

    /**
    * Return vector consisting of nodes in the shortest path between start and end
    * @return std::vector<int> &
    * @param int start
    * @param int end
    */
    std::vector<int> & returnPred(int end, int start);


    private:
    /**
     * visitedNodes is the vector of booleans that holds if a vertex is visited and helps
     * during the traversal
     */
    std::vector<bool> visitedNodes;

    /**
     * traversalOutput is a vector of ints that holds the path taken by the traversal
     */
    std::vector<int> traversalOutput;

    /*
     * traversalIndex is the current number nodes visited. It helps keep track of where
     * in the path the traversal is currently at
     */
    int traversalIndex;

    /**
     * Vector representing each node's predeccessor in a BFS traversal from a start node to an end node
     */
    std::vector<int> pred;

    /**
     * variable representing shortest path between start and ending nodes
     */
    std::vector<int> path;

    /**
     * adjlist_ is a 2D vector of ints that holds the adjacency list of the graph that the
     * traversal is called on
     */
    V2D adjlist_;
};