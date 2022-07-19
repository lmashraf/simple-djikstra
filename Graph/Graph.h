//
// Created by achraf on 19.07.22.
//

#include <iostream>
#include <vector>
#include <iomanip>

#ifndef SIMPLEDIJKSTRA_GRAPH_H
#define SIMPLEDIJKSTRA_GRAPH_H

// Edge
struct Edge {
    int source;
    int destination;
    int responseTime;
};

using Node = std::pair<int, int>;

// Graph
class Graph {
private:
    std::vector<Edge> edges;
    std::vector<std::vector<Node>> adjacentList;
    int size;

public:
    Graph(std::vector<Edge>& edges, int size);

public:
    void addEdge(Edge edge);
    void listAllEdges();
    void printGraph();
};

#endif
//SIMPLEDIJKSTRA_GRAPH_H