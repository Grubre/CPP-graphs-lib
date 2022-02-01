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
template <class T_node, class T_vertex>    
class Weighted_Graph : public Graph{
public:
    enum class TraverseAlgorithm
    {
        DFS,
        BFS
    };

//setters
public:
    //nodes
    void add(T_node value = T_node());
    void remove(int id);

    //vertices
    void add(const Vertex &id, T_vertex value = T_vertex(), bool twoWay = true);
    void remove(const Vertex &id, bool twoWay = true);

    void clear();

//utility functions
    void print_node_values();
    void print_vertex_values();

//operator overloads
    T_node& operator[](int);
    T_vertex& operator[](Vertex);

//constructors & destructors
public:
    Weighted_Graph();
    Weighted_Graph(unsigned int _size);
    ~Weighted_Graph();

//variables
protected:
    std::vector<std::vector<T_vertex>> m_VertexValues;
    std::vector<T_node> m_NodeValues;
};


//==================contructors & destructors====================
template <class T_node, class T_vertex>
Weighted_Graph<T_node,T_vertex>::Weighted_Graph() : Graph()
{
    
}

template <class T_node, class T_vertex>
Weighted_Graph<T_node,T_vertex>::Weighted_Graph(unsigned int _size) : Graph(_size)
{
    m_VertexValues.resize(m_size, std::vector<T_vertex>(m_size));
    m_NodeValues.resize(m_size, T_node());
}

template <class T_node, class T_vertex>
Weighted_Graph<T_node,T_vertex>::~Weighted_Graph()
{

}


//==================setters====================
template <class T_node, class T_vertex>
void Weighted_Graph<T_node,T_vertex>::add(T_node value)
{
    Graph::add();

    for(int i = 0; i < m_size - 1; i++)
    {
        m_VertexValues[i].push_back(T_vertex());
    }
    m_VertexValues.push_back(std::vector<T_vertex>(m_size));
    m_NodeValues.push_back(value);
}


template <class T_node, class T_vertex>
void Weighted_Graph<T_node,T_vertex>::remove(int id)
{
    Graph::remove(id);

    m_NodeValues.erase(m_NodeValues.begin()+id);
    m_VertexValues.erase(m_VertexValues.begin()+id);
    for(int i = 0; i < m_size; i++)
    {
        m_VertexValues[i].erase(m_VertexValues[i].begin()+id);
    }
}


template <class T_node, class T_vertex>
void Weighted_Graph<T_node,T_vertex>::add(const Vertex &id, T_vertex value, bool twoWay)
{
    Graph::add(id,twoWay);
    m_VertexValues[id.first][id.second] = value;
    if(twoWay)
        m_VertexValues[id.second][id.first] = value;
}


template <class T_node, class T_vertex>
void Weighted_Graph<T_node,T_vertex>::remove(const Vertex &id, bool twoWay)
{
    Graph::remove(id, twoWay);
    m_VertexValues[id.first][id.second] = T_vertex();
    m_VertexValues[id.second][id.first] = T_vertex();
}


template <class T_node, class T_vertex>
void Weighted_Graph<T_node,T_vertex>::clear()
{
    Graph::clear();
    m_VertexValues.clear();
    m_NodeValues.clear();
}


//==================utility functions====================
template <class T_node, class T_vertex>
void Weighted_Graph<T_node,T_vertex>::print_node_values()
{
    for(int i = 0; i < m_size; i++)
    {
        std::cout << m_NodeValues[i] << " ";
    }
    std::cout << std::endl;
}


template <class T_node, class T_vertex>
void Weighted_Graph<T_node,T_vertex>::print_vertex_values()
{
    for(int i = 0; i < m_size; i++)
    {
        for(int j = 0; j < m_size; j++)
            std::cout << m_VertexValues[i][j] << " ";
        std::cout << std::endl;
    }
}


//==================operator overloads====================
template <class T_node, class T_vertex>
T_node& Weighted_Graph<T_node,T_vertex>::operator[](int id)
{
    return m_NodeValues[id];
}
template <class T_node, class T_vertex>
T_vertex& Weighted_Graph<T_node,T_vertex>::operator[](Vertex id)
{
    if(!m_AdjacencyMatrix[id.first][id.second])
        add(id,T_vertex(),false);
    return m_VertexValues[id.first][id.second];
}


};
#endif //_WEIGHTED_GRAPH_H