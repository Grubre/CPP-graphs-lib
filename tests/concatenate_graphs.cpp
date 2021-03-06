#include "../src/graph.hpp"
#include <iostream>

using namespace Grubre;

int main()
{
    Graph<int,int> a(3);
     a.add({2,1});
    a.add({1,2});
    std::cout << "Graph a:\n";
    a.print_adjacency_matrix();

    Graph<int,int> b(4);
    b.add({0,1});
    b.add({1,2});
    b.add({2,3});
    b.add({3,0}); 
    std::cout << "Graph b:\n";
    b.print_adjacency_matrix();

    Graph<int,int> c = a | b;
    std::cout << "Graph (a|b):\n";
    c.print_adjacency_matrix();
    return 0;
}
