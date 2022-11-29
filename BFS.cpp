#include <iostream>
#include <vector>
#include <queue>
#include "AdjList.h"
#include "BFS.h"

using std::queue;

BFS::BFS(AdjList graph){
    int maxNode = graph.getMaxNode();
    visitedNodes = std::vector<bool> (maxNode, false);
    traversalOutput = std::vector<int> (maxNode);
    traversalIndex = 0;

    adjlist_ = graph.getAdjList();




}

void BFS::Traverse(){

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