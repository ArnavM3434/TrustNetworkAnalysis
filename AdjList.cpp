#include "AdjList.h"

AdjList::AdjList(const std::vector<std::vector<int>> & dataset, int maxNode) {
    std::vector<std::vector<int>> adjlist;
    adjlist.resize(maxNode);
    for (std::vector<int> nodePair : dataset) {
        int fromNode = nodePair[0];
        int toNode = nodePair[1];
        adjlist[toNode].push_back(fromNode);
    }
    adjlist_ = adjlist;
    maxNode_ = maxNode;
}

void AdjList::print() {
    for (int i = 0; i < maxNode_; i++) {
        std::cout << i << " <- ";
        for (int node : adjlist_[i]) {
            std::cout << node << " ";
        }
        std::cout << "" << std::endl;
    }
}



int AdjList::getMaxNode(){
    return maxNode_;


}



std::vector<std::vector<int>> & AdjList::getAdjList(){
    return adjlist_;

}