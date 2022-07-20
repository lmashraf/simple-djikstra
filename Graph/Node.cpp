//
// Created by achraf on 20.07.22.
//

#include "Node.h"

//----------------------------------------------------------------------------------------------------------------------
Node::Node(int vertex, int responseTime) : vertex(vertex), responseTime(responseTime)
{}

//----------------------------------------------------------------------------------------------------------------------
bool
operator>(const Node &lhs, const Node &rhs)
{
    return lhs.responseTime > rhs.responseTime;
}
