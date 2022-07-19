//
// Created by achraf on 19.07.22.
//
#include <iostream>
#include <vector>

#ifndef SIMPLEDIJKSTRA_GRAPH_H
#define SIMPLEDIJKSTRA_GRAPH_H

// Edge
struct Edge {
    int source;
    int destination;
    int weight;
};
typedef std::pair<int, int> Node;

// Graph
class Graph {
private:
    std::vector<Edge> edges;
    int size;
public:
    std::vector<std::vector<Node>> adjacentList;

    Graph(std::vector<Edge> edges) : edges(edges) {

        adjacentList.resize(size);

        for(auto& edge : edges) {
            int source = edge.source;
            int destination = edge.destination;
            int weight = edge.weight;

            // Insert at the end
            adjacentList[source].push_back( std::make_pair(destination, weight ) );
            adjacentList[destination].push_back( std::make_pair(source, weight ) );
        }
    }
    void addEdge(Edge& edge)
    {
        this->edges.push_back(edge);
    }

    void printGraph(int n);
};

#endif //SIMPLEDIJKSTRA_GRAPH_H


/*
//
// Created by achraf on 19.07.22.
//
#include <iostream>
#include <vector>

#ifndef SIMPLEDIJKSTRA_GRAPH_H
#define SIMPLEDIJKSTRA_GRAPH_H

// Edge
struct Edge {
    int source;
    int destination;
    int weight;
};



typedef std::pair<int, int> Node;

// Graph
class Graph {
public:
    std::vector<std::vector<Node>> adjacentList;

    Graph(std::vector<Edge> const &edges, int n)
    {
        adjacentList.resize(n);

        for(auto& edge : edges) {
            int source = edge.source;
            int destination = edge.destination;
            int weight = edge.weight;

            // Insert at the end
            adjacentList[source].push_back( std::make_pair(destination, weight ) );
            adjacentList[destination].push_back( std::make_pair(source, weight ) );
        }
    }

    void printGraph(int n);
};

#endif //SIMPLEDIJKSTRA_GRAPH_H
*/