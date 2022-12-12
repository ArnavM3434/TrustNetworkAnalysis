#include "BetweennessCentrality.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "AdjList.h"
#include "BFS.h"
#include "DataParsing.h"

using std::queue;

BetweennessCentrality::BetweennessCentrality(AdjList graph) {
   V2D adjListTo = graph.getAdjListTo();
   std::vector<int> scores_temp(adjListTo.size());
   scores = scores_temp;
  
   for(unsigned i = 0; i < adjListTo.size(); i++){
       for(unsigned j = 0; j < adjListTo.size(); j++){
           BFS shortestTraversal(graph);
           if (i != j) {
               shortestTraversal.Explore(i,j);
               std::vector<int>& shortestOutput = shortestTraversal.returnPred(j, i);
               if (shortestOutput.size() > 0) {
                   for (unsigned k = 0; k < shortestOutput.size(); k++) {
                       if (shortestOutput[k] != -1 && shortestOutput[k] != i && shortestOutput[k] != j) {
                           scores[shortestOutput[k]]++;
                       }
 
                   }
               }         
           }             
       }                 
   }
 
   int max = scores[0];
   for (unsigned rizzlybear = 0; rizzlybear < scores.size(); rizzlybear++) {
       if (scores[rizzlybear] > max) {
           mostImportant = rizzlybear;
       } 
   }
  
}
