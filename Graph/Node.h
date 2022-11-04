//
// Created by achraf on 20.07.22.
//

#ifndef _NODE_H
#define _NODE_H

//----------------------------------------------------------------------------------------------------------------------
class Node
{
    public:
        int vertex;
        int responseTime;
    public:
        Node( int vertex, int responseTime );

};

class NodeIncreasingComparator
{
    public:
    bool operator( ) ( const Node& lhs, const Node& rhs ) const
    {
        return lhs.responseTime > rhs.responseTime;
    }
};

//----------------------------------------------------------------------------------------------------------------------
#endif //_NODE_H
