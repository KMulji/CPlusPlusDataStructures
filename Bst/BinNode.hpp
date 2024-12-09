#include <iostream>


template<class T>

class BinNode{
    private:
        T val;
        BinNode<T> *left;
        BinNode<T> *right;
    public:
        BinNode(T val)
        {
            this->val=val;
            this->left=nullptr;
            this->right=nullptr;
        }

        T GetVal()
        {
            return this->val;
        }

        BinNode<T>* GetLeft()
        {
            return this->left;
        }
        BinNode<T>* GetRight()
        {
            return this->right;
        }

        void SetLeft(BinNode<T>* left)
        {
            this->left=left;
        }
        void SetRight(BinNode<T> *right)
        {
            this->right=right;
        }

        void SetVal(T val)
        {
            this->val=val;
        }

        
};