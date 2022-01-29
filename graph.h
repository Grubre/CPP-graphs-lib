#pragma once
#include <vector>
#include <queue>
#include <stack>
#include <functional>


class Graph{
public:
    enum class TraverseAlgorithm
    {
        DFS,
        BFS
    };
        
//setters
public:
    void addNode();
    void addNode(const std::vector<int> &neighborIDs, bool twoWay = true);
    void removeNode(int id);

    void addVertex(int NodeAID, int NodeBID, bool twoWay = true);
    void removeVertex(int NodeAID, int NodeBID, bool twoWay = true);

//variable getters
public:
    unsigned int size() const;
    bool isUndirected() const;
    bool isConnected() const;

    std::vector< std::vector< bool > > getAdjacencyMatrix() const;

//algorithmic getters
    bool isCyclic() const;
    int minEdgeCount(int NodeAID, int NodeBID) const;

    std::vector<int> getNeighbors(int id) const;

//utility functions
public:
    void traverse(TraverseAlgorithm alg, std::function<void(int, std::vector<bool>)> func,
    int startingPointID = 0) const;

    // for testing purposes only, to be removed
    void printAdjacencyMatrix() const;

//constructors & destructors
public:
    Graph();
    Graph(unsigned int _size);
    ~Graph();

//private utility functions
private:
    bool isConnectedCheck(); // algorithm that checks whether the graph is connected
    bool isUndirectedCheck() const; // algorithm that checks whether the graph is undirected

    void isConnectedCheckUtil(std::vector <bool> &visited, bool reverse) const;

    bool isCyclicUtil(int v, std::vector <bool> &visited, int parent) const;
    bool isCyclicUtilDirected(int v, std::vector <bool> &visited, std::vector <bool> &recStack) const;

    void update();

    bool isWithinBounds(int id);

//variables
protected:
    unsigned int m_size;

    bool m_isUndirected;
    bool m_isConnected;
    bool m_isWeighted;

    std::vector< std::vector< bool > > m_AdjacencyMatrix;
};