#include <iostream>
#include "../graph.h"
#include "../val_graph.h"

int main()
{
    Graph a(5);
    a.addNode({0,1,2});
    a.printAdjacencyMatrix();
    return 0;
}