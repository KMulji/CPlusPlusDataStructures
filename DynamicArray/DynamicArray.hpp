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
            if(GetLength()==GetSize())
            {
                this->size = 2* this->size;
                T *temp = new T[this->size];
                for(int i=0;i<GetLength();i++)
                {
                    temp[i]=arr[i];
                }
                delete[] arr;
                arr=temp;
            }
        }
        void Shrink()
        {
            if(GetLength()==GetSize()/2)
            {
                this->size=this->size/2;
                T* temp = new T[this->size];

                for(int i=0;i<GetLength();i++)
                {
                    temp[i] = arr[i];
                }
                delete[] arr;
                arr=temp;

            }
        }

    public:
        DynamicArray()
        {
            this->arr = new T[10];
            this->size=10;
            this->length=-1;
        }
        DynamicArray(T A[] , int n)
        {
            this->size=n;
            this->length=-1;
            this->arr = new T[10];
            for(int i=0;i<n;i++)
            {
                this->length++;
                arr[i]=A[i];
            }
        }
        int GetLength()
        {
            return this->length+1;
        }
        int GetSize()
        {
            return this->size;
        }
        void Display()
        {
            for(int i=0;i<GetLength();i++)
            {
                std::cout<<this->arr[i]<<std::endl;
            }
        }
        void Append(T val)
        {
            
            if(this->GetLength()==this->GetSize())
            {
                Expand();
            }
            this->length++;
            this->arr[this->length] = val;
        }
        void Insert(int index, T val)
        {
            if(index<0 || index >= GetLength()){
                std::cout<<"Invalid index for insert"<<std::endl;
                return;
            }
            // 1 2 3 4 5
            if(this->GetLength() == this->GetSize())
            {
                Expand();
            }
    
            for(int i=GetLength(); i>index;i--)
            {
                arr[i]=arr[i-1];
            }
            arr[index]=val;
            this->length++;

        }
        int PopBack()
        {
            int val;
            if(this->GetLength() ==this->GetSize()/2)
            {
                Shrink();
            }
            val = arr[this->length];
            this->length--;

            return val;
        }
        int Delete(int index)
        {
            if(index<0 || index >= GetLength()){
                std::cout<<"Invalid index for delete"<<std::endl;
                return-1;
            }
            if(this->GetLength() == this->GetSize()/2)
            {
                Shrink();
            }
            // 1 2 3 4 5
            int value = this->arr[index];

            for(int i=index;i<GetLength()-1;i++)
            {
                this->arr[i]=this->arr[i+1];
            }
            this->length--;
            return value;

        }
        int LinearSearch(int key)
        {
            for(int i=0;i<GetLength();i++)
            {
                if(this->arr[i]==key)
                {
                    return i;
                }
            }
            return -1;
        }
        int BinarySearch(int key)
        {
            int lo=0;
            int hi = GetLength()-1;
            while(lo<=hi)
            {
                int mid = lo +(hi-lo)/2;
                if(this->arr[mid]==key)
                {
                    return mid;
                }else if(this->arr[mid]>key)
                {
                    hi=mid-1;
                }else if(this->arr[mid]<key)
                {
                    lo=mid+1;
                }
            }
            return -1;
        }
        void Reverse()
        {
            int i=0;
            int j = GetLength()-1;

            while(i<j)
            {
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;

                i++;
                j--;
            }
        }
        T operator[](int index) const
        {
            if(index<0 || index >= GetLength()){
                std::cout<<"Invalid index for get"<<std::endl;
                return -1;
            }
            return arr[index];
        }
        T& operator [] (int index) 
        {
            if(index<0 || index >= GetLength()){
                std::cout<<"Invalid index for get"<<std::endl;

                return arr[0];
            }
            return arr[index];
        }
        
        

        
};