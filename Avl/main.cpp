#include <iostream>
#include "AVL.hpp"


int main()
{
    AVL<int> *tree= new AVL<int>();

    tree->Insert(8);
    tree->Insert(9);
    tree->Insert(10);

    tree->InOrder();
    std::cout<<"Root is "<<tree->GetRoot()->GetVal()<<std::endl;
    
    return 0;
}