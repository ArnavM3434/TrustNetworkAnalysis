## Leading Question 
This is a who-trust-whom online social network of a general consumer review site Epinions.com. Members of the site can decide whether to ''trust'' each other. A node trusts another node if it has a directed edge to the latter. All the trust relationships interact and form the Web of Trust which is then combined with review ratings to determine which reviews are shown to the user.

Questions we hope to answer:
Given this dataset of trust relationships for Epinions.com used to determine which reviews are shown to the user, how can we efficiently traverse through the network and from user to user? Which users are the most influential/important in this social network and why are they significant? 

We will use Djikstra’s algorithm to find the distance between 2 nodes - if the distance is 1, one node trusts the other node to the maximum degree (so a review from one node would very likely be shown to the other). As distance increases, the trust level decreases.

The PageRank algorithm will determine the most trusted nodes in a connected component, which are the nodes with the most incoming connections. The details of this will be described in detail further down.

## Dataset Acquisition
This is a who-trust-whom online social network of a general consumer review site Epinions.com. Members of the site can decide whether to ''trust'' each other. A node trusts another node if it has a directed edge to the latter. All the trust relationships interact and form the Web of Trust which is then combined with review ratings to determine which reviews are shown to the user.


## Data Format
The source of the dataset is Stanford Large Network Dataset Collection. Specifically, it is the Epinions social network. The input format of the dataset is a text file with 2 columns. For each row, the first number in the column represents a node, and the second column represents the node the first node points to (in other words the node that the first node trusts). The dataset consists of 75879 nodes and 508837 edges. The largest weakly connected component has 75877 nodes and 508836 edges. We plan to use all of the data. 


## Data Correction
Missing entries can occur in either of the two columns. If either of the two columns are missing (or both) we will simply process the next line. If an entire first column for a specific vertex is missing (for example all rows that start with vertex 10 are missing), it is not a problem, since it means 10 does not point to anything (but other vertices might point to 10). 

If we see a negative value in the file we will process the next line - only positive values are allowed.


## Data Storage
We are using a std::vector of std::vectors of integers to store the data. The first vector has size equal to the number of nodes, while each entry in the first vector consists of a vector with size equal to the number of nodes that point to the entry in the first vector. The worst case for storage O(n^2).


## Algorithm 
Function Inputs:
The data structure containing all the data will be an adjacency list consisting of a vector of vectors. Each element in the outer vector represents a unique user, and the vector that it contains represents all the users that trust that corresponding user.
To traverse through all the users in a connected component, we will use BFS and the input of that function will be the unique ID of a user in that connected component.
To figure out the shortest distance of trust between two users, we will implement Dijkstra’s algorithm with an input of two unique user IDs.
To get the ranking of the most “influential” users (according to PageRank centrality) in a connected component, we will implement the PageRank algorithm with an input of one user ID in that connected component.


Function Outputs
Our output for the PageRank will be a vector of the top 10 most “influential” nodes in order. For the Djikstra’s algorithm the output is a integer representing the distance between 2 nodes - this is effectively the level of trust between 2 nodes, which a greater distance indicating less trust.


Function Efficiency
For our functions we will be looking at the efficiency for BFS, Dijkstra’s Algorithm, and Page Rank. For BFS, the time complexity is dependent on the number of vertices(n) and the number of edges(m) for O(n+m). This is because we are required to visit all n vertices and for each vertex, we visit the directed edges that are connected to it using our implementation of a modified Adjacency List. This means that the time for BFS is dependent on the number of vertices and the edges which results in O(n+m). For Dijkstra’s Algorithm, our implementation will be using a heap using an adjacency list which has a runtime of O(nlog(n) + mlog(n)). Our implementation of Page Rank will have a runtime of O(k*n^2). Since page rank depends on matrix multiplication, it will have a worst time complexity of O(n^2). Matrix Multiplication is then run k times, where k is the number of iterations that we decide to implement for our page rank algorithm.



## Timeline
By November 11th:
Data Acquisition, Data Processing, Implement Breadth First Search, Data parsing pipeline

By November 18th:
Implement Dijkstra’s Algorithm

By November 25th:
Data correction, Implement PageRank Algorithm, Write Test Cases 

By December 2nd:
Finish the project and final deliverables
