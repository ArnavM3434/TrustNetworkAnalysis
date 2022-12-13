#include "AdjList.h"

/**
 * AdjList is a constructor that stores the object for the adjacency lists
 * @param dataset is a 2D vector of ints that stores the cleaned nodes
 * @param maxNode The number of nodes 
 */
AdjList::AdjList(const V2D & dataset, int maxNode) {
    V2D adjlistFrom;
    V2D adjlistTo;
    adjlistFrom.resize(maxNode);
    adjlistTo.resize(maxNode);
    for (std::vector<int> nodePair : dataset) {
        int fromNode = nodePair[0];
        int toNode = nodePair[1];
        adjlistFrom[toNode].push_back(fromNode);
        adjlistTo[fromNode].push_back(toNode);
    }
    adjlistFrom_ = adjlistFrom;
    adjlistTo_ = adjlistTo;
    maxNode_ = maxNode;
}


/**
 * printFrom prints the from adjacency list
 * @return void
 */
void AdjList::printFrom() {
    for (int i = 0; i < maxNode_; i++) {
        std::cout << i << " <- ";
        for (int node : adjlistFrom_[i]) {
            std::cout << node << " ";
        }
        std::cout << "" << std::endl;
    }
}


/**
 * printFrom prints the to adjacency list
 * @return void
 */
void AdjList::printTo() {
    for (int i = 0; i < maxNode_; i++) {
        std::cout << i << " <- ";
        for (int node : adjlistTo_[i]) {
            std::cout << node << " ";
        }
        std::cout << "" << std::endl;
    }
}


/**
 * getMaxNode returns the max nodes in the adjacency list
 * @return int maxNode_ in the adjacency list
 */
int AdjList::getMaxNode(){
    return maxNode_;
}


/**
 * getAdjListFrom returns the from adjacency list
 * @return V2D a 2D vector of ints
 */
V2D & AdjList::getAdjListFrom(){
    return adjlistFrom_;
}


/**
 * getAdjListFrom returns the to adjacency list
 * @return V2D a 2D vector of ints
 */
V2D & AdjList::getAdjListTo(){
    return adjlistTo_;
}