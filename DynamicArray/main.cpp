#include <iostream>
#include "DynamicArray.hpp"
int main()
{
    int A[9] = {50,70,60,90,40,80,10,20,30};
    DynamicArray<int> da = DynamicArray<int>(A,9);
    da.QuickSort();
    da.Display();

    
    //da.BinarySearch(4);
    
    std::cout<<"Length and size"<<std::endl;
    std::cout<<da.GetLength()<<std::endl;
    std::cout<<da.GetSize()<<std::endl;
    return 0;
}