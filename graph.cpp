#include "graph.h"
#include <iostream>


//=========setters===========
void Graph::addNode(int value)
{
    for(int i = 0; i < m_size; i++)
    {
        m_AdjacencyList[i].push_back(false);
    }
    m_size++;
    m_AdjacencyList.push_back(std::vector<bool>(m_size, false));
}


void Graph::removeNode(int id)
{
    if(id > m_size - 1)
        return;
    m_size--;
    m_AdjacencyList.erase(m_AdjacencyList.begin()+id);
    for(int i = 0; i < m_size; i++)
    {
        m_AdjacencyList[i].erase(m_AdjacencyList[i].begin()+id);
    }
}


void Graph::removeNodesByValue(int value)
{

}


void Graph::setNodeValue(int id, int value)
{

}



void Graph::addVertex(int NodeAID, int NodeBID, bool twoWay, int value)
{
    m_AdjacencyList[NodeAID][NodeBID] = true;
    if(twoWay)
        m_AdjacencyList[NodeBID][NodeAID] = true;
}


void Graph::removeVertex(int NodeAID, int NodeBID, bool twoWay)
{
    m_AdjacencyList[NodeAID][NodeBID] = false;
    if(twoWay)
        m_AdjacencyList[NodeBID][NodeAID] = false;
}


void Graph::removeVertexesByValue(int value)
{

}


void Graph::setVertexValue(int NodeAID, int NodeBID, int value)
{

}


void Graph::printAdjacencyList()
{
    for(int i = 0; i < m_size; i++)
    {
        for(int j = 0; j < m_size; j++)
        {
            std::cout << m_AdjacencyList[i][j] << " ";
        }
        std::cout << std::endl;
    }
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


//=========utility===========
Graph::Graph(unsigned int _size) : m_size(_size)
{
    m_AdjacencyList.reserve(_size);
}


Graph::~Graph()
{

}