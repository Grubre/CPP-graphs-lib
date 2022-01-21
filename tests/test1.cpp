#include <iostream>
#include "../graph.h"

int main()
{
    Graph a, b(10);
    a.addNode();
    a.addNode();
    a.addNode();
    a.addVertex(0,1,true);
    a.printAdjacencyMatrix();
    a.removeNode(1);
    a.printAdjacencyMatrix();
    std::cout << a.size() << std::endl;
    b.addNode();
    b.addVertex(5,10);
    b.printAdjacencyMatrix();
    return 0;
}