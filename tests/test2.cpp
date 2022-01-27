#include <iostream>
#include "../graph.h"
#include "../val_graph.h"

int main()
{
    Graph a(4);
    a.addVertex(0,1);
    //a.addVertex(0,2);
    a.addVertex(1,2);
    a.addVertex(2,3);
    a.printAdjacencyMatrix();
    std::cout << "dist from 0 to 3: " << a.minEdgeCount(0,3) << std::endl;
    std::cout << "is cyclic: " << a.isCyclic() << std::endl;
    return 0;
}