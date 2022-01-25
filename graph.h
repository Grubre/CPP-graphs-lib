#pragma once
#include <vector>


class Graph{
private:
    enum class TraverseAlgorithm
    {
        DFS,
        BFS
    };
        
//setters
public:
    void addNode();
    void addNode(const std::vector<int> &neighborIDs);
    void removeNode(int id);

    void addVertex(int NodeAID, int NodeBID, bool twoWay = true);
    void removeVertex(int NodeAID, int NodeBID, bool twoWay = true);

//getters
public:
    unsigned int size() const;

    void printAdjacencyMatrix() const;

    bool isUndirected() const;
    bool isCyclic();
    bool isDisconnected();

//utility functions
public:
    void traverse(TraverseAlgorithm alg, int startingPointID, void(*func)(unsigned int, 
    std::vector< bool >));

    int minEdgeCount(int NodeAID, int NodeBID); // TO DO

//private utility functions
private:
    bool isCyclicUtil(int v, std::vector <bool> &visited, int parent);

//constructors & destructors
public:
    Graph();
    Graph(unsigned int _size);
    ~Graph();

//variables
protected:
    unsigned int m_size;

    bool m_isUndirected;
    bool m_isDisconnected;
    bool m_isWeighted;

    std::vector< std::vector< bool > > m_AdjacencyMatrix;
};