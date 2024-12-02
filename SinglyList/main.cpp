#include "Singly.hpp"


int main()
{
    Singly<int> s = Singly<int>();
    s.Append(1);
    s.Append(5);
    s.Append(3);
    s.Append(2);
    s.Append(4);
    s.MergeSort();
    s.Display();

    
    
}