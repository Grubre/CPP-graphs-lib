#pragma once
#include <vector>


class Graph{
//setters
public:
    void addNode(int value);
    void removeNode(int id);
    void removeNodesByValue(int value);
    void setNodeValue(int id, int value);

    void addVertex(int NodeAID, int NodeBID, int value = 0);
    void removeVertex(int NodeAID, int NodeBID);
    void removeVertexesByValue(int value);
    void setVertexValue(int NodeAID, int NodeBID, int value);
//getters
public:
    unsigned int size() const;
//constructors & destructors
public:
    Graph();
    Graph(unsigned int _size);
    ~Graph();
//variables
private:
    unsigned int m_size;

    std::vector<int> m_NodeList;
    std::vector<std::vector<int>> m_AdjacencyList;
};