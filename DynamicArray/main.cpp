#include <iostream>
#include "DynamicArray.hpp"
int main()
{
    int A[4] = {1,2,3,4};
    DynamicArray<int> da = DynamicArray<int>(A,4);
    da.Append(5);
    da.Delete(4);
    
    da.Display();
    
    std::cout<<"Length and size"<<std::endl;
    std::cout<<da.GetLength()<<std::endl;
    std::cout<<da.GetSize()<<std::endl;
    return 0;
}