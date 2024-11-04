#include <iostream>
#include <stdlib.h>
template <class T>
class DynamicArray
{
private:
    T *arr;
    int size;
    int length;

public:
    DynamicArray()
    {
        arr = new T[10];
        this->size = 10;
        this->length = 0;
    }
    DynamicArray(int A[], int n)
    {
        arr = new T[n];
        this->size = n;
        this->length = 0;
        for (int i = 0; i < n; i++)
        {
            arr[i] = A[i];
            this->length++;
        }
    }
    void Display()
    {
        for(int i=0;i<this->length;i++)
        {
            std::cout<<arr[i]<<std::endl;
        }
    }

    ~DynamicArray()
    {
        delete[] arr;
    }
};