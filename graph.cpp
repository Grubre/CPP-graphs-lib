#include "graph.h"
#include <iostream>


//=========setters===========
void Graph::resize(unsigned int _size)
{
    m_size = _size;
}


//=========getters===========
unsigned int Graph::size() const
{
    return m_size;
}


//=========contructors & destructors===========
Graph::Graph() : m_size(0)
{

}


Graph::Graph(unsigned int _size) : m_size(_size)
{

}


Graph::~Graph()
{

}