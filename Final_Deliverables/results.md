# Final Report:

# Trust_Network_Project
Contributors:
* Vishesh Prasad (vprasad3)
* Arnav Mehta (arnavm7)
* Anirudh Laxminarasimha Bachiraju (alb11)
* Rohit Uruma (ruruma2)

# Overview
Our project analyzes a trust network obtained from http://snap.stanford.edu/data/soc-Epinions1.html. The data set is an directed, unweighted graph with 75879 nodes and 508837 edges which we read in from a .txt file, and the data formatted for each line being: (Nodes from	Nodes To). The data set represents a trust connection where Node From trusts Node To. The goal of our project is to analyze the trust network by running breadth first search, pagerank, and betweenness centrality algorithms on the graph and analyzing the output. The leading question we want to address through the project is finding the node in the trust network that is most important in connecting different nodes, and which node is most important to allow for the fewest degrees of trust between nodes.

# Implementation
The first step in our project was to implement a data parsing pipeline to read the dataset from the .txt file and store it in our graph data structure. For our graph data structure we used an adjacency list which we stored in a 2D vector of integers. In our data parsing pipeline, we implemented the ability to set a max node in order to decrease the size of our data set and get more meaningful data by running the algorithms on a graph that is easier to visualize.

# Breadth First Search (BFS)
The output of BFS is the path that the breadth first search takes when going through the trust network. The output for BFS of the trust network can be seen below. [INSERT PICTURE] To test the correctness of our algorithms, we developed a custom trust network and went through BFS by hand. The custom trust network was developed with only a small number of nodes so that our output could be tested quickly and easily before we scaled up to the actual, large data set. We then tested the algorithm’s output with the actual output that we had calculated. This test can be seen below.
![alt text](/Final_Deliverables/Final_Report_Images/BFS_Traversal.png)