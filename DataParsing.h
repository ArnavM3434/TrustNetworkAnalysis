#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "utils.h"


/**
 * V2D is a two-dimensional array. It is a vector that stores a vector of ints.
 * It is used to store the edges given from the text file by storing the origin node
 * and the node it points to.
 */
typedef std::vector<std::vector<int> > V2D; 

class DataParsing {
	public:
	/**
	 * Default constructor for Data Parsing
	 */
	DataParsing(int numClean);
	/**
	 * file_to_V2D is a helper function for data parsing. It cleans up the inputed data from the 
	 * given text file and returns all the nodes that are within the max node set in a V2D.
	 * @param filename The name of the file that holds the data
	 * @param setMax The max node to clean
	 * @return V2D storing a vector of a vector of ints which holds the nodes 
	 */
	V2D file_to_V2D(const std::string & filename, int setMax);

	/**
	 * getNodes is a function called by main. Its purpose is to call the data parsing helper function
	 * file_to_V2D and returns its output.
	 * @param filename The name of the file that holds the data
	 * @param setMax The max node to clean
	 * @return V2D storing a vector of a vector of ints which holds the nodes
	 */
	V2D getNodes(const std::string & filename, int setMax);

	/**
	 * returns number of lines cleaned after data parsing
	 * @return number of lines cleaned
	 */
	int getNumLinesCleaned();

	/**
	 * returns number of edges cleaned after data parsing
	 * @return number of edges cleaned
	 */
	int getNumEdgesCleaned();

	/**
	 * returns number of nodes cleaned after data parsing
	 * @return number of nodes cleaned
	 */
	int getNumNodesCleaned();


	private:
	/**
	 * stores number of lines cleaned
	 */
	int numLinesCleaned;

	/**
	 * stores number of edges cleaned
	 */
	int numEdgesCleaned;
	
	/**
	 * stores number of nodes cleaned
	 */
	int numNodesCleaned;
};