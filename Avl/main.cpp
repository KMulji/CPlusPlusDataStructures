#include <iostream>
#include "AVL.hpp"


int main()
{
    AVL<int> *tree= new AVL<int>();

    tree->Insert(5);
    tree->Insert(4);
    tree->Insert(15);

    tree->InOrder();
    
    return 0;
}