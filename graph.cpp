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

    // after adding a new node the graph is disconnected
    // unless it's size was 0
    m_isConnected = (m_size == 1);
}


void Graph::addNode(const std::vector<int> &neighborIDs, bool twoWay)
{
    std::vector<bool> neighborVector(m_size+1,0);
    for(auto i : neighborIDs)
        neighborVector[i] = true;
    for(int i = 0; i < m_size; i++)
    {
        m_AdjacencyMatrix[i].push_back(twoWay && neighborVector[i]);
    }
    m_size++;
    m_AdjacencyMatrix.push_back(neighborVector);

    // after adding a new node with init list we check whether the graph is disconnected
    // and/or directed
    update();
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

    // after removing a node we check whether the graph is disconnected
    m_isConnected = isConnected();
}


void Graph::addVertex(int NodeAID, int NodeBID, bool twoWay)
{
    m_AdjacencyMatrix[NodeAID][NodeBID] = true;
    if(twoWay)
        m_AdjacencyMatrix[NodeBID][NodeAID] = true;

    // after adding a new vertex we check whether the graph is directed or/and disconnected
    update();
}


void Graph::removeVertex(int NodeAID, int NodeBID, bool twoWay)
{
    m_AdjacencyMatrix[NodeAID][NodeBID] = false;
    if(twoWay)
        m_AdjacencyMatrix[NodeBID][NodeAID] = false;

    // after removing a vertex we check whether the graph is directed or/and disconnected
    update();
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


bool Graph::isCyclic()
{
    std::vector<bool> visited(m_size,0);
    if(m_isUndirected)
    {
        for(int u = 0; u < m_size; u++)
        {
            if(!visited[u])
            {
                if(isCyclicUtil(u,visited,-1))
                    return true;
            }
        }
    }
    else
    {
        std::vector<bool> recStack(m_size,0);
        for(int u = 0; u < m_size; u++)
        {
            if(!visited[u])
            {
                if(isCyclicUtilDirected(u,visited, recStack))
                    return true;
            }
        }
        // TO DO
    }
    return false;
}


bool Graph::isConnected()
{
    if(m_isUndirected)
    {
        std::vector<bool> visited(m_size,false);
        std::queue<int> to_visit;
        to_visit.push(0);
        visited[0] = true;
        while(!to_visit.empty())
        {
            int id = to_visit.front();
            
            for(int i = 0; i < m_size; i++)
            {
                if(!visited[i] && m_AdjacencyMatrix[id][i])
                {
                    to_visit.push(i);
                    visited[i] = true;
                }
            }
            to_visit.pop();
        }
        for(int i = 0; i < m_size; i++)
            if(!visited[i])
            {
                m_isConnected = false;
                return false; 
            }
    }
    else
    {
        std::vector<bool> visited1(m_size,false);
        std::vector<bool> visited2(m_size,false);

        std::queue<int> to_visit;
        isConnectedUtil(visited1, false);
        isConnectedUtil(visited2, true);

        for(int i = 0; i < m_size; i++)
            if(!visited1[i] && !visited2[i])
            {
                m_isConnected = false;
                return false;
            }
    }
    m_isConnected = true;
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


int Graph::minEdgeCount(int NodeAID, int NodeBID)
{
    int dist;
    if(m_isUndirected)
    {
        std::vector<bool> visited(m_size, false);
        std::vector<int> distance(m_size, 0);
        
        std::queue <int> to_visit;
        distance[NodeAID] = 0;
    
        to_visit.push(NodeAID);
        visited[NodeAID] = true;

        while (!to_visit.empty())
        {
            int id = to_visit.front();
            to_visit.pop();

            for(int i = 0; i < m_size; i++)
            {
                if(visited[i] || !m_AdjacencyMatrix[id][i])
                    continue;

                distance[i] = distance[id] + 1;
                to_visit.push(i);
                visited[i] = true;
            }
        }
        dist = distance[NodeBID];
    }
    else
    {
        std::cout << "Edge count is not implemented yet for directed graphs" << std::endl;
    }
    return dist;
}

//==================private utility functions====================
bool Graph::isCyclicUtil(int v, std::vector <bool> &visited, int parent)
{
    visited[v] = true;

    for(int i = 0; i < m_size; i++)
    {
        if(m_AdjacencyMatrix[v][i])
        {
            if(!visited[i] && isCyclicUtil(i, visited, v))
            {
                return true;
            }
            else if(i != parent)
                return true;
        }
    }
    return false;
}


bool Graph::isCyclicUtilDirected(int v, std::vector <bool> &visited, std::vector <bool> &recStack)
{
    visited[v] = true;
    recStack[v] = true;
    for(int i = 0; i < m_size; i++)
    {
        if(m_AdjacencyMatrix[v][i])
        {
            if(!visited[i] && isCyclicUtilDirected(i, visited, recStack))
            {
                return true;
            }
            else if(recStack[i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}


void Graph::isConnectedUtil(std::vector <bool> &visited, bool reverse)
{
    std::queue<int> to_visit;
    to_visit.push(0);
    visited[0] = true;
    while(!to_visit.empty())
    {
        int id = to_visit.front();
        
        for(int i = 0; i < m_size; i++)
        {
            if(!visited[i] && (m_AdjacencyMatrix[id][i] || (m_AdjacencyMatrix[i][id] && reverse)))
            {
                to_visit.push(i);
                visited[i] = true;
            }
        }
        to_visit.pop();
    }
}


void Graph::update()
{
    m_isConnected = isConnected();
    m_isUndirected = isUndirected();
}

//==================contructors & destructors====================
Graph::Graph() : m_size(0)
{
    m_isUndirected = true;
    m_isConnected = true;
}


Graph::Graph(unsigned int _size) : m_size(_size)
{
    m_isUndirected = true;
    m_isConnected = (m_size <= 1);
    m_AdjacencyMatrix.resize(m_size, std::vector<bool>(m_size, false));
}


Graph::~Graph()
{

}
