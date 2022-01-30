#include "../graph.h"
#include <iostream>

int main()
{
    Graph a(3);
    a.add_vertex(0,1);
    a.add_vertex(1,2);
    Graph b = a;
    a.print_adjacency_matrix();
    std::cout << std::endl;
    b.print_adjacency_matrix();
    std::cout << std::endl << (a == b) << std::endl;;
    return 0;
}