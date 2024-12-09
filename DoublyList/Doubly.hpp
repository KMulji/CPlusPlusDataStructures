#include <iostream>

#include "DoublyNode.hpp"
template<class T>


class Doubly{
    private:
        DoublyNode<T> *head;
        DoublyNode<T> *tail;
        int length;

        DoublyNode<T>* MergeSortPrivate(DoublyNode<T> *head)
        {
            if(!head || !head->GetNext())
            {
                return head;
            }
            //find middle and split list
            DoublyNode<T> * fast=head;
            DoublyNode<T> * slow=head;

            while(fast && fast->GetNext())
            {
                fast=fast->GetNext()->GetNext();
                slow=slow->GetNext();
            }

            DoublyNode<T> *list1=head;
            DoublyNode<T> *list2 = slow;

            if(slow->GetPrev())
            {
                slow->GetPrev()->SetNext(nullptr);
                slow->SetPrev(nullptr);
            }
            

            list1 = MergeSortPrivate(list1);
            list2 = MergeSortPrivate(list2);

            return Merge(list1,list2);

        }
        DoublyNode<T> *Merge(DoublyNode<T> *list1,DoublyNode<T> *list2)
        {
            DoublyNode<T> *newHead = nullptr;
            DoublyNode<T> *newTail=nullptr;
            DoublyNode<T> *curr1 = list1;
            DoublyNode<T> *curr2 = list2;

            while(curr1 && curr2)
            {
                if(curr1->GetValue()<curr2->GetValue())
                {
                    if(newHead==nullptr)
                    {
                        newHead=curr1;
                        newTail=curr1;
                        curr1=curr1->GetNext();
                    }else{
                        newTail->SetNext(curr1);
                        curr1->SetPrev(newTail);
                        newTail=curr1;
                        curr1=curr1->GetNext();

                    }
                }else{
                    if(newHead==nullptr)
                    {
                        newHead=curr2;
                        newTail = curr2;
                        curr2=curr2->GetNext();
                    }else{
                        newTail->SetNext(curr2);
                        curr2->SetPrev(newTail);
                        newTail=curr2;
                        curr2=curr2->GetNext();
                    }
                }
            }
            if(curr1)
            {
                newTail->SetNext(curr1);
                curr1->SetPrev(newTail);
            }
            if(curr2)
            {
                newTail->SetNext(curr2);
                curr2->SetPrev(newTail);
            }

            return newHead;
        }
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
            if(this->head->GetNext()==nullptr)
            {
                free(this->head);
                this->head=nullptr;
                this->tail=nullptr;
                return;
            }
            DoublyNode<T> *temp = this->head;
            this->head=this->head->GetNext();

            this->head->SetPrev(nullptr);
            temp->SetNext(nullptr);
            this->length--;
            free(temp);
            temp=nullptr;
            
        }

        void PopEnd()
        {
            if(this->length==0)
            {
                return;
            }
            if(this->head->GetNext()==nullptr)
            {
                free(this->head);
                this->head=nullptr;
                this->tail=nullptr;
                return;
            }
            DoublyNode<T> *temp = this->tail;
            this->tail = this->tail->GetPrev();
            temp->SetPrev(nullptr);
            this->tail->SetNext(nullptr);
            this->length--;

            free(temp);
            temp=nullptr;
        }
        /*
            1,2,3,4,5
        */
        void Delete(int index)
        {
            if(index<0 || index > this->length)
            {
                return;
            }
            if(this->head==nullptr)
            {
                return;
            }
            if(index==0)
            {
                Pop();
                return;
            }
            if(index==this->length)
            {
                PopEnd();
                return;
            }
            DoublyNode<T> *curr = this->head;
            int count=0;

            while(curr && count!=index)
            {

                curr=curr->GetNext();
                count++;

            }
            
            curr->GetPrev()->SetNext(curr->GetNext());
            curr->GetNext()->SetPrev(curr->GetPrev());
            curr->SetPrev(nullptr);
            curr->SetNext(nullptr);
            free(curr);
            curr=nullptr;
        }

        void MergeSort()
        {
            
            this->head = MergeSortPrivate(this->head);
            DoublyNode<T> *curr = this->head;
            
            while(curr)
            {
                this->tail=curr;
                curr=curr->GetNext();
            }
        }



};

