# Trust_Network_Project
Contributors:
* Vishesh Prasad (vprasad3)
* Arnav Mehta(arnavm7)
* Anirudh Laxminarasimha Bachiraju (alb11)
* Rohit Uruma (ruruma2)

# Overview
Goal: Analyize a trust network and run BFS, Betweenes Centrality, and Page Rank on a directed, unweighted graph.
- - - -
# Instructions to Run Program
Step 1: To download our program, please copy and paste this line to your terminal:

```
git clone git@github.com:VisheshP-29/Trust_Network_Project.git
``` 
Step 2: Open the repository in your terminal and navigate to the Trust_Network_Project directory.

Step 3: Build the program by running the following command in your terminal:
```
make
```
Step4: The executable file created can then be run with the following command:
```
./trustNet.exe 
```
Step5: The output will be displayed in the terminal. Where we show BFS, PageRank, and Betweenness Centrality and their respective outputs. We also show the results of the test cases not the test cases themselves.
- - - -
# Data Parsing
## Folder: Dataset
Holds the data set .txt file where the data set is located.
## Files: DataParsing.h/cpp
Read in the data from the soc-Epinions1.txt text file located in the Dataset folder. Data stores in the given format: NodeTo"\t"NodeFrom. Store the data set in a 2 dimensional vector of integers so that it can be used to create the adjacency list.
