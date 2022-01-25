#include "graph.h"
#include <iostream>


//==================setters====================
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

    // after adding a new vertex we check whether the graph is directed
    m_isUndirected = isUndirected();
}


void Graph::removeVertex(int NodeAID, int NodeBID, bool twoWay)
{
    m_AdjacencyMatrix[NodeAID][NodeBID] = false;
    if(twoWay)
        m_AdjacencyMatrix[NodeBID][NodeAID] = false;

    // after removing a vertex we check whether the graph is directed
    m_isUndirected = isUndirected();
}


//==================getters====================
unsigned int Graph::size() const
{
    return m_size;
}


void Graph::printAdjacencyMatrix() const
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


bool Graph::isUndirected() const
{
    for(int i = 0; i < m_size; i++)
    {
        for(int j = 0; j < m_size; j++)
        {
            if(m_AdjacencyMatrix[i][j] != m_AdjacencyMatrix[j][i])
                return false;
        }
    }
    return true;
}


//==================utility====================
void Graph::traverse(TraverseAlgorithm alg, int startingPointID, void(*func)( unsigned int, 
    std::vector< bool >))
{
    switch(alg)
    {
        case TraverseAlgorithm::DFS:

        break;
        case TraverseAlgorithm::BFS:
        
        break;
    }
}


//==================contructors & destructors====================
Graph::Graph() : m_size(0), m_isUndirected(0)
{

}


Graph::Graph(unsigned int _size) : m_size(_size), m_isUndirected(0)
{
    m_AdjacencyMatrix.resize(m_size, std::vector<bool>(m_size, false));
}


Graph::~Graph()
{

}
