#pragma once
#include <iostream>
#include <vector>

class AdjList {
    public:
        AdjList(const std::vector<std::vector<int>> & dataset, int maxNode);
        void print();
    private:
        std::vector<std::vector<int>> adjlist_;
        int maxNode_;
};