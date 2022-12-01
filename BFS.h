#pragma once
#include <iostream>
#include <vector>
#include "AdjList.h"


class BFS{

    public:

    BFS(AdjList graph);

    void Traverse(int startNode);

    void Explore(int v);

    std::vector<int> & Output();



    private:

    std::vector<bool> visitedNodes;

    std::vector<int> traversalOutput;

    int traversalIndex;

    std::vector<std::vector<int>> adjlist_;












};