#include "../src/graph.h"
#include <iostream>

using namespace Grubre;

int main()
{
    Graph a(3);
    a.add_vertex(0,1);
    a.add_vertex(1,2);
    a.print_adjacency_matrix();

    Graph b(4);
    b.add_vertex(0,1);
    b.add_vertex(1,2);
    b.add_vertex(2,3);
    b.add_vertex(3,0);
    b.print_adjacency_matrix();

    Graph c = a | b;
    c.print_adjacency_matrix();
    std::cout << "is connected: " << c.is_connected() << std::endl;
    return 0;
}