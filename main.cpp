#include "Graph/Graph.h"

int main()
{
    // Construct the graph from a list of Edges/Nodes
    std::vector< Edge > edges =
            {
                    { 0, 1, 20 },
                    { 2, 3, 99 },
                    { 3, 4, 35 },
                    { 1, 2, 10 },
                    { 1, 4, 150 },
                    { 4, 0, 450 },
            };

    // Initialise the Graph
    int numberOfEdges = edges.size( ) - 1;
    Graph graph( edges, numberOfEdges );

    // Add additional Edges/Nodes to the Graph
    graph.addEdge( { 4,5, 44 } ) ;
    graph.addEdge( { 5,6, 250 } );
    graph.addEdge( { 1,5, 20 } );

    // Print the Graph
    graph.printGraphBySourceNode( );
    std::cout << std::setw(64) << std::setfill('#') << "#"  << std::endl;
    graph.listAllNodes();

    // Search for the shortest path from sourceNode to destinationNode
    std::cout << std::setw(64) << std::setfill('#') << "#"  << std::endl;
    int sourceNode, destinationNode;

    std::cout << "Enter initial node:";
    std::cin >> sourceNode;

    std::cout << "Enter destination node:";
    std::cin >> destinationNode;

    graph.shortestPath(sourceNode, destinationNode);

    return 0;
}
