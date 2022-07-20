#include "Graph/Graph.h"

int main()
{
    std::vector< Edge > edges =
            {
                    { 0, 1, 20 },
                    { 2, 3, 99 },
                    { 3, 4, 35 },
                    { 1, 2, 10 },
                    { 1, 4, 150 },
                    { 4, 0, 450 },
            };
    int n = edges.size( ) - 1;

    Graph graph( edges, n );

    graph.addEdge( { 4,5, 44 } ) ;
    graph.addEdge( { 5,6, 250 } );
    graph.addEdge( { 1,5, 20 } );

    graph.printGraph( );

    // graph.listAllNodes();
    int sourceNode, destinationNode;

    std::cout << "Enter initial node:";
    std::cin >> sourceNode;
    std::cout << "Enter destination node:";
    std::cin >> destinationNode;

    graph.shortestPath(sourceNode, destinationNode);


    return 0;
}
