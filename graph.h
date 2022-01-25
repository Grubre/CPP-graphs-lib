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
    void removeNode(int id);

    void addVertex(int NodeAID, int NodeBID, bool twoWay = true);
    void removeVertex(int NodeAID, int NodeBID, bool twoWay = true);

//getters
public:
    unsigned int size() const;

    void printAdjacencyMatrix() const;

    bool isUndirected() const;

//utility functions
public:
    void traverse(TraverseAlgorithm alg, int startingPointID, void(*func)(unsigned int, 
    std::vector< bool >));
    unsigned int countCycles();

//constructors & destructors
public:
    Graph();
    Graph(unsigned int _size);
    ~Graph();

//variables
protected:
    unsigned int m_size;

    bool m_isUndirected;

    std::vector< std::vector< bool > > m_AdjacencyMatrix;
};