#pragma once
#include <iostream>
#include <vector>

class AdjList {
    public:
        AdjList(const std::vector<std::vector<int>> & dataset, int maxNode);
        void printFrom();
        void printTo();
        int getMaxNode();
        std::vector<std::vector<int>> & getAdjListFrom();
        std::vector<std::vector<int>> & getAdjListTo();

    private:
        std::vector<std::vector<int>> adjlistFrom_;
        std::vector<std::vector<int>> adjlistTo_;
        int maxNode_;
};