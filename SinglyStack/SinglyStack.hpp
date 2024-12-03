#include <iostream>
#include "../SinglyList/SinglyNode.hpp"
template<class T>

class SinglyStack{
    private:
        SinglyNode<T>* head;
        int length;
    public:
        SinglyStack()
        {
            this->head=nullptr;
            this->length=0;
        }
        void Push(T val)
        {
            SinglyNode<T>* temp = new SinglyNode(val);
            if(this->head==nullptr)
            {
                this->head=temp;
                this->length++;
                return;
            }
            temp->SetNext(this->head);
            this->length++;
            head=temp;

        }
        void Pop()
        {
            if(this->length==0)
            {
                std::cout<<"Stack is empty"<<std::endl;
                return;
            }
            if(this->head->GetNext()==nullptr)
            {
                free(this->head);
                this->head=nullptr;
                this->length--;
                return;
            }
            SinglyNode<T> *temp = this->head;
            this->head=this->head->GetNext();
            this->length--;
            free(temp);

        }
        int GetLength()
        {
            return this->length;
        }
        void Display()
        {
            if(this->length==0)
            {
                std::cout<<"Stack is empty"<<std::endl;
                return;
            }
            SinglyNode<T> *curr=this->head;

            while(curr)
            {
                std::cout<<curr->GetVal()<<std::endl;
                curr=curr->GetNext();
            }
        }
        T Peek()
        {
            if(this->length==0)
            {
                std::cout<<"Stack is empty"<<std::endl;
                return -1;
            }
            
            return this->head->GetVal();
        }

};