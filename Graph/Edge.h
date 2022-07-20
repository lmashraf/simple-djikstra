//
// Created by achraf on 20.07.22.
//

#ifndef _EDGE_H
#define _EDGE_H

class Edge
{
public:
    int source;         // Source node
    int destination;    // Destination node
    int responseTime;   // Weight

public:
    Edge(int source, int destination, int responseTime);
};

#endif //_EDGE_H
