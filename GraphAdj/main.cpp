#include <iostream>
#include "Graph.hpp"

int main()
{
    Graph test = Graph(5);

    test.Insert(0,4);
    test.Insert(0,1);

    test.Insert(1,2);
    test.Insert(1,4);
    test.Insert(4,2);
    test.Insert(4,3);
    test.Insert(2,3);

    test.DFS(0);
    test.BFS(0);

    return 0;
}