#include "graph.h"
#include <iostream>


//=========setters===========
void Graph::addNode()
{
    for(int i = 0; i < m_size; i++)
    {
        m_AdjacencyMatrix[i].push_back(false);
    }
    m_size++;
    m_AdjacencyMatrix.push_back(std::vector<bool>(m_size, false));
}


void Graph::removeNode(int id)
{
    if(id > m_size - 1)
        return;
    m_size--;
    m_AdjacencyMatrix.erase(m_AdjacencyMatrix.begin()+id);
    for(int i = 0; i < m_size; i++)
    {
        m_AdjacencyMatrix[i].erase(m_AdjacencyMatrix[i].begin()+id);
    }
}


void Graph::addVertex(int NodeAID, int NodeBID, bool twoWay)
{
    m_AdjacencyMatrix[NodeAID][NodeBID] = true;
    if(twoWay)
        m_AdjacencyMatrix[NodeBID][NodeAID] = true;
}


void Graph::removeVertex(int NodeAID, int NodeBID, bool twoWay)
{
    m_AdjacencyMatrix[NodeAID][NodeBID] = false;
    if(twoWay)
        m_AdjacencyMatrix[NodeBID][NodeAID] = false;
}


void Graph::printAdjacencyMatrix()
{
    for(int i = 0; i < m_size; i++)
    {
        for(int j = 0; j < m_size; j++)
        {
            std::cout << m_AdjacencyMatrix[i][j] << " ";
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
    m_AdjacencyMatrix.resize(m_size, std::vector<bool>(m_size, false));
}


Graph::~Graph()
{

}