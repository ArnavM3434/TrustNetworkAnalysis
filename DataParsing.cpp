#include "DataParsing.h"

/**
 * Default constructor for Data Parsing
 */
DataParsing::DataParsing(int numClean) {
	numLinesCleaned = numClean;
}


/**
 * file_to_V2D is a helper function for data parsing. It cleans up the inputed data from the 
 * given text file and returns all the nodes that are within the max node set in a V2D.
 * @param filename The name of the file that holds the data
 * @param setMax The max node to clean
 * @return V2D storing a vector of a vector of ints which holds the nodes 
 */
V2D DataParsing::file_to_V2D(const std::string & filename, int setMax) {

	V2D toReturn;
	std::ifstream infile(filename);
	int maxNode = setMax;

	std::string line;
	while (std::getline(infile, line)) {
		if(line[0] == '#') {
			continue;
		}
		std::vector<std::string> currLine;
		char toSplit = '\t';
		int numLines = SplitString(line, toSplit, currLine);
		if(numLines != 2) {
			continue;
		}
		int nodeFrom = std::stoi(currLine[0]);
		int nodeTo = std::stoi(currLine[1]);
		if((nodeFrom >= maxNode) || (nodeTo >= maxNode)) {
			continue;
		}
		std::vector<int> validLine;
		validLine.push_back(nodeFrom);
		validLine.push_back(nodeTo);
		toReturn.push_back(validLine);
		numLinesCleaned++;
	}

	return toReturn;
}


/**
 * getNodes is a function called by main. Its purpose is to call the data parsing helper function
 * file_to_V2D and returns its output.
 * @param filename The name of the file that holds the data
 * @param setMax The max node to clean
 * @return V2D storing a vector of a vector of ints which holds the nodes
 */
V2D DataParsing::getNodes(const std::string & filename, int setMax) {
	V2D nodes = file_to_V2D(filename, setMax);
	numNodesCleaned = setMax;
	numEdgesCleaned = static_cast<int>(nodes.size());
	return nodes;
}


/**
 * returns number of lines cleaned after data parsing
 * @return number of lines cleaned
 */
int DataParsing::getNumLinesCleaned() {
	return numLinesCleaned;
}


/**
 * returns number of edges cleaned after data parsing
 * @return number of edges cleaned
 */
int DataParsing::getNumEdgesCleaned() {
	return numEdgesCleaned;
}


/**
 * returns number of nodes cleaned after data parsing
 * @return number of nodes cleaned
 */
int DataParsing::getNumNodesCleaned() {
	return numNodesCleaned;
}