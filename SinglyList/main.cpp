#include "Singly.hpp"


int main()
{
    Singly<int> s = Singly<int>();
    s.Append(10);
    s.Append(20);
    s.Prepend(5);
    s.Insert(30,3);
    s.Delete(3);
    s.Display();
    
}