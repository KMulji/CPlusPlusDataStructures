#include <iostream>
#include "BST.hpp"




int main()
{
    BST<int> *tree = new BST<int>();

    tree->InsertRecursive(8);
    tree->InsertRecursive(3);
    tree->InsertRecursive(10);
    tree->InsertRecursive(1);
    tree->InsertRecursive(6);
    tree->InsertRecursive(14);
    tree->InsertRecursive(4);
    tree->InsertRecursive(7);
    tree->InsertRecursive(13);

    // tree->InsertRecursive(10);
    // tree->InsertRecursive(5);
    // tree->InsertRecursive(20);

    tree->Delete(8);
    std::cout<<"Root is "<<tree->GetRoot()->GetVal()<<std::endl;
    tree->Inorder();
    

    free(tree);
    return 0;

}