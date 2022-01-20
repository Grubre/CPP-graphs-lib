#include "graph.h"
#include <iostream>


//=========setters===========
void Graph::addNode(int value = 0)
{

}


void Graph::removeNode(int id)
{

}


void Graph::removeNodesByValue(int value)
{

}


void Graph::setNodeValue(int id, int value)
{

}



void Graph::addVertex(int NodeAID, int NodeBID, int value = 0)
{

}


void Graph::removeVertex(int NodeAID, int NodeBID)
{

}


void Graph::removeVertexesByValue(int value = 0)
{

}


void Graph::setVertexValue(int NodeAID, int NodeBID, int value)
{

}


//=========getters===========
unsigned int Graph::size() const
{
    return m_size;
}


//=========contructors & destructors===========
Graph::Graph() : m_size(0)
{

}


Graph::Graph(unsigned int _size) : m_size(_size)
{
    m_NodeList.reserve(_size);
    m_AdjacencyList.reserve(_size);
}


Graph::~Graph()
{

}