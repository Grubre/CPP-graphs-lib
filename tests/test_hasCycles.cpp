#include <iostream>
#include "../graph.h"

int main()
{
    Graph a(5);

    a.addVertex(0,1);
    a.addVertex(1,2);
    a.addVertex(0,2);
    a.printAdjacencyMatrix();
    std::cout << "Undirected: " << a.isUndirected() << std::endl;
    std::cout << "isCyclic:     " << a.isCyclic() << std::endl;
    return 0;
}