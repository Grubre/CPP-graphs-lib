#include <iostream>
#include "../graph.h"

int main()
{
    Graph a(5);
    a.addVertex(0,1,false);
    a.addVertex(0,2,false);
    a.addVertex(2,3,false);
    a.addVertex(1,2,false);
    std::cout << "dist from 0 to 3: " << a.minEdgeCount(0,3) << std::endl;
    return 0;
}