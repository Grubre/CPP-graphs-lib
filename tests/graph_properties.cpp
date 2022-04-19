#include <iostream>
#include "../src/graph.hpp"

using namespace Grubre;

int main()
{
    Graph<int,int> a(3);
    a.add({0,1});
    a.add({1,2});

    std::cout << "Adjacency matrix:\n";
    a.print_adjacency_matrix();
    std::cout << "The graph is:\n";
    std::cout << "Undirected: " << (a.is_undirected() ? "true" : "false") << std::endl;
    std::cout << "Cyclic:     " << (a.is_cyclic() ? "true" : "false")<< std::endl;
    std::cout << "Connected:  " << (a.is_connected() ? "true" : "false")<< std::endl;
    return 0;
}
