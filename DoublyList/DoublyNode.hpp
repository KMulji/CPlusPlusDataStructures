#include <iostream>

template<class T>

class DoublyNode{
    private:
        T val;
        DoublyNode* next;
        DoublyNode* prev;
    public:
        DoublyNode()
        {
            val=-1;
            this->next=nullptr;
            this->prev=nullptr;
        }
        DoublyNode(T val)
        {
            this->val=val;
            this->prev=nullptr;
            this->next=nullptr;
        }


        DoublyNode* GetNext()
        {
            return this->next;
        }
        DoublyNode* GetPrev()
        {
            return this->prev;
        }
        T GetValue()
        {
            return this->val;
        }

        void SetNext(DoublyNode<T>* next)
        {
            this->next=next;
        }
        void SetPrev(DoublyNode<T>* prev)
        {
            this->prev=prev;
        }
        void SetVal(T val)
        {
            this->val=val;
        }

};