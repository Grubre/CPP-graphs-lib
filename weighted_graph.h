#ifndef _WEIGHTED_GRAPH_H
#define _WEIGHTED_GRAPH_H
///////////////////////////////////////////////////////////////////
// NAME:               weighted_graph.h
//
// PURPOSE:            Method implementations of Graph class.
//
// AUTHOR:             Grubre
///////////////////////////////////////////////////////////////////


#include "graph.h"

namespace Grubre
{
class Weighted_Graph : public Graph{
public:
    enum class TraverseAlgorithm
    {
        DFS,
        BFS
    };

//setters
public:
    void add_node();
    void add_node(const std::vector<int> &neighborIDs, bool twoWay = true);
    void remove_node(int id);

    void add_vertex(int NodeAID, int NodeBID, bool twoWay = true);
    void remove_vertex(int NodeAID, int NodeBID, bool twoWay = true);

//constructors & destructors
public:
    Weighted_Graph();
    Weighted_Graph(unsigned int _size);
    ~Weighted_Graph();

//variables
protected:
    //bool m_isSymetricallyValued;
};
};
#endif //_WEIGHTED_GRAPH_H