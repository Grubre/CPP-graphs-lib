#include <iostream>
#include "../src/graph.h"

using namespace Grubre;

int main()
{
    Graph a(7);
    a.add({0,1});
    a.add({0,2});
    a.add({1,3});
    a.add({1,4});
    a.add({2,5});
    a.add({2,6});
    auto lambdaPrint = [](int id, std::vector<bool> adjacencyList)
    {
        std::cout << id << " ";
    };
    
    std::cout << "Graph a:\n";
    a.print_adjacency_matrix();
    std::cout << "Traversal using:\n";
    std::cout << "DFS: " << std::endl;;
    a.traverse(Graph::TraverseAlgorithm::DFS, lambdaPrint);
    std::cout << std::endl << "BFS: " << std::endl;;
    a.traverse(Graph::TraverseAlgorithm::BFS, lambdaPrint);
    std::cout << std::endl;
    return 0;
}
