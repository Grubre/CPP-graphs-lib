#include "../src/graph.hpp"
#include <iostream>

using namespace Grubre;

int main()
{
    // create a graph of size 4
    Graph<int,int> a(4);

    // add vertices between nodes
    a.add({0,1});
    a.add({1,2});
    a.add({2,3});
    a.add({0,3});

    // add a new node
    a.add();
    a.add({0,4});
   
    // count all paths going from 0 to it's neighbours and back
    std::cout << "Number of paths of length 2 to node 0 and back: ";
    std::cout << a.num_of_paths(0,0,2) << std::endl;

    // the resulting count is 3, ((0,1) (0,3) (0,4))

    return 0;
}
