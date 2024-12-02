#include <iostream>
#include "SinglyNode.hpp"

template <class T>
class Singly{
    private:
        SinglyNode<T>* head;
        SinglyNode<T> * tail;
        int length;
        
        SinglyNode<T>* Merge(SinglyNode<T> *list1,SinglyNode<T> * list2)
        {
            SinglyNode<T> * curr1=list1;
            SinglyNode<T> * curr2=list2;
            SinglyNode<T> * temp=nullptr;
            SinglyNode<T> *newHead=nullptr;
            SinglyNode<T> *newTail=nullptr;
            while(curr1&&curr2)
            {
                if(curr1->GetVal()<curr2->GetVal())
                {
                    if(newHead==nullptr){
                        newHead=curr1;
                        newTail=curr1;
                    }else{
                        newTail->SetNext(curr1);
                        newTail=curr1;
                    }
                    temp=curr1;
                    
                    curr1=curr1->GetNext();
                    temp->SetNext(nullptr);
                }else{
                    if(newHead==nullptr){
                        newHead=curr2;
                        newTail=curr2;
                    }else{
                        newTail->SetNext(curr2);
                        newTail=curr2;
                    }
                    temp=curr2;
                    curr2=curr2->GetNext();
                    temp->SetNext(nullptr);
                }
            }
            if (curr1) {
                    newTail->SetNext(curr1);
            }if(curr2) {
                    newTail->SetNext(curr2);
            }
            
            return newHead;
        }
        /*
        1 2 3 4 5 
        */
        SinglyNode<T>* MergeSortPrivate(SinglyNode<T>* head)
        {

            if(!head||!head->GetNext())
            {
                return head;
            }
            //get middle
            SinglyNode<T>*fast = head;
            SinglyNode<T>*slow = head;
            SinglyNode<T>* beforeSlow=nullptr;

            while(fast&&fast->GetNext())
            {
                fast=fast->GetNext()->GetNext();
                beforeSlow=slow;
                slow=slow->GetNext();
            }
            
            SinglyNode<T> * list2 = slow;
            if(beforeSlow)
            {
                beforeSlow->SetNext(nullptr);
            }
            
            SinglyNode<T>* list1 = head;

            list1=MergeSortPrivate(list1);
            list2=MergeSortPrivate(list2);

            return Merge(list1,list2);
        }

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

       void MergeSort()
       {
            this->head = MergeSortPrivate(this->head);
            
       }

       
       



};