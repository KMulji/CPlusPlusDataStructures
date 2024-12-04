#include <iostream>

#include "DoublyNode.hpp"
template<class T>
class Doubly{
    private:
        DoublyNode<T> *head;
        DoublyNode<T> *tail;
        int length;

    public:
        Doubly()
        {
            this->head=nullptr;
            this->tail=nullptr;
            this->length=0;
        }

        void Append(T val)
        {
            DoublyNode<T> *temp = new DoublyNode<T>(val);
            if(this->head==nullptr||this->tail==nullptr)
            {
                this->head=temp;
                this->tail=temp;
                this->length++;
                return;
            }
            this->tail->SetNext(temp);
            temp->SetPrev(this->tail);
            this->tail=temp;
            this->length++;
        }
        void Prepend(T val)
        {
            DoublyNode<T> * temp = new DoublyNode<T>(val);

            if(this->head==nullptr||this->tail==nullptr)
            {
                this->head=temp;
                this->tail=temp;
                this->length++;
                return;
            }
            temp->SetNext(this->head);
            this->head->SetPrev(temp);
            this->head=temp;
            this->length++;
        }
        /*
               t
            1->2->3->4->5
        */
        void Insert(T val,int index)
        {
            if(index==0)
            {
                Prepend(val);
                return;
            }
            if(index==this->length)
            {
                Append(val);
                return;
            }
            DoublyNode<T> *temp = new DoublyNode<T>(val);
            DoublyNode<T> *curr=this->head;
            
            int count=0;

            while(curr && count!=index)
            {
                count++;
                curr=curr->GetNext();
            }
            temp->SetNext(curr);
            temp->SetPrev(curr->GetPrev());
            curr->GetPrev()->SetNext(temp);
            curr->SetPrev(temp);
            this->length++;



        }
        void Display()
        {
            if(this->length==0)
            {
                return;
            }
            DoublyNode<T> *curr = this->head;

            while(curr)
            {
                std::cout<<curr->GetValue()<<std::endl;
                curr=curr->GetNext();
            }
        }
        void DisplayReverse()
        {
            if(this->length==0)
            {
                return;
            }
            DoublyNode<T> *curr = this->tail;
            while(curr)
            {
                std::cout<<curr->GetValue()<<std::endl;
                curr=curr->GetPrev();
            }
        }

        void Pop()
        {
            if(this->length==0)
            {
                return;
            }
            DoublyNode<T> *temp = this->head;
            this->head=this->head->GetNext();

            this->head->SetPrev(nullptr);
            temp->SetNext(nullptr);
            free(temp);
            temp=nullptr;
        }

        void PopEnd()
        {
            if(this->length==0)
            {
                return;
            }
            DoublyNode<T> *temp = this->tail;
            this->tail = this->tail->GetPrev();
            temp->SetPrev(nullptr);
            this->tail->SetNext(nullptr);

            free(temp);
            temp=nullptr;
        }
        void Delete(int index)
        {
            
        }



};

