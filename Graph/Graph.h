//
// Created by achraf on 19.07.22.
//
#ifndef _GRAPH_H
#define _GRAPH_H

#include "Edge.h"
#include "Node.h"

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <queue>

//----------------------------------------------------------------------------------------------------------------------
// Graph
class Graph
{
private:
    std::vector< Edge > edges;
    std::vector< std::vector< Edge > > adjacentList;
    int graphSize;

public:
    Graph( std::vector< Edge >& edges, int graphSize );

public:
    void addEdge(const Edge edge );

    void listAllNodes( ) const;
    void printGraphBySourceNode( ) const;
    void shortestPath( int sourceNode, int destinationNode );
};

#endif

//_GRAPH_H