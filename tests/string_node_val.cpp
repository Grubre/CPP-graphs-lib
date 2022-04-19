#include "../src/graph.hpp"
#include <iostream>

using namespace Grubre;

int main()
{
    Graph<std::string,int> a(4);

    a.add({0,1},0);
    a.add({1,2},1);
    a.add({2,3},2);

    a[0] = "city a";
    a[1] = "city b";
    a[2] = "city c";
    a[3] = "city d";
    auto lambdaPrint = [](int id, std::string val, std::vector<bool> adjacencyList)
    {
        std::cout << val << ", ";
    };
    
    a.traverse(Graph<std::string,int>::TraverseAlgorithm::DFS, lambdaPrint);
    return 0;
}
