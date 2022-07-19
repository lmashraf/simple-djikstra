//
// Created by achraf on 19.07.22.
//

#include "Graph.h"

void Graph::printGraph(int n)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout << "Node " << i << std::endl;
        for (Node node: this->adjacentList[i])
        {
            std::cout << "DEST: 'Node " << node.first << "', Response Time: " << node.second << " ms" << std::endl;
        }
        std::cout << " \n---------------\n";
        std::cout << std::endl;
    }
}
