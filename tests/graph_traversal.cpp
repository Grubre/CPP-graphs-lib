#include <iostream>
#include "../src/graph.hpp"

using namespace Grubre;

int main()
{
    Graph<int,int> a(7);
    a.add({0,1});
    a.add({0,2});
    a.add({1,3});
    a.add({1,4});
    a.add({2,5});
    a.add({2,6});

    for(int i = 0; i < a.size(); i++)
        a[i] = i;

    auto lambdaPrint = [](int id, int val, std::vector<bool> adjacencyList)
    {
        std::cout << val << " ";
    };
    
    std::cout << "Graph a:\n";
    a.print_adjacency_matrix();
    std::cout << "Traversal using:\n";
    std::cout << "DFS: " << std::endl;;
    a.traverse(Graph<int,int>::TraverseAlgorithm::DFS, lambdaPrint);
    std::cout << std::endl << "BFS: " << std::endl;;
    a.traverse(Graph<int,int>::TraverseAlgorithm::BFS, lambdaPrint);
    std::cout << std::endl;
    return 0;
}
