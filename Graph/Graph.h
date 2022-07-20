//
// Created by achraf on 19.07.22.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

#ifndef SIMPLEDIJKSTRA_GRAPH_H
#define SIMPLEDIJKSTRA_GRAPH_H

//----------------------------------------------------------------------------------------------------------------------
// Edge
struct Edge
{
    int source;         // Source node
    int destination;    // Destination node
    int responseTime;   // Weight
};

//----------------------------------------------------------------------------------------------------------------------
// Link
using Node = std::pair<int, int>;   // Node is defined by the pair destination node and its weight/cost

//----------------------------------------------------------------------------------------------------------------------
// Graph
class Graph
{
private:
    std::vector< Edge > edges;
    std::vector< std::vector< Node > > adjacentList;
    int size;

public:
    Graph( std::vector< Edge >& edges, int size );

public:
    void addEdge( Edge edge );
    void listAllNodes( );
    void printGraph( );
    void shortestPath( int startNode, int endNode );
};

#endif

//SIMPLEDIJKSTRA_GRAPH_H