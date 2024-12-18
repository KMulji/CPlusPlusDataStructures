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
        AVLNode<T>* LLRotation(AVLNode<T> * root)
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
        AVLNode<T>* LRRotation(AVLNode<T> * root)
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
        AVLNode<T>* RRRotation(AVLNode<T> * root)
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
        AVLNode<T>* RLRotation(AVLNode<T> * root)
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
                
                return LLRotation(root);
            }
            // balances LR
            else if(NodeBalaceFactor(root)==2 && NodeBalaceFactor(root->GetLeft())==-1)
            {
                return LRRotation(root);
            }
            //balances RR
            else if(NodeBalaceFactor(root)==-2 && NodeBalaceFactor(root->GetRight())==-1)
            {
                return RRRotation(root);
            }
            // rl balances
            else if(NodeBalaceFactor(root)==-2 && NodeBalaceFactor(root->GetRight())==1)
            {
                return RLRotation(root);
            }
            return root;
            
        }
        AVLNode<T>* InOrderSucc(AVLNode<T> *root)
        {
            while(root&&root->GetLeft())
            {
                root=root->GetLeft();
            }
            return root;
        }
        AVLNode<T>* DeletePrivate(AVLNode<T> *root,T val)
        {
            if(!root)
            {
                return nullptr;
            }
            if(val>root->GetVal())
            {
                root->SetRight(DeletePrivate(root->GetRight(),val));
            }else if(val<root->GetVal())
            {
                root->SetLeft(DeletePrivate(root->GetLeft(),val));
            }else{
                //equal to val
                if(!root->GetLeft() && !root->GetRight())
                {
                    delete root;
                    return nullptr;
                }
                if(!root->GetLeft())
                {
                    AVLNode<T> * temp = root->GetRight();
                    delete root;
                    return temp;
                }
                if(!root->GetRight())
                {
                    AVLNode<T> * temp = root->GetLeft();
                    delete root;
                    return temp;
                }
                if(root->GetLeft()&&root->GetRight())
                {
                    AVLNode<T> *succ = InOrderSucc(root->GetRight());
                    root->SetVal(succ->GetVal());

                    root->SetRight(DeletePrivate(root->GetRight(),succ->GetVal()));
                }
            }
            root->SetHeight(NodeHeight(root));
            //ll rotation
            if(NodeBalaceFactor(root)==2 && NodeBalaceFactor(root->GetLeft())==1)
            {
                return LLRotation(root);

            }
            // LR Rotation
            else if(NodeBalaceFactor(root)==2 && NodeBalaceFactor(root->GetLeft())==-1)
            {
                return LRRotation(root);
            }
            //RR Rotation
            else if(NodeBalaceFactor(root)==-2 && NodeBalaceFactor(root->GetRight())==-1)
            {
                return RRRotation(root);
            }
            //RL Rotation
            else if(NodeBalaceFactor(root)==-2 && NodeBalaceFactor(root->GetRight)==1)
            {
                return RLRotation(root);
            }
            //L-0 Rotation
            else if(NodeBalaceFactor(root)==2 && NodeBalaceFactor(root)==0)
            {
                return LLRotation(root);
            }
            //R-0 Rotation
            else if(NodeBalaceFactor(root)=-2 && NodeBalaceFactor(root)==0)
            {
                return RRRotation(root);
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