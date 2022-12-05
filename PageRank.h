#pragma once

#include "DataParsing.h"
#include "AdjList.h"
#include "BFS.h"

#include <vector>

class PageRank {
	public:
		PageRank(AdjList graph);
		void runPageRank(int numPower);
		std::vector<std::vector<std::string>> getToPageRank();
		std::vector<std::vector<std::string>> getPageRank();

	private:
		V2D adjMat_;
		std::vector<std::vector<double>> markovMatrix_;
		std::vector<std::vector<std::string>> pageRank_;
		int numNodes_;
};