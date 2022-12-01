#include "AdjList.h"

AdjList::AdjList(const std::vector<std::vector<int>> & dataset, int maxNode) {
    std::vector<std::vector<int>> adjlistFrom;
    std::vector<std::vector<int>> adjlistTo;
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

void AdjList::printFrom() {
    for (int i = 0; i < maxNode_; i++) {
        std::cout << i << " <- ";
        for (int node : adjlistFrom_[i]) {
            std::cout << node << " ";
        }
        std::cout << "" << std::endl;
    }
}

void AdjList::printTo() {
    for (int i = 0; i < maxNode_; i++) {
        std::cout << i << " <- ";
        for (int node : adjlistTo_[i]) {
            std::cout << node << " ";
        }
        std::cout << "" << std::endl;
    }
}


int AdjList::getMaxNode(){
    return maxNode_;
}


std::vector<std::vector<int>> & AdjList::getAdjListFrom(){
    return adjlistFrom_;
}

std::vector<std::vector<int>> & AdjList::getAdjListTo(){
    return adjlistTo_;
}