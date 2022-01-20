#pragma once
#include <vector>

class Graph{
//setters
public:
    void resize(unsigned int _size);
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
};