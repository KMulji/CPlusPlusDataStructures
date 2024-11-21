#include <iostream>


template <class T>
class SinglyNode{
    private:
        T data;
        SinglyNode<T>* next;
        

    public:
        
        SinglyNode(T data,SinglyNode* next)
        {
            this->data=data;
            this->next=next;
        }
        SinglyNode(T data)
        {
            this->data=data;
            this->next=nullptr;
        }
        T GetVal()
        {
            return this->data;
        }
        void SetVal(T val)
        {
            this->data=val;
        }

        SinglyNode<T>* GetNext()
        {
            return this->next;
        }

        void SetNext(SinglyNode<T> *next){
            this->next=next;
        }
        ~SinglyNode()
        {
            delete next;
        }

};