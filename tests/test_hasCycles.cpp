#include <iostream>
#include "../src/graph.h"

using namespace Grubre;

int main()
{
    Graph a(3);
    a.add({0,1});
    a.add({1,2});
    //a.add(0,2);
    a.print_adjacency_matrix();
    std::cout << "Undirected: " << a.is_undirected() << std::endl;
    std::cout << "is_cyclic:   " << a.is_cyclic() << std::endl;
    return 0;
}