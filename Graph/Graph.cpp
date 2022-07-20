//
// Created by achraf on 19.07.22.
//

#include "Graph.h"

Graph::Graph( std::vector< Edge >& edges, int graphSize ) : edges( edges ), graphSize( graphSize )
{
    // Resize the adjacent list vector
    adjacentList.resize( graphSize );

    // Add edges to the graph
    for( auto& edge : edges )
    {
        int source = edge.source;
        int destination = edge.destination;
        int weight = edge.responseTime;

        // Insert at the end
        adjacentList[source].push_back( edge );
        // adjacentList[destination].push_back( edge );
    }
}
//----------------------------------------------------------------------------------------------------------------------
void Graph::addEdge(const Edge edge )
{
    // Resize
    adjacentList.resize(++graphSize );

    // Insert at the end
    adjacentList[ edge.source ].push_back( edge  );
    adjacentList[ edge.destination ].push_back( edge );

    // Add to the edges' list
    edges.push_back(edge);
}

//----------------------------------------------------------------------------------------------------------------------
void Graph::printGraphBySourceNode( ) const
{
    for(int i = 0; i < graphSize - 1 ; ++i )
    {
        std::cout << "# SRC('node-" << i << "')" << std::endl;
        for ( Edge e: adjacentList[ i ] )
        {
            std::cout << "\tDEST('node-" << e.destination << "') with a response time of: " << e.responseTime << "ms." << std::endl;
        }
        std::cout << std::endl ;
    }
    std::cout << std::endl;
}

//----------------------------------------------------------------------------------------------------------------------
void Graph::listAllNodes( ) const
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
void Graph::shortestPath( int sourceNode, int destinationNode )
{
    // Create a Min-Heap using STL Priority Queue
    std::priority_queue< Node, std::vector< Node >, std::greater< > > minHeap;

    minHeap.push( Node(sourceNode, 0));

    // Distance from startNode to endNode set to Infinity
    std::vector<int> distance( destinationNode, INTMAX_MAX );

    // Distance from sourceNode to itself is 0
    distance[sourceNode] = 0;

    // Track vertices for which minimum cost is found
    std::vector<bool> isVisited(graphSize, false);

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