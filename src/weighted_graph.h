#ifndef _WEIGHTED_GRAPH_H
#define _WEIGHTED_GRAPH_H
///////////////////////////////////////////////////////////////////
// NAME:               weighted_graph.h
//
// PURPOSE:            Implementation of Weighted_Graph class.
//                     It's an extension of the Graph class, that
//                     holds values for vertices and performs basic
//                     graph algorithms.
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

    std::vector<std::vector<float>> m_VertexValues;
};


//==================contructors & destructors====================
Weighted_Graph::Weighted_Graph() : Graph()
{
    
}

Weighted_Graph::Weighted_Graph(unsigned int _size) : Graph(_size)
{
    m_VertexValues.resize(m_size, std::vector<float>(m_size));
}

Weighted_Graph::~Weighted_Graph()
{

}
};
#endif //_WEIGHTED_GRAPH_H