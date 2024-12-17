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
            hl = root&&root->GetLeft()?root->GetLeft()->GetHeight():0;
            hr = root&&root->GetRight()?root->GetRight()->GetHeight():0;
            return hl>hr ? hl+1:hr+1;
        }
        int NodeBalaceFactor(AVLNode<T> *root)
        {
            int hl;
            int hr;
            hl = root&&root->GetLeft()?root->GetLeft()->GetHeight():0;
            hr = root&&root->GetRight()?root->GetRight()->GetHeight():0;
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
            
            //balances LL
            if(NodeBalaceFactor(root)==2 && NodeBalaceFactor(root->GetLeft())==1)
            {
                AVLNode<T> * p =root;
                AVLNode<T> * pl = root->GetLeft();
                AVLNode<T> *plr = pl->GetRight();

                pl->SetRight(p);
                p->SetLeft(plr);

                //recompute heights
                p->SetHeight(NodeHeight(p));
                pl->SetHeight(NodeHeight(pl));
                

                if(this->root == p)
                    this->root=pl;

                return pl;

            }
            // balances LR
            else if(NodeBalaceFactor(root)==2 && NodeBalaceFactor(root->GetLeft())==-1)
            {
                AVLNode<T> * p =root;
                AVLNode<T> * pl = root->GetLeft();
                AVLNode<T> *plr = pl->GetRight();

                pl->SetRight(plr->GetLeft());
                p->SetLeft(plr->GetRight());

                plr->SetLeft(pl);
                plr->SetRight(p);

                pl->SetHeight(NodeHeight(pl));
                p->SetHeight(NodeHeight(p));
                plr->SetHeight(NodeHeight(plr));

                if(p==this->root)
                    this->root=plr;
                return plr;
            }
            //balances RR
            else if(NodeBalaceFactor(root)==-2 && NodeBalaceFactor(root->GetRight())==-1)
            {
                AVLNode<T> * p =root;
                AVLNode<T> * pr = root->GetRight();
                AVLNode<T> * prl = pr->GetLeft();

                pr->SetLeft(p);
                p->SetRight(prl);

                p->SetHeight(NodeHeight(p));
                pr->SetHeight(NodeHeight(pr));

                if(this->root==p)
                    this->root=pr;
                

                return pr;
            }
            // rl balances
            else if(NodeBalaceFactor(root)==-2 && NodeBalaceFactor(root->GetRight())==1)
            {
                AVLNode<T>* p =root;
                AVLNode<T>* pr = root->GetRight();
                AVLNode<T>* prl = pr->GetLeft();

                p->SetRight(prl->GetLeft());
                pr->SetLeft(prl->GetRight());

                prl->SetLeft(p);
                prl->SetRight(pr);


                p->SetHeight(NodeHeight(p));
                pr->SetHeight(NodeHeight(pr));
                prl->SetHeight(NodeHeight(prl));


                if(this->root==p)
                    this->root = prl;

                return prl;

            }
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
        AVLNode<T>* GetRoot()
        {
            return this->root;
        }
};