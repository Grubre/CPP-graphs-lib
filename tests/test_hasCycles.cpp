#include <iostream>
#include "../graph.h"

int main()
{
    Graph a(3);
    a.add_vertex(0,1);
    a.add_vertex(1,2);
    //a.add_vertex(0,2);
    a.print_adjacency_matrix();
    std::cout << "Undirected: " << a.is_undirected() << std::endl;
    std::cout << "is_cyclic:   " << a.is_cyclic() << std::endl;
    return 0;
}