#include <iostream>
#include "../src/graph.h"

using namespace Grubre;

int main()
{
    Graph a(5);
    a.add_vertex(0,1,false);
    a.add_vertex(2,1,false);
    a.add_vertex(2,3);
    a.add_vertex(3,4);
    a.print_adjacency_matrix();
    std::cout << "undirected: " << a.is_undirected() << std::endl;
    std::cout << "connected: " << a.is_connected() << std::endl;
    return 0;
}