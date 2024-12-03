#include <iostream>
#include "SinglyQueue.hpp"


int main()
{
    SinglyQueue<int> sq = SinglyQueue<int>();

    for(int i=0;i<5;i++)
    {
        sq.Enqueue(i);
    }
    sq.Display();
    std::cout<<".............................."<<std::endl;
    for(int i=0;i<3;i++)
    {
        sq.Dequeue();
    }
    sq.Display();
    return 0;
}