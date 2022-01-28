#include <iostream>
#include "../graph.h"

int main()
{
    Graph a(7);
    a.addVertex(0,1);
    a.addVertex(0,2);
    a.addVertex(1,3);
    a.addVertex(1,4);
    a.addVertex(2,5);
    a.addVertex(2,6);
    auto lambdaPrint = [](int id, std::vector<bool> adjacencyList)
    {
        std::cout << id << " ";
    };
    std::cout << "DFS: " << std::endl;;
    a.traverse(Graph::TraverseAlgorithm::DFS, lambdaPrint);
    std::cout << std::endl << "BFS: " << std::endl;;
    a.traverse(Graph::TraverseAlgorithm::BFS, lambdaPrint);
    return 0;
}