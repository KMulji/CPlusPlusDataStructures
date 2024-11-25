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
            this->length++;
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
            this->length++;
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
        /*
            Name: Insert()
            Description: Insert val at certain index in list.
        */
       void Insert(T val, int index)
       {
            if(index<0 || index>this->length)
            {
                std::cout<<"Index out of range"<<std::endl;
                return;
            }
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
            SinglyNode<T> *temp = new SinglyNode(val);
            SinglyNode<T> *curr = this->head;
            SinglyNode<T> *prev =nullptr;
            int count=0;
            while(count!=index && curr!=nullptr)
            {
                prev=curr;
                curr=curr->GetNext();
                count++;
            }

            prev->SetNext(temp);
            temp->SetNext(curr);
            this->length++;
       }
        /*
            Name: PopBack()
            Description: remove from tail.
        */
       void PopBack()
       {
            if(this->length==0)
            {
                std::cout<<"Singly list is empty"<<std::endl;
                return;
            }
            SinglyNode<T> *curr= this->head;
            while(curr!=nullptr && curr->GetNext()!=this->tail)
            {

                curr = curr->GetNext();
            }
            delete this->tail;
            this->tail=curr;
            this->tail->SetNext(nullptr);
            this->length--;
       }
        /*
            Name: PopFront()
            Description: Remove from head.
        */
       void PopFront()
       {
            if(this->length==0)
            {
                std::cout<<"Singly list is empty"<<std::endl;
                return;
            }
            SinglyNode<T> *curr=this->head;
            this->head = this->head->GetNext();
            curr->SetNext(nullptr);
            delete curr; 
       }
       /*
            Name: Delete()
            Description: Remove from a index.

            10->20->30->40
        */
       void Delete(int index)
       {
            if(this->length==0)
            {
                std::cout<<"Singly list is empty"<<std::endl;
                return;
            }
            SinglyNode<T> *curr = this->head;
            SinglyNode<T> *prev = nullptr;
            int count=0;
            while(curr!=nullptr &&  count!=index)
            {
                count++;
                prev=curr;
                curr=curr->GetNext();
            }

            if(count==0)
            {
                PopFront();
                return;
            }

            if(count==this->length-1)
            {
                PopBack();
                return;
            }
            SinglyNode<T> *temp=curr;
            prev->SetNext(curr->GetNext());
            curr->SetNext(nullptr);
            this->length--;
            delete temp;

       }
       /*
            Name: Peek()
            Description: Return the value in the top of singly list.

            10->20->30->40
        */
       T Peek()
       {
            if(this->length==0)
            {
                std::cout<<"Singly list is empty"<<std::endl;
                return;
            }
            return this->head->GetVal();
       }
       /*
            Name: Poke()
            Description: Return the value at the back of singly list.

            10->20->30->40
        */ 
       T Poke()
       {
        if(this->length==0)
            {
                std::cout<<"Singly list is empty"<<std::endl;
                return;
            }
            return this->tail->GetVal();
       }

};