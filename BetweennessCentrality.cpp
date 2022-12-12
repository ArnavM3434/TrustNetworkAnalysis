#include "BetweennessCentrality.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "AdjList.h"
#include "BFS.h"
#include "DataParsing.h"

using std::queue;

/*
* This constructor handles the Betweenness Centrality Algorithm. It relies
* on a BFS traversal to find the shortest path. It updates the class level
* variable "MostImportant" with the node that has the most paths running through
* it.
*/
BetweennessCentrality::BetweennessCentrality(AdjList graph) {
   V2D adjListTo = graph.getAdjListTo();
   std::vector<int> scores_temp(adjListTo.size());
   scores = scores_temp;
  
   for(unsigned i = 0; i < adjListTo.size(); i++){ //This double for loop evaluates every pair of nodes
       for(unsigned j = 0; j < adjListTo.size(); j++){
           BFS shortestTraversal(graph);
           if (i != j) {
               shortestTraversal.Explore(i,j);
               std::vector<int>& shortestOutput = shortestTraversal.returnPred(j, i); //shortestOutput stores the shortest path between two nodes
               if (shortestOutput.size() > 0) {
                   for (unsigned k = 0; k < shortestOutput.size(); k++) {
                       if (shortestOutput[k] != -1 && shortestOutput[k] != i && shortestOutput[k] != j) {
                           scores[shortestOutput[k]]++; //if a node appears in a shortest path, reflect accordingly in the scores vector
                       }
 
                   }
               }         
           }             
       }                 
   }
 

    
   int max = scores[0];
   //This loop is used to find the node with the highest score
   for (unsigned rizzlybear = 0; rizzlybear < scores.size(); rizzlybear++) {
       if (scores[rizzlybear] > max) {
           mostImportant = rizzlybear;
       } 
   }
  
}
