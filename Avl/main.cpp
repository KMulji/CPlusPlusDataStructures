#include <iostream>
#include "AVL.hpp"


int main()
{
    AVL<int> *tree= new AVL<int>();

    tree->Insert(13);
    tree->Insert(18);
    tree->Insert(15);

    tree->InOrder();
    std::cout<<"Root is "<<tree->GetRoot()->GetVal()<<std::endl;
    
    return 0;
}