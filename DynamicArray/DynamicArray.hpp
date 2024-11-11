#include <iostream>
#include <stdlib.h>


template <class T>
class DynamicArray
{
private:
    T *arr;
    int size;
    int length;

    void Expand()
    {
        if(this->length==this->size)
        {
            T* temp = new T[size*2];
            size=size*2;

            for(int i=0;i<length;i++)
            {
                temp[i] = arr[i];
            }
        
            arr=temp;
        }
    }
    void Shrink()
    {
        int newSize= 0.5 *this->size;
        
        if(length == newSize)
        {
            std::cout<<"Resizing "<<std::endl;
            T* temp = new T[newSize];
            size=newSize;

            for(int i=0;i<length;i++)
            {
                temp[i] = arr[i];
            }
             arr=temp;
        }
       
    }

public:
    DynamicArray()
    {
        arr = new T[10];
        this->size = 10;
        this->length = -1;
    }
    int GetLength()
    {
        return length+1;
    }
    int GetSize()
    {
        return size;
    }
    DynamicArray(int A[], int n)
    {
        arr = new T[n];
        this->size = n;
        this->length=-1;
        for (int i = 0; i < n; i++)
        {
            
            this->length++;
            arr[length] = A[i];
            
        }
    }
    void Append(T val)
    {
        this->length++;
        if(size == length)
        {
            Expand();
        }
        arr[length] = val;
    }

    int PopBack()
    {
        int ans = arr[length];
        
        
       
        if(this->length==this->size *0.5)
        {
            
            Shrink();
        }
        this->length--;
        return ans;
    }

    void Display()
    {
        for(int i=0;i<=this->length;i++)
        {
            std::cout<<arr[i]<<std::endl;
        }
    }

    ~DynamicArray()
    {
        delete[] arr;
    }

    
};