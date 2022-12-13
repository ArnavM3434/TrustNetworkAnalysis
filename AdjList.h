#pragma once
#include <iostream>
#include <vector>
#include "DataParsing.h"

class AdjList {
    public:
		/**
		 * AdjList is a constructor that stores the object for the adjacency lists
		 * @param dataset is a 2D vector of ints that stores the cleaned nodes
		 * @param maxNode The number of nodes 
		 */
		AdjList(const V2D & dataset, int maxNode);

		/**
		 * printFrom prints the from adjacency list
		 * @return void
		 */
		void printFrom();

		/**
		 * printFrom prints the to adjacency list
		 * @return void
		 */
		void printTo();

		/**
		 * getMaxNode returns the max nodes in the adjacency list
		 * @return int maxNode_ in the adjacency list
		 */
		int getMaxNode();

		/**
		 * getAdjListFrom returns the from adjacency list
		 * @return V2D a 2D vector of ints
		 */
		V2D & getAdjListFrom();

		/**
		 * getAdjListFrom returns the to adjacency list
		 * @return V2D a 2D vector of ints
		 */
		V2D & getAdjListTo();


    private:
        /**
         * adjlistFrom_ is the adjacency list where we store the node's neighbor nodes that point
         * to that node
         */
        V2D adjlistFrom_;

        /**
         * adjlistTo_ is the adjacency list where we store the node's neighbor nodes that the node
         * points to
         */
        V2D adjlistTo_;

        /**
         * maxNode_ is the index of the max node stored inthe adjacency list
         */
        int maxNode_;
};