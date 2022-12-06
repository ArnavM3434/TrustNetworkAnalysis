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
    std::cout<<"Traversal Starting at Node " + std::to_string(bfsStartNode) + ":"<<std::endl;

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
    std::cout<<"Traversal Starting at Node " + std::to_string(bfsStartNode) + ":"<<std::endl;

    expectedBFS = {2,0,1,3,4};
    if(expectedBFS != bfsTraversalOutput){
        std::cout<<"Second BFS Traversal is Incorrect"<<std::endl;
        return false;
    }
    else{
        std::cout<<"Second BFS Traversal is Correct"<<std::endl;
    }

	//Test PageRank Algorithm
	// PageRank currPageRank(dataAdjList);

    std::cout<<"Test One Passed"<<std::endl;
    return true;
}