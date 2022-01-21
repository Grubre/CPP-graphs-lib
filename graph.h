#pragma once
#include <vector>


class Graph{
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

//utility functions
public:

//constructors & destructors
public:
    Graph();
    Graph(unsigned int _size);
    ~Graph();

//variables
protected:
    unsigned int m_size;

    std::vector< std::vector< bool > > m_AdjacencyMatrix;
};