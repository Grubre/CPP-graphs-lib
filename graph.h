#ifndef _GRAPH_H
#define _GRAPH_H
///////////////////////////////////////////////////////////////////
// NAME:               graph.h
//
// PURPOSE:            Definition of Graph class. This is a simple
//                     unweighted graph that serves as a base for
//                     all the other graph classes
//
// AUTHOR:             Grubre
///////////////////////////////////////////////////////////////////


#include <vector>
#include <queue>
#include <stack>
#include <functional>

namespace Grubre
{
class Graph{
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

    void clear();

//variable getters
public:
    unsigned int size() const;
    bool is_undirected() const;
    bool is_connected() const;

    std::vector< std::vector< bool > > getAdjacencyMatrix() const;

//algorithmic getters
    bool is_cyclic() const;
    int min_edge_count(int NodeAID, int NodeBID) const;
    int num_of_paths(int id, int of_length = 1) const;// TO DO

    std::vector<int> get_neighbors(int id) const;

//utility functions
public:
    void traverse(TraverseAlgorithm alg, std::function<void(int, std::vector<bool>)> func,
    int startingPointID = 0) const;

    // for testing purposes only, to be removed
    void print_adjacency_matrix() const;

//constructors & destructors
public:
    Graph();
    Graph(unsigned int _size);
    ~Graph();

//private utility functions
private:
    bool P_is_connected_check(); // algorithm that checks whether the graph is connected
    bool P_is_undirected_check() const; // algorithm that checks whether the graph is undirected

    void P_is_connected_check_util(std::vector <bool> &visited, bool reverse) const;

    bool P_is_cyclic_util(int v, std::vector <bool> &visited, int parent) const;
    bool P_is_cyclic_util_directed(int v, std::vector <bool> &visited, std::vector <bool> &recStack) const;

    void P_update();

    bool P_is_within_bounds(int id);

//operator overloads
public:
    //concatenate operator
    Graph operator | (Graph const &rhs);
    //equality operator
    bool operator == (Graph const &rhs);

//variables
protected:
    unsigned int m_size;

    bool m_isUndirected;
    bool m_isConnected;
    bool m_isWeighted;

    std::vector< std::vector< bool > > m_AdjacencyMatrix;
};
};
#endif //_GRAPH_H