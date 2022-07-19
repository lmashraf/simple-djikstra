//
// Created by achraf on 19.07.22.
//

#include "Graph.h"

Graph::Graph(std::vector<Edge>& edges, int size) : edges(edges), size(size)
{
    adjacentList.resize(size);

    for(auto& edge : edges) {
        int source = edge.source;
        int destination = edge.destination;
        int weight = edge.responseTime;

        // Insert at the end
        adjacentList[source].push_back( std::make_pair(destination, weight ) );
        adjacentList[destination].push_back( std::make_pair(source, weight ) );
    }
}

//----------------------------------------------------------------------------------------------------------------------
void Graph::printGraph()
{
    for(int i = 0; i < size - 1 ; ++i)
    {
        std::cout << " SRC('node-" << i << "')" << std::endl;
        for (Node node: this->adjacentList[i])
        {
            std::cout << "\tDEST: 'node-" << node.first << "' with a response time of: " << node.second << "ms" << std::endl;
        }
        std::cout << std::endl << "#";
    }
    std::cout << std::endl;
}

//----------------------------------------------------------------------------------------------------------------------
void Graph::addEdge(Edge edge)
{
    ++size;
    adjacentList.resize(size );

    // Insert at the end
    adjacentList[edge.source].push_back( std::make_pair(edge.destination, edge.responseTime ) );
    adjacentList[edge.destination].push_back( std::make_pair(edge.source, edge.responseTime ) );

    // Add to edges list
    edges.push_back(edge);
}

//----------------------------------------------------------------------------------------------------------------------
void Graph::listAllEdges()
{
    std::cout
    << std::setw(20) << std::left << std::setfill(' ')  << "SOURCE NODE"
    << std::setw(20) << std::left << std::setfill(' ')  << "DEST. NODE"
    << std::setw(20) << std::left << std::setfill(' ')  << "RESPONSE TIME"
    << std::endl;

    for(auto& edge: edges)
    {
        std::cout
                << std::setw(20) << std::left << std::setfill(' ') << edge.source
                << std::setw(20) << std::left << std::setfill(' ') << edge.destination
                << std::setw(20) << std::left << std::setfill(' ') << edge.responseTime
        << std::endl;
    }
}