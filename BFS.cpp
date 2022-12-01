#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "AdjList.h"
#include "BFS.h"

using std::queue;

BFS::BFS(AdjList graph){
    int maxNode = graph.getMaxNode();
    visitedNodes = std::vector<bool> (maxNode, false);
    traversalOutput = std::vector<int> (maxNode);
    traversalIndex = 0;

    adjlist_ = graph.getAdjListTo();
}

void BFS::Traverse(int startNode){

    /*
    for(int i = 0; i < visitedNodes.size(); i++){
        visitedNodes[i] = false;
    }
    */
    Explore(startNode);
    for(unsigned i = 0; i < adjlist_.size(); i++){
        if(visitedNodes[i] == false){
            Explore(i);
        }
    }
}

void BFS::Explore(int v){
    std::queue<int> q;
    visitedNodes[v] = true;
    q.push(v);

    while(q.size() != 0){
        v = q.front();
        q.pop();
        traversalOutput[traversalIndex] = v;
        traversalIndex++;
        // std::vector<int> tempNeigh(adjlist_[v]);
        // int numNeigh = tempNeigh.size();
        // while(numNeigh > 0) {
        //     auto nextNode = *std::min_element(tempNeigh.begin(), tempNeigh.end());
        //     if(visitedNodes[nextNode] == true) {
        //         continue;
        //     } else {
        //         visitedNodes[nextNode] = true;
        //         q.push(nextNode);
        //     }
        //     numNeigh--;
        // }
        for (int neighbor : adjlist_[v]){
            if(visitedNodes[neighbor] == true){
                continue;
            }
            else{
                visitedNodes[neighbor] = true;
                q.push(neighbor);

            }
        }
    }
}



std::vector<int> & BFS::Output(){
    return traversalOutput;
}
