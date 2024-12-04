#include "Doubly.hpp"


int main()
{
    Doubly<int> d = Doubly<int>();

    for(int i=0;i<5;i++)
    {
        d.Prepend(i);
    }
    d.Insert(100,5);
   
    d.Display();
    std::cout<<"..................."<<std::endl;
    d.DisplayReverse();

    return 0;
}