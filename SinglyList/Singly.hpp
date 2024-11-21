#include <iostream>
#include "SinglyNode.hpp"
template <class T>
class Singly{
    private:
        SinglyNode<T>* head;
        SinglyNode<T> * tail;
        int length;

    public:
        Singly()
        {
            this->head=nullptr;
            this->tail=nullptr;
            this->length=0;
        }
        /*
            Name: Append()
            Description: Add to the tail of the singly list
        */
        void Append(T val)
        {
            SinglyNode<T> *temp  =new SinglyNode(val);
            if(head==nullptr || tail==nullptr)
            {
                
                this->head=temp;
                this->tail=temp;
                this->length++;
                return;
            }
            this->tail->SetNext(temp);
            tail=tail->GetNext();
        }
        /*
            Name: Prepend()
            Description: Add to the head of the singly list
        */
        void Prepend(T val)
        {
            SinglyNode<T> *temp = new SinglyNode(val);
            if(head==nullptr||tail==nullptr)
            {
                this->head=temp;
                this->tail=temp;
                this->length++;
                return;
            }
            temp->SetNext(this->head);
            this->head = temp;
        }
        /*
            Name: Display()
            Description: print singly list to terminal
        */
        void Display()
        {
            SinglyNode<T> * curr = this->head;

            while(curr)
            {
                std::cout<<curr->GetVal()<<std::endl;
                curr=curr->GetNext();
            }
        }

        

};