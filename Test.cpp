#include "Test.h"


/*
 * test is a function that is used to test the working capacity of our functions
 * @param testNumber is the testNumber that we want to run;
 * @return bool which is true if test casses pass and false otherwise
 */
bool test(int testNumber) {
    std::vector<std::string> testHold;
    const std::string testOne = "Tests/TestOne.txt";
    //Add tests strings as more tests are added
    testHold.push_back(testOne);
    return testHelper(testHold[testNumber - 1]);
}


/*
 * testHelper is a helper function that takes in the file with the test data and test all functions
 * that we have implemented
 * @param filename The name of the file that holds the test data
 * @return bool which is true if test casses pass and false otherwise
 */
bool testHelper(const std::string & filename) {
    int setMaxNodes = 5;
    V2D cleanedNodes = getNodes(filename, setMaxNodes);
   
    AdjList dataAdjList(cleanedNodes, setMaxNodes);

    //Testing cleanNodes
    V2D expectedCleanNodes = {
        {0,1},
        {1,2},
        {1,3},
        {2,0},
        {4,3}
    };
    if(expectedCleanNodes != cleanedNodes){
        std::cout<<"Data Incorrectly Cleaned"<<std::endl;
        for(int i = 0; i < expectedCleanNodes.size(); i++){
            for(int j = 0; j < expectedCleanNodes[i].size(); j++){
                std::cout<<expectedCleanNodes[i][j]<<std::endl;
            }
        }

        for(int i = 0; i < cleanedNodes.size(); i++){
            for(int j = 0; j < cleanedNodes[i].size(); j++){
                std::cout<<cleanedNodes[i][j]<<std::endl;
            }
        }
        return false;
    } else {
        std::cout<<"Test Data Correctly Cleaned"<<std::endl;
    }

    //Testing Adjacency List "From"
    V2D expectedAdjListFrom = {
        {2},
        {0},
        {1},
        {1,4},
        {}
    };
    if(expectedAdjListFrom != dataAdjList.getAdjListFrom()){
        std::cout<<"Adjacency List 'From' is Incorrect"<<std::endl;
        return false;
    }
    else{
        std::cout<<"Adjacency List 'From' is Correct"<<std::endl;

    }
    //Testing Adjacency List "From"
    V2D expectedAdjListTo = {
        {1},
        {2,3},
        {0},
        {},
        {3}
    };
    V2D actualAdjListTo = dataAdjList.getAdjListTo();
    if(expectedAdjListTo != actualAdjListTo){
        std::cout<<"Adjacency List 'To' is Incorrect"<<std::endl;


        return false;
    }
    else{
        std::cout<<"Adjacency List 'To' is Correct"<<std::endl;

    }

    //Testing BFS
    int bfsStartNode = 0;
    BFS bfsTraversal(dataAdjList);
    bfsTraversal.Traverse(bfsStartNode);
    std::vector<int>& bfsTraversalOutput = bfsTraversal.Output();
    std::cout<<"Traversal Starting at Node " + std::to_string(bfsStartNode) + ": ";

    std::vector<int> expectedBFS = {0,1,2,3,4};
    if(expectedBFS != bfsTraversalOutput){
        std::cout<<"BFS Traversal is Incorrect"<<std::endl;
        return false;
    }
    else{
        std::cout<<"BFS Traversal is Correct"<<std::endl;
    }

    //Testing Random Starting Node
    bfsStartNode = 2;
    BFS bfsTraversal2(dataAdjList);
    bfsTraversal2.Traverse(bfsStartNode);
    bfsTraversalOutput = bfsTraversal2.Output();
    std::cout<<"Traversal Starting at Node " + std::to_string(bfsStartNode) + ": ";

    expectedBFS = {2,0,1,3,4};
    if(expectedBFS != bfsTraversalOutput){
        std::cout<<"Second BFS Traversal is Incorrect"<<std::endl;
        return false;
    }
    else{
        std::cout<<"Second BFS Traversal is Correct"<<std::endl;
    }

	//Test PageRank Algorithm
    
	PageRank currPageRank(dataAdjList, 0.85);
	currPageRank.runPageRank(10, true);
	std::vector<std::vector<std::string>> dataPageRank = currPageRank.getPageRank();
	int maxRankNode = 3;
	std::vector<double> calcRank = currPageRank.getRank();
	double maxRank = calcRank[0];
	int currMax = 0;
	for(int i = 0; i < static_cast<int>(calcRank.size()); i++) {
		if(calcRank[i] > maxRank) {
			maxRank = calcRank[0];
			currMax = i;
		}
	}
	if(maxRankNode != currMax) {
        std::cout<<"Page Rank Failed!"<<std::endl;
    }
    else{
        std::cout<<"Page Rank Passed!"<<std::endl;
    }

    
    


    //Testing Shortest Path With BFS
    BFS shortestTraversal(dataAdjList);
    shortestTraversal.Explore(0,3);
    std::vector<int>& shortestOutput = shortestTraversal.returnPred(3, 0);
    if(shortestOutput[0] != 1 || shortestOutput[1] != 0){
        std::cout<<"Shortest Path Failed!"<<std::endl;
    }
    else{
        std::cout<<"Shortest Path Passed!"<<std::endl;
    }
    
    



    //Betweeness Centrality Test
    BetweennessCentrality betweenness(dataAdjList);
    int mostImportant = betweenness.mostImportant;


    if(mostImportant != 1){
        std::cout<<"Betweenness Centrality Failed!"<<std::endl;
    }
    else{
        std::cout<<"Betweenness Centrality Passed!"<<std::endl;
    }


    std::cout<<"All Tests Completed!"<<std::endl;

    return true;

}