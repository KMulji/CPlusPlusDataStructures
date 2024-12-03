#include <iostream>
#include "../SinglyList/SinglyNode.hpp"

template<class T>
class SinglyQueue{
    private:
        SinglyNode<T> *head;
        SinglyNode<T> *tail;
        int length;
    public:
        SinglyQueue()
        {
            this->head=nullptr;
            this->tail=nullptr;
            this->length=0;
        }
        void Enqueue(T val)
        {
            SinglyNode<T> *temp = new SinglyNode(val);
            if(this->head==nullptr ||this->tail==nullptr)
            {
                this->head=temp;
                this->tail=temp;
                this->length++;
                return;
            }
            this->tail->SetNext(temp);
            this->tail=temp;
            this->length++;
        }
        void Dequeue()
        {
            if(this->head==nullptr||this->tail==nullptr)
            {
                std::cout<<"Queue is empty"<<std::endl;
                return;
            }
            if(this->head->GetNext()==nullptr)
            {
                free(this->head);
                this->head=nullptr;
                this->tail=nullptr;
                this->length--;
                return;
            }
            SinglyNode<T>* temp = this->head;
            this->head=this->head->GetNext();
            this->length--;
            free(temp);
            temp=nullptr;

        }
        T Peek()
        {
            return this->head->GetVal();
        }
        void Display()
        {
            if(this->head==nullptr||this->tail==nullptr)
            {
                std::cout<<"Queue is empty"<<std::endl;
                return;
            }

            SinglyNode<T> *curr=this->head;

            while(curr)
            {
                std::cout<<curr->GetVal()<<std::endl;
                curr=curr->GetNext();
            }
        }
};  

