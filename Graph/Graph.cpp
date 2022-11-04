//
// Created by achraf on 19.07.22.
//

#include "Graph.h"

#include <climits>

Graph::Graph( std::vector< Edge >& edges, int graphSize ) :
        edges( edges ),
        graphSize( graphSize )
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
void Graph::addEdge(const Edge& edge )
{
    // Resize
    adjacentList.resize(++graphSize );

    // Insert at the end
    adjacentList[ edge.source ].push_back( edge  );
    adjacentList[ edge.destination ].push_back( edge );

    // Add to the edges' list
    edges.push_back(edge);

    std::cout << "Edge: (src:" << edge.source
            << ", dest:" << edge.destination
            << ", time:" << edge.responseTime << "ms ) added." << std::endl;
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
    std::priority_queue< Node, std::vector< Node >, NodeIncreasingComparator > minHeap;
    minHeap.push( { sourceNode, 0 } );

    // Distance from startNode to endNode set to Infinity
    std::vector<int> distance( destinationNode, INT_MAX );

    // Distance from sourceNode to itself is 0
    distance[ sourceNode ] = 0;

    // Track each edge/node for which minimum cost is found or has been visited/closed.
    std::vector<bool> isClosed(destinationNode, false);
    isClosed[ sourceNode ] = true;

    // Store predecessor of a vertex to a path
    std::vector<int> previousNode(destinationNode, -1);

    // Run loop until minHeap is empty
    while ( !minHeap.empty( ) )
    {
        // Remove the visited node and return the best vertex
        Node node = minHeap.top( );
        minHeap.pop( );

        // Store the vertex number
        int u = node.vertex;

        // Do for each neighbour of the current node
        for( auto e: adjacentList[ u ] )
        {
            int v = e.destination;
            int cost = e.responseTime;

            // Relaxation
            if ( !isClosed[ v ] && ( distance[ u ] + cost ) < distance[ v ] )
            {
                distance[ v ] = distance [ u ] + cost;
                previousNode[ v ] = u;
                minHeap.push({v, distance[ v ]});
            }
            // The vertex 'u' is now closed and shouldn't be picked again.
            isClosed[ u ] = true;
        }

        // Print the shortest path
        for( unsigned int i = 0; i < destinationNode; ++i )
        {
            if( i != sourceNode && distance[ i ] != INT_MAX )
            {
                /*std::cout << "The shortest path from ('node-" << sourceNode << "') to ('node-'" << i
                << "') has a minimum cost of" << distance[ i ] << std::endl;*/
                std::cout << "Path(" << sourceNode << " --> " << i << "): Minimum cost = "
                        << distance [ i ] << std::endl;
            }
        }
    }
}