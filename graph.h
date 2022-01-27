#pragma once
#include <vector>
#include <queue>
#include <stack>


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

//variable getters
public:
    unsigned int size() const;
    bool isUndirected() const;
    bool isConnected() const;

//algorithmic getters
    bool isCyclic();
    int minEdgeCount(int NodeAID, int NodeBID); // TO DO FOR DIRECTED

//utility functions
public:
    void traverse(TraverseAlgorithm alg, int startingPointID, void(*func)(unsigned int, 
    std::vector< bool >)); // TO DO

    void printAdjacencyMatrix() const;

//private utility functions
private:
    bool isConnectedCheck(); // algorithm that checks whether the graph is connected
    bool isUndirectedCheck() const; // algorithm that checks whether the graph is undirected

    void isConnectedCheckUtil(std::vector <bool> &visited, bool reverse);

    bool isCyclicUtil(int v, std::vector <bool> &visited, int parent);
    bool isCyclicUtilDirected(int v, std::vector <bool> &visited, std::vector <bool> &recStack);

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