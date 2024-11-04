#include <iostream>
#include "DynamicArray.hpp"
int main()
{
    std::cout << "Hello World" << std::endl;
    int A[5] = {2,4,6,8,10};  

    DynamicArray<int> da = DynamicArray<int>(A,5);
    da.Display();
    return 0;
}