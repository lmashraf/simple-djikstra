//
// Created by achraf on 19.07.22.
//

#include <queue>
#include <limits>

#include "Graph.h"

Graph::Graph( std::vector< Edge >& edges, int size ) : edges( edges ), size( size )
{
    adjacentList.resize(size);

    for( auto& edge : edges )
    {
        int source = edge.source;
        int destination = edge.destination;
        int weight = edge.responseTime;

        // Insert at the end
        adjacentList[source].push_back( std::make_pair(destination, weight ) );
        adjacentList[destination].push_back( std::make_pair(source, weight ) );
    }
}

//----------------------------------------------------------------------------------------------------------------------
void Graph::printGraph( )
{
    for( int i = 0; i < size - 1 ; ++i )
    {
        std::cout << "#SRC('node-" << i << "')" << std::endl;
        for ( Node v: adjacentList[ i ] )
        {
            std::cout << "\tDEST('node-" << v.first << "') with a response time of: " << v.second << "ms." << std::endl;
        }
        std::cout << std::endl ;
    }
    std::cout << std::endl;
}

//----------------------------------------------------------------------------------------------------------------------
void Graph::addEdge( Edge edge )
{
    // Resize
    adjacentList.resize(++size );

    // Insert at the end
    adjacentList[ edge.source ].push_back( std::make_pair( edge.destination, edge.responseTime ) );
    adjacentList[ edge.destination ].push_back( std::make_pair( edge.source, edge.responseTime ) );

    // Add to the edges' list
    edges.push_back(edge);
}

//----------------------------------------------------------------------------------------------------------------------
void Graph::listAllNodes()
{
    // Header
    std::cout
        << std::setw( 20 ) << std::left << std::setfill( ' ' )  << "SOURCE NODE"
        << std::setw( 20 ) << std::left << std::setfill( ' ' )  << "DEST. NODE"
        << std::setw( 20 ) << std::left << std::setfill( ' ' )  << "RESPONSE TIME"
        << std::endl;

    // All nodes
    for( auto& edge: edges )
    {
        std::cout
            << std::setw( 20 ) << std::left << std::setfill( ' ' ) << edge.source
            << std::setw( 20 ) << std::left << std::setfill( ' ' ) << edge.destination
            << std::setw( 20 ) << std::left << std::setfill( ' ' ) << edge.responseTime
            << std::endl;
    }
}
//----------------------------------------------------------------------------------------------------------------------
void Graph::shortestPath( int startNode, int endNode )
{
    // Create a Min-Heap using STL Priority Queue
    std::priority_queue< Node, std::vector< Node >, std::greater< Node > > minHeap;

    minHeap.push( { startNode, 0 } );

    // Distance from startNode to endNode set to Infinity
    std::vector<int> distance( endNode, INTMAX_MAX );

    // Distance from startNode to itself is 0
    distance[startNode] = 0;

    // Track vertices for which minimum cost is found

    // Store predecessor of a vertex to a path

    // Run loop until minHeap is empty
    while ( !minHeap.empty( ) )
    {
        // Remove the visited node and return the best vertex

        // Store the vertex number

        // Do for each neighbour of the current node

        // Add Dijkstra relaxation step
    }

    // Show shortest path
    std::cout << "Shortest Path: "<< std::endl;

}