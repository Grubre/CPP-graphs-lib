#include "../graph.h"
#include <iostream>

int main()
{
    Graph a(3);
    a.addVertex(0,1);
    a.addVertex(1,2);
    a.printAdjacencyMatrix();

    Graph b(4);
    b.addVertex(0,1);
    b.addVertex(1,2);
    b.addVertex(2,3);
    b.addVertex(3,0);
    b.printAdjacencyMatrix();

    Graph c = a | b;
    c.printAdjacencyMatrix();
    std::cout << "is connected: " << c.isConnected() << std::endl;
    return 0;
}