#include "Graph/Graph.h"

int main()
{
    // Construct the graph from a list of Edges/Nodes
    std::vector< Edge > edges =
            {
                    { 0, 1, 20 },
                    { 2, 3, 99 },
                    { 2, 6, 200 },
                    { 3, 4, 35 },
                    { 1, 2, 10 },
                    { 1, 4, 150 },
                    { 4, 0, 450 }
            };

    // Initialise the Graph
    int numberOfEdges = edges.size( ) ;
    std::cout << "Initial Number of Edges: " << numberOfEdges << std::endl;
    Graph graph( edges, numberOfEdges );

    // Add additional Edges/Nodes to the Graph
    graph.addEdge( { 4,5, 44 } ) ;
    graph.addEdge( { 5,6, 250 } );
    graph.addEdge( { 1,5, 20 } );
    graph.addEdge( { 7,2, 220 } );

    // View number of Edges
    numberOfEdges = edges.size( ) ;
    std::cout << "Current number of Edges: " << numberOfEdges << std::endl;

    // Print the Graph
    graph.printGraphBySourceNode( );
    std::cout << std::setw(64) << std::setfill('#') << "#"  << std::endl;
    graph.listAllNodes();

    // Search for the shortest path from sourceNode to destinationNode
    /*std::cout << std::setw(64) << std::setfill('#') << "#"  << std::endl;
    int sourceNode, destinationNode;

    std::cout << "Enter initial node:";
    std::cin >> sourceNode;

    std::cout << "Enter destination node:";
    std::cin >> destinationNode;

    graph.shortestPath(sourceNode, destinationNode);*/

    // Run Dijkstra's algorithm from every node
    for (int sourceNode = 0; sourceNode <= numberOfEdges; ++sourceNode )
    {
        std::cout << std::setw(64) << std::setfill('#') << " ####### SrcNode: " << sourceNode << std::endl;
        graph.shortestPath( sourceNode, numberOfEdges );
    }

    return 0;
}
