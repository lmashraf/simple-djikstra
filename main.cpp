#include "Graph/Graph.h"

int main() {
    std::vector< Edge > edges =
            {
                    { 0, 1, 20 },
                    { 1, 2, 10 },
                    { 1, 4, 150 },
                    { 2, 3, 99 },
                    { 3, 4, 35 },
                    { 4, 0, 450 },
            };
    int n = edges.size( );

    Graph graph( edges, n );

    graph.addEdge( { 4,5,44 }) ;
    graph.addEdge( { 5,6,250 } );

    graph.printGraph( );

    graph.listAllEdges( );

    return 0;
}
