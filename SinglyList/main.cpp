#include "Singly.hpp"


int main()
{
    Singly<int> s = Singly<int>();
    s.Append(10);
    s.Append(20);
    s.Prepend(5);
    s.Display();
}