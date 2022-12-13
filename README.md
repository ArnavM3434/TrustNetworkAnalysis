# Trust_Network_Project
Contributors:
* Vishesh Prasad (vprasad3)
* Arnav Mehta(arnavm7)
* Anirudh Bachiraju (alb11)
* Rohit Uruma (ruruma2)

# Overview
Goal: Analyize a trust network and run BFS, Betweenness Centrality, and Page Rank on a directed, unweighted graph.
- - - -
# Instructions to Run Program
Step 1: To download our program, please copy and paste this line to your terminal:

```
git clone https://github.com/VisheshP-29/Trust_Network_Project.git
``` 
Step 2: Open the repository in your terminal and navigate to the Trust_Network_Project directory.

Step 3: Build the program by running the following command in your terminal:
```
make
```
Step 4: The executable file created can then be run with the following command:
```
./trustNet.exe 
```
##Output:
The output will be displayed in the text file: output.txt. The output will include the output of BFS, PageRank, and Betweenness Centrality run on the data set.

Note: There is no input to be specified. However you can change the number of nodes you work with, the starting node for BFS, and the damping factor/number of power iterations for PageRank all in main.cpp (which deals with the larger dataset). You can also change the file name in Test.cpp (within bool test(int testNumber)) to include a file of your own creation - test cases would have to be modified accordingly.
- - - -
# Final Deliverables
## Folder: Final_Deliverables
Holds the final deliverables for the project including the final presentation video, slides, and the final report.
results.md within Final_Deliverables stores the written report.
- - - -
# Data Parsing
## Folder: Dataset
Holds the data set .txt file where the data set is located.
## Files: DataParsing.h/cpp
Read in the data from the soc-Epinions1.txt text file located in the Dataset folder. Data stores in the given format: NodeTo"\t"NodeFrom. Store the data set in a 2 dimensional vector of integers so that it can be used to create the adjacency list.
## Helper Files: utils.h/cpp
Stores helper functions for data parsing.
# Adjacency List
## Files: AdjList.h/cpp
Uses the nodes that are read in from the data parsing pipeline to create an adjacency "to" list (each node has vector of nodes it points to) and an adjacency "from" list (each node has vector of nodes that point to it).

# Breadth First Search(BFS)
## Files: BFS.h/cpp
Uses graph adjacency list to find a breadth first search traversal through the given graph.
Also had function to find the shortest path between two nodes that was used by Betweenness Centrality Algorithm.

# PageRank
## Files: PageRank.h/cpp
Uses graph from adjacency list to calculate the rank of each node and find the node with the highest rank.

# Betweenness Centrality
## Files: BetweennessCentrality.h/cpp
Uses graph from adjacency list to find the most important node using betweenness centrality.

# Testing
## Folder: Tests
Holds the custom data set in a .txt file that uses the same formatting as the large data set
## Files: Test.h/cpp
Run unit tests on each algorithm using the custom data set read in from .txt files in the Tests folder.
## Brief Description
Our tests ensure we clean the test data correctly (it purposely has typos in it), create a graph correctly, implement BFS correctly using a sample starting node, implement Page Rank correctly, and implement Betweenness Centrality and the shortest path aspect of Betweenness Centrality.
