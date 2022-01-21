#include <iostream>
#include "../graph.h"

int main()
{
    Graph a;
    a.addNode();
    a.addNode();
    a.addNode();
    a.addVertex(0,1,true);
    a.printAdjacencyList();
    a.removeNode(1);
    a.printAdjacencyList();
    std::cout << a.size() << std::endl;
    return 0;
}