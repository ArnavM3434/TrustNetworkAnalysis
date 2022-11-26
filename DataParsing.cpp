#include "DataParsing.h"

/*
 * file_to_V2D is a helper function for data parsing. It cleans up the inputed data from the 
 * given text file and returns all the nodes that are within the max node set in a V2D.
 * @param filename The name of the file that holds the data
 * @return V2D storing a vector of a vector of ints which holds the nodes 
 */
V2D file_to_V2D(const std::string & filename) {

    V2D toReturn;
    std::ifstream infile(filename);
    int maxNode = 500;

    std::string line;
    while (std::getline(infile, line)) {
        if(line[0] == '#') {
            // std::cout<<line + "\n";
            continue;
        }
        // std::cout<<line + "\n";
        std::vector<std::string> currLine;
        char toSplit = '\t';
        int numLines = SplitString(line, toSplit, currLine);
        int nodeFrom = std::stoi(currLine[0]);
        int nodeTo = std::stoi(currLine[1]);
        if((nodeFrom >= maxNode) || (nodeTo >= maxNode)) {
            continue;
        }
        // std::cout<<line + "\n";
        std::vector<int> validLine;
        validLine.push_back(nodeFrom);
        validLine.push_back(nodeTo);
        toReturn.push_back(validLine);
    }

    return toReturn;
}

/*
 * getNodes is a function called by main. Its purpose is to call the data parsing helper function
 * file_to_V2D and returns its output.
 * @return V2D storing a vector of a vector of ints which holds the nodes
 */
V2D getNodes(void) {
    V2D nodes = file_to_V2D("Dataset/soc-Epinions1.txt");
    std::cout<<"Number of Edges: ";
    std::cout<<nodes.size()<<std::endl;
    return nodes;
}
