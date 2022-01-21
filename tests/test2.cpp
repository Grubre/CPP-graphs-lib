#include <iostream>
#include "../graph.h"
#include "../val_graph.h"

int main()
{
    Val_Graph<int,int> a(10);
    a.addNode();
    a.setNodeValue(0,10);
    a.addVertex(0,1,2);
    std::cout << a.getVertexValue(1,0) << std::endl;
    std::cout << a.size() << std::endl;
    return 0;
}