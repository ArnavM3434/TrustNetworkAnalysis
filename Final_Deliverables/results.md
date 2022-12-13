# Final Report:

# Trust_Network_Project
Contributors:
* Vishesh Prasad (vprasad3)
* Arnav Mehta (arnavm7)
* Anirudh Bachiraju (alb11)
* Rohit Uruma (ruruma2)

# Overview
Our project analyzes a trust network obtained from http://snap.stanford.edu/data/soc-Epinions1.html. The data set is an directed, unweighted graph with 75879 nodes and 508837 edges which we read in from a .txt file, and the data formatted for each line being: (Nodes from	Nodes To). The data set represents a trust connection where Node From trusts Node To. The goal of our project is to analyze the trust network by running breadth first search, pagerank, and betweenness centrality algorithms on the graph and analyzing the output. The leading question we want to address through the project is finding the node in the trust network that is most important in connecting different nodes, and which node is most important to allow for the fewest degrees of trust between nodes.

# Implementation
The first step in our project was to implement a data parsing pipeline to read the dataset from the .txt file and store it in our graph data structure. For our graph data structure we used an adjacency list which we stored in a 2D vector of integers. In our data parsing pipeline, we implemented the ability to set a max node in order to decrease the size of our data set and get more meaningful data by running the algorithms on a graph that is easier to visualize.

# Breadth First Search (BFS)
The output of BFS is the path that the breadth first search takes when going through the trust network. The output for BFS of the trust network can be seen below.
![alt text](/Final_Deliverables/Final_Report_Images/BFS_Traversal.png)
To test the correctness of our algorithms, we developed a custom trust network and went through BFS by hand. The custom trust network was developed with only a small number of nodes so that our output could be tested quickly and easily before we scaled up to the actual, large data set. We then tested the algorithm’s output with the actual output that we had calculated. This test can be seen below.
![alt text](/Final_Deliverables/Final_Report_Images/BFS_Test.png)

# PageRank
The output of PageRank is the rank of each node, which is a measurement of how important that node is to the set of nodes that make up the trust network. The rank of a page takes into consideration how many edges point to a page, and is calculated recursively based on the number of power iterations we want to calculate until the rank reaches a steady state. The damping factor (which we have chosen to be 0.85), dictates how much of the page’s next rank is based on its previous. A damping factor of 1 meaning that the new rank is not dependent on the previous rank, and 0 meaning that the new rank will always be the same as the initial rank. The rank of the nodes of our trust network can be seen below. 
![alt text](/Final_Deliverables/Final_Report_Images/PageRank.png)
The goal of PageRank is to find the most important node, which mainly focuses on the node with the most edges that point to it, but also takes into account the amount of edges that exit the node. To test the PageRank algorithm, we calculated the steady state rank of the custom data set and checked the algorithm’s output with our calculated one.
![alt text](/Final_Deliverables/Final_Report_Images/PageRank_Test.png)

# Betweenness Centrality
The output of our Betweenness Centrality algorithm is the most “important” node, or the node that has the greatest number of shortest paths running through it. The input is our graph, and the function runs through the shortest path between every combination of nodes in our dataset using a modified breadth-first search. Each traversal stores the shortest path between the current two nodes in a vector, and then updates the number of node occurrences in a vector called scores. After every combination of nodes is traversed, a single for-loop is then used to find the node with the greatest number of occurrences or the greatest number of shortest paths running through it. This node is then saved to the variable called mostImportant, and this value is returned to the terminal. To test our algorithm, we developed a custom trust network with a small number of nodes and calculated the betweenness centrality of each node. We then tested the algorithm’s output with the actual output that we had calculated. This test can be seen below.
![alt text](/Final_Deliverables/Final_Report_Images/BC_Test.png)

# Leading Question
Our leading question concerned which nodes were most influential in the network. We answered this using Betweenness Centrality and PageRank. On smaller test data, both algorithms yielded the same node as being the most important, while on the bigger trust dataset, they yielded different nodes. This result can be explained since PageRank depends on the edges that enter and exit a node and helped us figure out the most popular/trusting node, while Betweenness Centrality finds the node with the most shortest paths through it and help us figure out the node that holds the trust network together(help decrease the most degrees of trust by providing a shorter path). The overall idea that more important nodes are more trafficked comes into play when looking at applications of the trust dataset, where it becomes likely that more trafficked nodes are more trusted, and would thus give/receive reviews to other users more frequently.
