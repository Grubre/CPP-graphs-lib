#pragma once
#include <vector>
#include <queue>


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
    void addNode(const std::vector<int> &neighborIDs, bool twoWay = true);
    void removeNode(int id);

    void addVertex(int NodeAID, int NodeBID, bool twoWay = true);
    void removeVertex(int NodeAID, int NodeBID, bool twoWay = true);

//getters
public:
    unsigned int size() const;

    void printAdjacencyMatrix() const;

    bool isUndirected() const;
    bool isCyclic();
    bool isConnected();

//utility functions
public:
    void traverse(TraverseAlgorithm alg, int startingPointID, void(*func)(unsigned int, 
    std::vector< bool >)); // TO DO

    int minEdgeCount(int NodeAID, int NodeBID); // TO DO

//private utility functions
private:
    bool isCyclicUtil(int v, std::vector <bool> &visited, int parent);
    bool isCyclicUtilDirected(int v, std::vector <bool> &visited, std::vector <bool> &recStack);

    void isConnectedUtil(std::vector <bool> &visited, bool reverse);

    void update();

//constructors & destructors
public:
    Graph();
    Graph(unsigned int _size);
    ~Graph();

//variables
protected:
    unsigned int m_size;

    bool m_isUndirected;
    bool m_isConnected;
    bool m_isWeighted;

    std::vector< std::vector< bool > > m_AdjacencyMatrix;
};