#include <iostream>
#include <stdlib.h>


template <class T>
class DynamicArray
{
    private:
        T *arr; 
        int size;
        int length;
        /*
            Name: Expand()
            Description: Grow the array when length == size
        */
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
        /*
            Name: Shrink()
            Description: Shrink the array when size/2==len
        */
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
        /*
            Name:QuickSortPrivate
            Description: private function to manage recursive calls of quicksort
        */
        void QuickSortPrivate(int low,int hi,T A[])
        {
            if(low>=hi)
            {
                return;
            }
            int j = Partition(low,hi,A);
            
            QuickSortPrivate(low,j-1,A);
            QuickSortPrivate(j+1,hi,A);
        }
        /*
            Name: Partition
            Description: sort the partitioned section of quicksort
        */
        int Partition(int low,int high,T A[])
        {
            T pivot = A[high];
            
            int i=low;
            int j=high-1;

            while(i<j)
            {
                
                while(A[j]>pivot){j--;}

                while(A[i]<pivot){i++;}
                if(i<j){
                    T temp = A[i];
                    A[i]=A[j];
                    A[j]=temp;
                }
            }
            T temp = A[i];
            A[i]=A[high];
            A[high]=temp;
            return i;
        }

        void Merge(T A[] ,int lo,int mid,int hi)
        {
            int i=lo;
            int j=mid+1;
            int k=lo;
            T* B = new T[hi-lo];

            while(i<=mid && j<=hi)
            {
                if(A[i]<A[j])
                {
                    B[k++] = A[i++];
                }else
                {
                    B[k++]=A[j++];
                }
            }
            for(;i<=mid;i++)
            {
                B[k++]=A[i];
            }

            for(;j<=hi;j++)
            {
                B[k++]=A[j];
            }

            for(int l=lo;l<=hi;l++)
            {
                A[l]=B[l];
            }
            delete[] B;
        }
        void MergeSortPrivate(T A[],int lo,int hi)
        {
            int mid;
            if(lo<hi)
            {
                mid = (lo+hi)/2;

                MergeSortPrivate(A,lo,mid);
                MergeSortPrivate(A,mid+1,hi);
                Merge(A,lo,mid,hi);
            }
        }

    public:
        /*
            Name: Dynamic Array
            Description: Default constructor
        */
        DynamicArray()
        {
            this->arr = new T[10];
            this->size=10;
            this->length=-1;
        }
        /*
            Name:DynamicArray
            Description: Construct a dynamic array from a standard C++ array;
        */
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
        /*
            Name: Get Length
            Description: return number of elements in the array
        */
        int GetLength()
        {
            return this->length+1;
        }
        /*
            Name: Get Size
            Description: Return capacity of array
        */
        int GetSize()
        {
            return this->size;
        }
        /*
            Name: Display()
            Description: Print the contents of dynamic array to terminal
        */
        void Display()
        {
            for(int i=0;i<GetLength();i++)
            {
                std::cout<<this->arr[i]<<std::endl;
            }
        }
        /*
            Name: Append()
            Description: Add element to the end of dynamic array
        */
        void Append(T val)
        {
            
            if(this->GetLength()==this->GetSize())
            {
                Expand();
            }
            this->length++;
            this->arr[this->length] = val;
        }
        /*
            Name:Insert
            Description:Add a element at a specific index withint dynamic array 
        */
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
        /*
            Name: PopBack
            Description: Delete element from end of array.
        */
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
        /*
            Name: Delete
            Description: Remove and return element at specified index. 
        */
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
        /*
            Name: Linear Search
            Description: Find an element in 0(N) time.
        */
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
        /*
            Name: BinarySearch
            Description: Find an element in O(logn) time
        */
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
        /*
            Name: Reverse
            Description: Reverse the array
        */
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
        /*
            Name: Quicksort
            Description: sorts the array in O(n^2) worst time and O(nlogn) average time
        */
        void QuickSort()
        {
            
            QuickSortPrivate(0,GetLength()-1,this->arr);

        }

        void MergeSort()
        {
            MergeSortPrivate(this->arr,0,GetLength()-1);
        }
        
        
        

        
};