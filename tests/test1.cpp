#include <iostream>
#include "../graph.h"

int main()
{
    Graph a;
    std::cout << a.size() << std::endl;
    a.resize(10);
    std::cout << a.size() << std::endl;
    return 0;
}