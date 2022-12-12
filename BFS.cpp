#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "AdjList.h"
#include "BFS.h"

using std::queue;

/*
 * BFS constructor that will build an object on which we can run the traversal on
 * @param graph is the adjacency list that will be running BFS traversal on
 */
BFS::BFS(AdjList graph){
    int maxNode = graph.getMaxNode();
    visitedNodes = std::vector<bool> (maxNode, false);
    traversalOutput = std::vector<int> (maxNode);
    traversalIndex = 0;
    pred = std::vector<int>(maxNode, -1);

    adjlist_ = graph.getAdjListTo();
}

/*
 * Traverse is the function which runs BFS on the given BFS object
 * @param startNode is the starting node for BFS traversal
 * @return void
 */
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

/*
 * Explore is a helper function for Traverse that is used to explore the neighbors of
 * the given vertex
 * @param v is the current vertex of the graph to explore by looking at its neighbors
 * @return void
 */
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

void BFS::Explore(int v, int e){
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
            pred[neighbor] = v;
            if(visitedNodes[neighbor] == true){
                continue;
            }
            else{
                visitedNodes[neighbor] = true;



                if(neighbor == e){
                    //end traversal
                    return;


                }
                q.push(neighbor);



            }
        }
    }
}





/*
 * Output returns the traversal path taken by BFS
 * @return std::vector<int> returns the vector that holds the path taken by the traversal
 */
std::vector<int> & BFS::Output(){
    return traversalOutput;
}

std::vector<int> & BFS::returnPred(int end, int start){

    /*
    std::cout<<"Start Node: " <<start<<"End Node: "<<end<<std::endl;
    for(unsigned i = 0; i < traversalOutput.size(); i++){
        std::cout<<traversalOutput[i]<<std::endl;
    }
    */

    if(pred[end] == -1){
        return path;
    }

    int i = pred[end];
    path.push_back(i);
    while(i != start && i != -1){
        i = pred[i];
        path.push_back(i);
    }

    



    return path;


    
}