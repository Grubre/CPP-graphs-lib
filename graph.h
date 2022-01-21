#pragma once
#include <vector>


class Graph{
//setters
public:
    void addNode(int value = 0);
    void removeNode(int id);
    void removeNodesByValue(int value);
    void setNodeValue(int id, int value);

    void addVertex(int NodeAID, int NodeBID, bool twoWay = true, int value = 0);
    void removeVertex(int NodeAID, int NodeBID, bool twoWay = true);
    void removeVertexesByValue(int value);
    void setVertexValue(int NodeAID, int NodeBID, int value);

    void printAdjacencyList();
//getters
public:
    unsigned int size() const;
//constructors & destructors
public:
    Graph();
    Graph(unsigned int _size);
    ~Graph();
//utility functions
private:

//variables
private:
    unsigned int m_size;

    std::vector<std::vector<bool>> m_AdjacencyList;
};