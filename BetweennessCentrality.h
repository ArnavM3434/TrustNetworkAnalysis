#pragma once

#include "DataParsing.h"
#include "AdjList.h"
#include "BFS.h"

#include <vector>


class BetweennessCentrality{

    public:
    
    BetweennessCentrality(AdjList graph);

    void DjikstraPath();
   

    private:

    std::vector<std::vector<double>> matrix;









};