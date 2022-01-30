///////////////////////////////////////////////////////////////////
// NAME:               graph.cpp
//
// PURPOSE:            Method implementations of Graph class.
//
// AUTHOR:             Grubre
///////////////////////////////////////////////////////////////////

#include "graph.h"
#include <iostream>

#define MIN(x,y) x > y ? y : x


using namespace Grubre;

//==================setters====================
void Graph::add_node()
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


void Graph::add_node(const std::vector<int> &neighborIDs, bool twoWay)
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
    P_update();
}


void Graph::remove_node(int id)
{
    if(id > m_size - 1)
        return;
    m_size--;
    m_AdjacencyMatrix.erase(m_AdjacencyMatrix.begin()+id);
    for(int i = 0; i < m_size; i++)
    {
        m_AdjacencyMatrix[i].erase(m_AdjacencyMatrix[i].begin()+id);
    }

    // after removing a node we check whether the graph is directed and/or disconnected 
    P_update();
}


void Graph::add_vertex(int NodeAID, int NodeBID, bool twoWay)
{
    m_AdjacencyMatrix[NodeAID][NodeBID] = true;
    if(twoWay)
        m_AdjacencyMatrix[NodeBID][NodeAID] = true;

    // after adding a new vertex we check whether the graph is directed or/and disconnected
    P_update();
}


void Graph::remove_vertex(int NodeAID, int NodeBID, bool twoWay)
{
    m_AdjacencyMatrix[NodeAID][NodeBID] = false;
    if(twoWay)
        m_AdjacencyMatrix[NodeBID][NodeAID] = false;

    // after removing a vertex we check whether the graph is directed or/and disconnected
    P_update();
}


void Graph::clear()
{
    m_AdjacencyMatrix.clear();
    m_isConnected = 1;
    m_isUndirected = 1;
    m_size = 0;
}


//==================variable getters====================
unsigned int Graph::size() const
{
    return m_size;
}
bool Graph::is_undirected() const
{
    return m_isUndirected;
}
bool Graph::is_connected() const
{
    return m_isConnected;
}
std::vector< std::vector< bool > > Graph::getAdjacencyMatrix() const
{
    return m_AdjacencyMatrix;
}


//==================variable getters====================
bool Graph::is_cyclic() const
{
    std::vector<bool> visited(m_size,0);
    if(m_isUndirected)
    {
        //std::cout << "is_cyclic Undirected" << std::endl;
        for(int u = 0; u < m_size; u++)
        {
            if(!visited[u])
            {
                if(P_is_cyclic_util(u,visited,-1))
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
                if(P_is_cyclic_util_directed(u,visited, recStack))
                    return true;
            }
        }
    }
    return false;
}


int Graph::min_edge_count(int NodeAID, int NodeBID) const
{
    std::vector<bool> visited(m_size, false);
    std::vector<int> distance(m_size, -1);
    
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
    return distance[NodeBID];
}


std::vector<int> Graph::get_neighbors(int id) const
{
    std::vector<int> neighborList;
    for(int i = 0; i < m_size; i++)
    {
        if(m_AdjacencyMatrix[id][i])
        {
            neighborList.push_back(i);
        }
    }
    return neighborList;
}


int Graph::num_of_paths(int id, int of_length = 1) const
{
    // to do
    int number = 0;
    return number;
}


//==================utility====================
void Graph::traverse(TraverseAlgorithm alg, std::function<void(int, std::vector<bool>)> func,
    int startingPointID) const
{
    switch(alg)
    {
        case TraverseAlgorithm::DFS:
        {
            std::vector<int> visited(m_size,0);
            std::stack<int> to_visit;

            to_visit.push(startingPointID);

            while (!to_visit.empty())
            {
                int id = to_visit.top();
                to_visit.pop();
        
                if (!visited[id])
                {
                    func(id,m_AdjacencyMatrix[id]);
                    visited[id] = true;
                }
        
                for(int i = 0; i < m_size; i++)
                {
                    if(!visited[i] && m_AdjacencyMatrix[id][i])
                        to_visit.push(i);
                }
            }
            break;
        }
        case TraverseAlgorithm::BFS:
        {
            std::vector<int> visited(m_size,0);
            std::queue<int> to_visit;

            to_visit.push(startingPointID);
            visited[startingPointID] = true;
        
            while (!to_visit.empty())
            {
                int id = to_visit.front();
                to_visit.pop();

                func(id,m_AdjacencyMatrix[id]);
        
                for(int i = 0; i < m_size; i++)
                {
                    if(!visited[i] && m_AdjacencyMatrix[id][i])
                    {
                        to_visit.push(i);
                        visited[i] = true;
                    }
                }
            }
            break;
        }
    }
}


void Graph::print_adjacency_matrix() const
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


//==================private utility functions====================
bool Graph::P_is_undirected_check() const
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


bool Graph::P_is_connected_check()
{
    if(m_isUndirected)
    {
        std::vector<bool> visited(m_size,false);
        P_is_connected_check_util(visited,false);
        
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
        P_is_connected_check_util(visited1, false);
        P_is_connected_check_util(visited2, true);

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


bool Graph::P_is_cyclic_util(int v, std::vector <bool> &visited, int parent) const
{
    visited[v] = true;

    for(int i = 0; i < m_size; i++)
    {
        if(m_AdjacencyMatrix[v][i])
        {
            if(!visited[i])
            {
                if(P_is_cyclic_util(i, visited, v))
                {
                    return true;
                }     
            }
            else if(i != parent)
                return true;
        }
    }
    return false;
}


bool Graph::P_is_cyclic_util_directed(int v, std::vector <bool> &visited, std::vector <bool> &recStack) const
{
    visited[v] = true;
    recStack[v] = true;
    for(int i = 0; i < m_size; i++)
    {
        if(m_AdjacencyMatrix[v][i])
        {
            if(!visited[i])
            {
                if(P_is_cyclic_util_directed(i, visited, recStack))
                {
                    return true;
                }
            }
            else if(recStack[i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}


void Graph::P_is_connected_check_util(std::vector <bool> &visited, bool reverse) const
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


void Graph::P_update()
{
    m_isUndirected = P_is_undirected_check();
    m_isConnected = P_is_connected_check();
}


bool Graph::P_is_within_bounds(int id)
{
    return (id >= 0 && id < m_size);
}


//==================operator overloads====================
Graph Graph::operator | (Graph const &rhs)
{
    Graph lhs;
    lhs.m_AdjacencyMatrix = this->m_AdjacencyMatrix;
    lhs.m_size = this->m_size;
    for(int i = 0; i < lhs.size(); i++)
    {
        for(int j = 0; j < rhs.m_size; j++)
        {
            lhs.m_AdjacencyMatrix[i].push_back(false);
        }
    }
    std::vector<bool> prefix(lhs.m_size, false);
    for(int j = 0; j < rhs.m_size; j++)
    {
        std::vector<bool> row(prefix);
        row.insert(row.end(), rhs.m_AdjacencyMatrix[j].begin(), rhs.m_AdjacencyMatrix[j].end());
        lhs.m_AdjacencyMatrix.push_back(row);
    }
    lhs.m_size = lhs.m_size + rhs.m_size;
    lhs.P_update();
    return lhs;
}


bool Graph::operator == (Graph const &rhs)
{
    return this->m_AdjacencyMatrix == rhs.m_AdjacencyMatrix;
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
