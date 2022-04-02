#include "../src/weighted_graph.h"
#include <iostream>

using namespace Grubre;

void print_matrix(const std::vector < std::vector<int>> &a)
{
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < a.size(); j++)
            std::cout << a[i][j] << " ";
        std::cout << std::endl;
    }
        
}

int main()
{
    Graph a(4);
    a.add({0,1});
    a.add({1,2});
    a.add({2,3});
    a.add({0,3});

    std::cout << "Number of paths:\n";
    std::cout << a.num_of_paths(0,0,2) << std::endl;
    return 0;
}
