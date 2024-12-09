#include <iostream>
#include "BinNode.hpp"
#include <queue>

using std::queue;
template<class T>
class BST{
    private:
        BinNode<T> *root;
        void InorderPrivate(BinNode<T> *root)
        {
            if(root==nullptr)
            {
                return;
            }
            InorderPrivate(root->GetLeft());
            std::cout<<root->GetVal()<<std::endl;
            InorderPrivate(root->GetRight());
        }
        void PreOrderPrivate(BinNode<T> * root)
        {
            if(root==nullptr)
            {
                return;
            }
            std::cout<<root->GetVal()<<std::endl;
            PreOrderPrivate(root->GetLeft());
            PreOrderPrivate(root->GetRight());
        }
        void PostOrderPrivate(BinNode<T> *root)
        {
            if(root==nullptr)
            {
                return;
            }
            PostOrderPrivate(root->GetLeft());
            PostOrderPrivate(root->GetRight());
            std::cout<<root->GetVal()<<std::endl;
        }
        BinNode<T> * InsertPrivate(BinNode<T> *root,T val)
        {
            if(!root)
            {
                BinNode<T> *temp= new BinNode<T>(val);
                return temp;
            }
            if(val>root->GetVal())
            {
                 root->SetRight(InsertPrivate(root->GetRight(),val));
            }else if(val<root->GetVal())
            {
                 root->SetLeft(InsertPrivate(root->GetLeft(),val));
            }
            return root;
        }
        BinNode<T>* InOrderSucc(BinNode<T> *root)
        {
            while(root && root->GetLeft())
            {
                root=root->GetLeft();
            }
            return root;
        }
        BinNode<T>* DeletePrivate(BinNode<T> *root,T val)
        {
            if(!root)
            {
                return nullptr;
            }
            if(val > root->GetVal())
            {
                root->SetRight(DeletePrivate(root->GetRight(),val));
            }else if(val<root->GetVal())
            {
                root->SetLeft(DeletePrivate(root->GetLeft(),val));
            }else{
                if(!root->GetRight()&&!root->GetLeft())
                {
                    delete root;
                    return nullptr;
                }else if(!root->GetLeft())
                {
                    BinNode<T> *temp = root->GetRight();
                    delete root;
                    return temp;
                }else if(!root->GetRight())
                {
                    BinNode<T> * temp = root->GetLeft();
                    delete root;
                    return temp;
                }else if (root->GetRight()&& root->GetLeft())
                {

                    BinNode<T> *succ = InOrderSucc(root->GetRight());
                    root->SetVal(succ->GetVal());
                    root->SetRight(DeletePrivate(root->GetRight(),succ->GetVal()));
                }
            } 
            return root;
        }
    public:
        BST()
        {
            root=nullptr; 
        }
        BinNode<T>* GetRoot()
        {
            return this->root;
        }

        void Insert(T val)
        {
            BinNode<T> *temp = new BinNode<T>(val);
            if(root==nullptr)
            {
                root=temp;
                return;
            }

            BinNode<T> *curr = root;
            BinNode<T> *prev = nullptr;

            while(curr)
            {
                if(val>curr->GetVal())
                {
                    prev=curr;
                    curr=curr->GetRight();
                }else if(val<curr->GetVal())
                {
                    prev=curr;
                    curr=curr->GetLeft();
                }
            }
            if(val>prev->GetVal())
            {
                prev->SetRight(temp);
            }else if(val<prev->GetVal())
            {
                prev->SetLeft(temp);
            }
        }

        void InsertRecursive(T val)
        {
            if(!root)
            {
                BinNode<T> *temp = new BinNode<T>(val);
                this->root=temp;
                return;
            }
            InsertPrivate(root,val);
        }
        void Delete(T val)
        {
            
            this->root=DeletePrivate(root,val);   
        }
        void Inorder()
        {
            InorderPrivate(this->root);
        }
        void PreOrder()
        {
            PreOrderPrivate(this->root);
        }
        void PostOrder()
        {
            PostOrderPrivate(this->root);
        }
};