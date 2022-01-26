#include <iostream>
#include "../graph.h"
#include "../val_graph.h"

int main()
{
    Graph a(6);
    a.addVertex(1,2,false);
    a.addVertex(2,3,false);
    a.addVertex(3,1,false);
    a.printAdjacencyMatrix();
    std::cout << "is connected: " << a.isConnected() << std::endl;
    std::cout << "is cyclic: " << a.isCyclic() << std::endl;
    return 0;
}