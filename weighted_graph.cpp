///////////////////////////////////////////////////////////////////
// NAME:               weighted_graph.cpp
//
// PURPOSE:            Definition of Weighted_Graph class.
//                     This class is an extention of the Graph class.
//                     It adds the functionality of having weighted vertices.
//
// AUTHOR:             Grubre
///////////////////////////////////////////////////////////////////

#include "weighted_graph.h"
#include <iostream>

using namespace Grubre;
//==================contructors & destructors====================
Weighted_Graph::Weighted_Graph() : Graph()
{

}

Weighted_Graph::Weighted_Graph(unsigned int _size) : Graph(_size)
{

}

Weighted_Graph::~Weighted_Graph()
{

}