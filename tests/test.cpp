#include "../src/weighted_graph.h"
#include <iostream>

using namespace Grubre;

void print_matrix()
{
    
}

int main()
{
    Graph a(4);
    a.add({0,1});
    a.add({1,2});
    a.add({2,3});
    a.add({0,3});

    std::vector < std::vector<int>> b = a.num_of_paths(0,0,2);
    std:
    return 0;
}