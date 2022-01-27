#include <iostream>
#include "../graph.h"

int main()
{
    Graph a(5);
    a.addVertex(0,1,false);
    a.addVertex(2,1,false);
    a.addVertex(2,3);
    a.addVertex(3,4);
    a.printAdjacencyMatrix();
    std::cout << "undirected: " << a.isUndirected() << std::endl;
    std::cout << "connected: " << a.isConnected() << std::endl;
    return 0;
}