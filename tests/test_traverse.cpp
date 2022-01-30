#include <iostream>
#include "../graph.h"

int main()
{
    Graph a(7);
    a.add_vertex(0,1);
    a.add_vertex(0,2);
    a.add_vertex(1,3);
    a.add_vertex(1,4);
    a.add_vertex(2,5);
    a.add_vertex(2,6);
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