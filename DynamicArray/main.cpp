#include <iostream>
#include "DynamicArray.hpp"
int main()
{
    int A[6] = {1,2,3,4,5,6};
    DynamicArray<int> da = DynamicArray<int>(A,6);
    da.Append(7);
    
    da.Display();
    std::cout<<"Binary Search results "<<da.BinarySearch(6)<<std::endl;
    //da.BinarySearch(4);
    std::cout<<"Length and size"<<std::endl;
    std::cout<<da.GetLength()<<std::endl;
    std::cout<<da.GetSize()<<std::endl;
    return 0;
}