#include <iostream>
#include "AVLNode.hpp"
template <class T>
class AVL{
    private:
        AVLNode<T> * root;
        int NodeHeight(AVLNode<T> * root)
        {
            int hl;
            int hr;
            hl = root->GetLeft()?root->GetLeft()->GetHeight():0;
            hr = root->GetRight()?root->GetRight()->GetHeight():0;
            return hl>hr ? hl+1:hr+1;
        }
        int NodeBalaceFactor(AVLNode<T> *root)
        {
            int hl;
            int hr;
            hl = root->GetLeft()?root->GetLeft()->GetHeight():0;
            hr = root->GetRight()?root->GetRight()->GetHeight():0;
            return hl - hr;
        }
        AVLNode<T>* InsertPrivate(AVLNode<T> *root,T val)
        {
            if(!root)
            {
                AVLNode<T> *temp = new AVLNode<T>(val);
                return temp;
            }
            if(val<root->GetVal())
            {
                root->SetLeft(InsertPrivate(root->GetLeft(),val));
            }
            if(val>root->GetVal())
            {
                root->SetRight(InsertPrivate(root->GetRight(),val));
            }
            root->SetHeight(NodeHeight(root));
            
            //balances
            return root;
        }

        void InorderPrivate(AVLNode<T> *root)
        {
            if(!root)
            {
                return;
            }
            InorderPrivate(root->GetLeft());
            std::cout<<root->GetVal()<<std::endl;
            std::cout<<"Height is "<<root->GetHeight()<<std::endl;
            InorderPrivate(root->GetRight());
        }


    public:
        AVL()
        {
            this->root=nullptr;
        }
        void Insert(T val)
        {
            if(!this->root)
            {
                AVLNode<T> *temp = new AVLNode<T>(val);
                this->root=temp;
                return;
            }
            InsertPrivate(this->root,val);
        }
        void InOrder()
        {
            InorderPrivate(this->root);
        }
};