#include "Doubly.hpp"


int main()
{
    Doubly<int> d = Doubly<int>();

    d.Append(10);
    d.Append(40);
    d.Append(30);
    d.Append(20);
    d.Append(-10);
    d.Append(50);
     d.Display();
    d.MergeSort();
   
    std::cout<<"..................."<<std::endl;
    d.DisplayReverse();

    return 0;
}