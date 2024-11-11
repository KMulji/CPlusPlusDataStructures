#include <iostream>
#include "DynamicArray.hpp"
int main()
{
    int A[6] = {2,4,6,8,10,12};  
    DynamicArray<int> da = DynamicArray<int>(A,6);
    da.Append(14);
    da.Display();
    std::cout<<"Length is "<<da.GetLength()<<std::endl;
    std::cout<<"Size is "<<da.GetSize()<<std::endl;

    da.PopBack();
    std::cout<<"Length is "<<da.GetLength()<<std::endl;
    std::cout<<"Size is "<<da.GetSize()<<std::endl;

    da.PopBack();
    std::cout<<"Length is "<<da.GetLength()<<std::endl;
    std::cout<<"Size is "<<da.GetSize()<<std::endl;

    da.PopBack();
    std::cout<<"Length is "<<da.GetLength()<<std::endl;
    std::cout<<"Size is "<<da.GetSize()<<std::endl;

    da.PopBack();
    std::cout<<"Length is "<<da.GetLength()<<std::endl;
    std::cout<<"Size is "<<da.GetSize()<<std::endl;

    da.Display();
    
    
    return 0;
}