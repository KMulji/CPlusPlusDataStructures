#include <iostream>
#include "SinglyStack.hpp"


int main()
{
    SinglyStack<int> st = SinglyStack<int>();
    for(int i=0;i<5;i++)
    {
        st.Push(i);
    }
    st.Display();
    std::cout<<"...................."<<std::endl;
    std::cout<<st.Peek()<<std::endl;
    return 0;
}