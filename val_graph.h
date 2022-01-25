#pragma once
#include "graph.h"
#include <iostream>


template <class T_node, class T_vertex>
class Val_Graph : public Graph
{
private:
enum class TraverseAlgorithm
{
    DFS,
    BFS
};
//setters
public:
    void addNode();
    void removeNode(int id);
    void setNodeValue(int id, T_node value);

    void addVertex(int NodeAID, int NodeBID, T_vertex value, bool twoWay = true);
    void removeVertex(int NodeAID, int NodeBID, bool twoWay = true);
    void setVertexValue(int NodeAID, int NodeBID, T_node value, bool twoWay = true);

//getters
public:
    T_node getNodeValue(int id) { return m_NodeValues[id]; }
    T_node getVertexValue(int NodeAID, int NodeBID) { return m_VertexValues[NodeAID][NodeBID]; }

//utility functions
public:

//constructors & destructors
public:
    Val_Graph();
    Val_Graph(unsigned int _size);
    ~Val_Graph();

//variables
protected:
    std::vector<T_node> m_NodeValues;
    std::vector< std::vector< T_vertex > > m_VertexValues;

    bool m_IsSymetricallyValued;
};


//==================FUNCTION DECLARATIONS====================

//==================setters====================
template <class T_node, class T_vertex>
void Val_Graph<T_node, T_vertex>::addNode()
{
    Graph::addNode();
    m_NodeValues.resize(m_size);
    m_VertexValues.resize(m_size);
}


template <class T_node, class T_vertex>
void Val_Graph<T_node, T_vertex>::removeNode(int id)
{
    if(id > m_size - 1)
        return;
    Graph::removeNode(id);
    m_NodeValues.erase(m_AdjacencyMatrix.begin()+id);
    m_VertexValues.erase(m_AdjacencyMatrix.begin()+id);
    for(int i = 0; i < m_size; i++)
    {
        m_VertexValues[i].erase(m_VertexValues[i].begin()+id);
    }
}


template <class T_node, class T_vertex>
void Val_Graph<T_node, T_vertex>::setNodeValue(int id, T_node value)
{
    m_NodeValues[id] = value;
}


template <class T_node, class T_vertex>
void Val_Graph<T_node, T_vertex>::addVertex(int NodeAID, int NodeBID, T_vertex value, bool twoWay)
{
    Graph::addVertex(NodeAID, NodeBID, twoWay);
    m_VertexValues[NodeAID][NodeBID] = value;
    if(twoWay)
        m_VertexValues[NodeBID][NodeAID] = value;
}


template <class T_node, class T_vertex>
void Val_Graph<T_node, T_vertex>::removeVertex(int NodeAID, int NodeBID, bool twoWay)
{
    Graph::removeVertex(NodeAID, NodeBID, twoWay);
    // to check
}


template <class T_node, class T_vertex>
void Val_Graph<T_node, T_vertex>::setVertexValue(int NodeAID, int NodeBID, T_node value, bool twoWay)
{
    if(m_AdjacencyMatrix[NodeAID][NodeBID] == false)
        return;
    m_VertexValues[NodeAID][NodeBID] = value;
    if(twoWay)
        m_VertexValues[NodeBID][NodeAID] = value;
}

//==================getters====================

//==================utility====================

//==================constructors & destructors====================
template <class T_node, class T_vertex>
Val_Graph<T_node, T_vertex>::Val_Graph() : Graph(), m_IsSymetricallyValued(1) { }


template <class T_node, class T_vertex>
Val_Graph<T_node, T_vertex>::Val_Graph(unsigned int _size) : Graph(_size), m_IsSymetricallyValued(1)
{
    m_NodeValues.resize(m_size);
    m_VertexValues.resize(m_size, std::vector<T_vertex>(m_size));
}


template <class T_node, class T_vertex>
Val_Graph<T_node, T_vertex>::~Val_Graph()
{

}