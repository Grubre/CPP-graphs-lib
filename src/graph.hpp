#pragma once
///////////////////////////////////////////////////////////////////
// NAME:               graph.hpp
//
// PURPOSE:            Declaration and Implementation of the Graph class.
//                     It's a graph model that includes template values
//                     for nodes and vertices, traversal algortihms(DFS, BFS)
//                     and functionality such as finding the shortest path,
//                     counting the number of paths between two nodes and
//                     keeping track of whether the graph is cyclic, directed
//                     or connected.
//
// AUTHOR:             Grubre
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <utility>

namespace Grubre{
template <class T_node, class T_vertex>  
class Graph{
protected:
    struct Vertex{
        int first, second;
        Vertex(int _f, int _s) : first(_f), second(_s) {}
        Vertex reverse(){return Vertex(second,first);}
    };
public:
    enum class TraverseAlgorithm
    {
        DFS,
        BFS
    };

//setters
public:
    //nodes
    void add(const T_node& value = T_node());
    void remove(int id);

    //vertices
    void add(const Vertex &id, const T_vertex& value = T_vertex(), bool twoWay = true);
    void remove(const Vertex &id, bool twoWay = true);

    void clear(); 

//variable getters
public:
    unsigned int size() const;
    bool is_undirected() const;
    bool is_connected() const;

    std::vector< std::vector< bool > > getAdjacencyMatrix() const;

//algorithmic getters
    bool is_cyclic() const;
    int min_edge_count(const std::pair<int,int> &id) const;
    int num_of_paths(int id1, int id2, int of_length = 1);// TO DO

    std::vector<int> get_neighbors(int id) const;

//utility functions
public:
    void traverse(TraverseAlgorithm alg, std::function<void(int, T_node, std::vector<bool>)> func,
    int startingPointID = 0) const;

    // for testing purposes only, to be removed
    void print_adjacency_matrix() const;

    void print_node_values();
    void print_vertex_values();

//constructors & destructors
public:
    Graph();
    Graph(unsigned int _size);
    ~Graph();

//private utility functions
private:
    std::vector<std::vector<int>> multiply_matrix(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b);

    bool P_is_connected_check(); // algorithm that checks whether the Graph is connected
    bool P_is_undirected_check() const; // algorithm that checks whether the Graph is undirected

    void P_is_connected_check_util(std::vector <bool> &visited, bool reverse) const;

    bool P_is_cyclic_util(int v, std::vector <bool> &visited, unsigned int parent) const;
    bool P_is_cyclic_util_directed(int v, std::vector <bool> &visited, std::vector <bool> &recStack) const;

    void P_update();

    bool P_is_within_bounds(unsigned int id);

//operator overloads
public:
    //concatenate operator
    Graph operator | (Graph const &rhs);
    //equality operator
    bool operator == (Graph const &rhs);

    T_node& operator[](int);
    T_vertex& operator[](Vertex);

//variables
protected:
    unsigned int m_size;

    bool m_isUndirected;
    bool m_isConnected;

    std::vector< std::vector< bool > > m_AdjacencyMatrix;

    std::vector<std::vector<T_vertex>> m_VertexValues;
    std::vector<T_node> m_NodeValues;

};

//==================setters====================
template <class T_node, class T_vertex>
void Graph<T_node,T_vertex>::add(const T_node& value)
{
    for(unsigned int i = 0; i < m_size; i++)
    {
        m_AdjacencyMatrix[i].push_back(false);
    }
    m_size++;
    m_AdjacencyMatrix.push_back(std::vector<bool>(m_size, false));

    // after adding a new node the Graph is disconnected
    // unless it's size was 0
    m_isConnected = (m_size == 1);

    for(int i = 0; i < m_size - 1; i++)
    {
        m_VertexValues[i].push_back(T_vertex());
    }
    m_VertexValues.push_back(std::vector<T_vertex>(m_size));
    m_NodeValues.push_back(value);
}

template <class T_node, class T_vertex>
void Graph<T_node,T_vertex>::remove(int id)
{
    m_size--;
    m_AdjacencyMatrix.erase(m_AdjacencyMatrix.begin()+id);
    for(unsigned int i = 0; i < m_size; i++)
    {
        m_AdjacencyMatrix[i].erase(m_AdjacencyMatrix[i].begin()+id);
    }

    // after removing a node we check whether the Graph is directed and/or disconnected 
    P_update();

    m_NodeValues.erase(m_NodeValues.begin()+id);
    m_VertexValues.erase(m_VertexValues.begin()+id);
    for(int i = 0; i < m_size; i++)
    {
        m_VertexValues[i].erase(m_VertexValues[i].begin()+id);
    }
}

template <class T_node, class T_vertex>
void Graph<T_node,T_vertex>::add(const Vertex &id, const T_vertex& value, bool twoWay)
{
    m_AdjacencyMatrix[id.first][id.second] = true;
    if(twoWay)
        m_AdjacencyMatrix[id.second][id.first] = true;

    // after adding a new vertex we check whether the Graph is directed or/and disconnected
    P_update();

    m_VertexValues[id.first][id.second] = value;
    if(twoWay)
        m_VertexValues[id.second][id.first] = value;
}

template <class T_node, class T_vertex>
void Graph<T_node,T_vertex>::remove(const Vertex &id, bool twoWay)
{
    m_AdjacencyMatrix[id.first][id.second] = false;
    if(twoWay)
        m_AdjacencyMatrix[id.first][id.second] = false;

    // after removing a vertex we check whether the Graph is directed or/and disconnected
    P_update();

    m_VertexValues[id.first][id.second] = T_vertex();
    m_VertexValues[id.second][id.first] = T_vertex();
}

template <class T_node, class T_vertex>
void Graph<T_node,T_vertex>::clear()
{
    m_AdjacencyMatrix.clear();
    m_isConnected = 1;
    m_isUndirected = 1;
    m_size = 0;

    m_VertexValues.clear();
    m_NodeValues.clear();
}


//==================variable getters====================
template <class T_node, class T_vertex>
unsigned int Graph<T_node,T_vertex>::size() const
{
    return m_size;
}
template <class T_node, class T_vertex>
bool Graph<T_node,T_vertex>::is_undirected() const
{
    return m_isUndirected;
}
template <class T_node, class T_vertex>
bool Graph<T_node,T_vertex>::is_connected() const
{
    return m_isConnected;
}
template <class T_node, class T_vertex>
std::vector< std::vector< bool > > Graph<T_node,T_vertex>::getAdjacencyMatrix() const
{
    return m_AdjacencyMatrix;
}


//==================variable getters====================
template <class T_node, class T_vertex>
bool Graph<T_node,T_vertex>::is_cyclic() const
{
    std::vector<bool> visited(m_size,0);
    if(m_isUndirected)
    {
        //std::cout << "is_cyclic Undirected" << std::endl;
        for(unsigned int u = 0; u < m_size; u++)
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
        for(unsigned int u = 0; u < m_size; u++)
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

template <class T_node, class T_vertex>
int Graph<T_node,T_vertex>::min_edge_count(const std::pair<int,int> &id) const
{
    std::vector<bool> visited(m_size, false);
    std::vector<int> distance(m_size, -1);
    
    std::queue <int> to_visit;
    distance[id.first] = 0;

    to_visit.push(id.first);
    visited[id.first] = true;

    while (!to_visit.empty())
    {
        int id = to_visit.front();
        to_visit.pop();

        for(unsigned int i = 0; i < m_size; i++)
        {
            if(visited[i] || !m_AdjacencyMatrix[id][i])
                continue;

            distance[i] = distance[id] + 1;
            to_visit.push(i);
            visited[i] = true;
        }
    }
    return distance[id.second];
}

template <class T_node, class T_vertex>
std::vector<int> Graph<T_node,T_vertex>::get_neighbors(int id) const
{
    std::vector<int> neighborList;
    for(unsigned int i = 0; i < m_size; i++)
    {
        if(m_AdjacencyMatrix[id][i])
        {
            neighborList.push_back(i);
        }
    }
    return neighborList;
}

template <class T_node, class T_vertex>
int Graph<T_node,T_vertex>::num_of_paths(int id1, int id2, int of_length)
{
    // to do
    std::vector<std::vector<int>> ret;
    ret.resize(m_size,std::vector<int>(m_size,0));
    for(unsigned int i = 0; i < m_size; i++)
        ret[i][i] = 1;

    std::vector<std::vector<int>> a;
    a.resize(m_size,std::vector<int>(m_size));
    for(unsigned int i = 0; i < m_size; i++)
        for(unsigned int j = 0; j < m_size; j++)
            a[i][j] = m_AdjacencyMatrix[i][j];

    while(of_length > 0)
    {
        if(of_length % 2 == 1)
            ret = multiply_matrix(ret, a);
        a = multiply_matrix(a,a);
        of_length /= 2;
    }

    return ret[id1][id2];
}


//==================utility====================
template <class T_node, class T_vertex>
void Graph<T_node,T_vertex>::traverse(TraverseAlgorithm alg, std::function<void(int, T_node, std::vector<bool>)> func,
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
                    func(id,m_NodeValues[id],m_AdjacencyMatrix[id]);
                    visited[id] = true;
                }
        
                for(unsigned int i = 0; i < m_size; i++)
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
            int a = 1;
        
            while (!to_visit.empty())
            {
                int id = to_visit.front();
                to_visit.pop();

                func(id,m_NodeValues[id],m_AdjacencyMatrix[id]);
        
                for(unsigned int i = 0; i < m_size; i++)
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

template <class T_node, class T_vertex>
void Graph<T_node,T_vertex>::print_adjacency_matrix() const
{
    for(unsigned int i = 0; i < m_size; i++)
    {
        for(unsigned int j = 0; j < m_size; j++)
        {
            std::cout << m_AdjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


template <class T_node, class T_vertex>
void Graph<T_node,T_vertex>::print_node_values()
{
    for(int i = 0; i < m_size; i++)
    {
        std::cout << m_NodeValues[i] << " ";
    }
    std::cout << std::endl;
}


template <class T_node, class T_vertex>
void Graph<T_node,T_vertex>::print_vertex_values()
{
    for(int i = 0; i < m_size; i++)
    {
        for(int j = 0; j < m_size; j++)
            std::cout << m_VertexValues[i][j] << " ";
        std::cout << std::endl;
    }
}


//==================private utility functions====================
template <class T_node, class T_vertex>
std::vector<std::vector<int>> Graph<T_node,T_vertex>::multiply_matrix(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b) 
{
    int s = a.size();

    std::vector<std::vector<int>> ret;
    ret.resize(s,std::vector<int>(s));
    
    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < s; j++)
        {
            int val = 0;
            for(int y = 0; y < s; y++)
            {
                val += a[i][y] * b[y][j];
            }
            ret[i][j] = val;
        }
    }

    return ret;
}

template <class T_node, class T_vertex>
bool Graph<T_node,T_vertex>::P_is_undirected_check() const
{
    for(unsigned int i = 0; i < m_size; i++)
    {
        for(unsigned int j = 0; j < m_size; j++)
        {
            if(m_AdjacencyMatrix[i][j] != m_AdjacencyMatrix[j][i])
                return false;
        }
    }
    return true;
}

template <class T_node, class T_vertex>
bool Graph<T_node,T_vertex>::P_is_connected_check()
{
    if(m_isUndirected)
    {
        std::vector<bool> visited(m_size,false);
        P_is_connected_check_util(visited,false);
        
        for(unsigned int i = 0; i < m_size; i++)
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

        for(unsigned int i = 0; i < m_size; i++)
            if(!visited1[i] && !visited2[i])
            {
                m_isConnected = false;
                return false;
            }
    }
    m_isConnected = true;
    return true;
}

template <class T_node, class T_vertex>
bool Graph<T_node,T_vertex>::P_is_cyclic_util(int v, std::vector <bool> &visited, unsigned int parent) const
{
    visited[v] = true;

    for(unsigned int i = 0; i < m_size; i++)
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

template <class T_node, class T_vertex>
bool Graph<T_node,T_vertex>::P_is_cyclic_util_directed(int v, std::vector <bool> &visited, std::vector <bool> &recStack) const
{
    visited[v] = true;
    recStack[v] = true;
    for(unsigned int i = 0; i < m_size; i++)
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

template <class T_node, class T_vertex>
void Graph<T_node,T_vertex>::P_is_connected_check_util(std::vector <bool> &visited, bool reverse) const
{
    std::queue<int> to_visit;
    to_visit.push(0);
    visited[0] = true;
    while(!to_visit.empty())
    {
        int id = to_visit.front();
        
        for(unsigned int i = 0; i < m_size; i++)
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

template <class T_node, class T_vertex>
void Graph<T_node,T_vertex>::P_update()
{
    m_isUndirected = P_is_undirected_check();
    m_isConnected = P_is_connected_check();
}

template <class T_node, class T_vertex>
bool Graph<T_node,T_vertex>::P_is_within_bounds(unsigned int id)
{
    return (id >= 0 && id < m_size);
}


//==================operator overloads====================
template <class T_node, class T_vertex>
Graph<T_node,T_vertex> Graph<T_node,T_vertex>::operator | (Graph<T_node,T_vertex> const &rhs)
{
    Graph lhs;
    lhs.m_AdjacencyMatrix = this->m_AdjacencyMatrix;
    lhs.m_size = this->m_size;
    lhs.m_NodeValues = this->m_NodeValues;
    lhs.m_VertexValues = this->m_VertexValues;
    lhs.m_NodeValues.insert(lhs.m_NodeValues.end(), rhs.m_NodeValues.begin(), rhs.m_NodeValues.end());
    lhs.m_VertexValues.insert(lhs.m_VertexValues.end(), rhs.m_VertexValues.begin(), rhs.m_VertexValues.end());
    for(unsigned int i = 0; i < lhs.size(); i++)
    {
        for(unsigned int j = 0; j < rhs.m_size; j++)
        {
            lhs.m_AdjacencyMatrix[i].push_back(false);
        }
    }
    std::vector<bool> prefix(lhs.m_size, false);
    for(unsigned int j = 0; j < rhs.m_size; j++)
    {
        std::vector<bool> row(prefix);
        row.insert(row.end(), rhs.m_AdjacencyMatrix[j].begin(), rhs.m_AdjacencyMatrix[j].end());
        lhs.m_AdjacencyMatrix.push_back(row);
    }
    lhs.m_size = lhs.m_size + rhs.m_size;
    lhs.P_update();
    return lhs;
}

template <class T_node, class T_vertex>
bool Graph<T_node,T_vertex>::operator == (Graph const &rhs)
{
    return this->m_AdjacencyMatrix == rhs.m_AdjacencyMatrix;
}

template <class T_node, class T_vertex>
T_node& Graph<T_node,T_vertex>::operator[](int id)
{
    return m_NodeValues[id];
}
template <class T_node, class T_vertex>
T_vertex& Graph<T_node,T_vertex>::operator[](Vertex id)
{
    if(!m_AdjacencyMatrix[id.first][id.second])
        add(id,T_vertex(),false);
    return m_VertexValues[id.first][id.second];
}

//==================contructors & destructors====================
template <class T_node, class T_vertex>
Graph<T_node,T_vertex>::Graph() : m_size(0)
{
    m_isUndirected = true;
    m_isConnected = true;
}

template <class T_node, class T_vertex>
Graph<T_node,T_vertex>::Graph(unsigned int _size) : m_size(_size)
{
    m_isUndirected = true;
    m_isConnected = (m_size <= 1);
    m_AdjacencyMatrix.resize(m_size, std::vector<bool>(m_size, false));

    m_VertexValues.resize(m_size, std::vector<T_vertex>(m_size));
    m_NodeValues.resize(m_size, T_node());
}

template <class T_node, class T_vertex>
Graph<T_node,T_vertex>::~Graph()
{
    
}

};

