#include "../src/weighted_graph.h"
#include <iostream>

using namespace Grubre;

int main()
{
    Weighted_Graph<std::string,int> a(3);
    a[0] = "Konin";
    a[1] = "Kalisz";
    a[2] = "Poznan";
    a.add("Wroclaw");
    a.add({0,1},5);
    a[{0,1}] = 3;
    a.print_adjacency_matrix();
    a.print_node_values();
    a.print_vertex_values();
    return 0;
}