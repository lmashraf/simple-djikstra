//
// Created by achraf on 20.07.22.
//

#ifndef _NODE_H
#define _NODE_H


class Node
{
public:
    int vertex;
    int responseTime;
public:
    Node(int vertex, int responseTime);
    friend bool operator>(const Node& n1, const Node& n2);
};


#endif //_NODE_H
