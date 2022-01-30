#include "../graph.h"
#include <iostream>

int main()
{
    Graph a(3);
    a.addVertex(0,1);
    a.addVertex(1,2);
    Graph b = a;
    a.printAdjacencyMatrix();
    std::cout << std::endl;
    b.printAdjacencyMatrix();
    std::cout << std::endl << (a == b) << std::endl;;
    return 0;
}