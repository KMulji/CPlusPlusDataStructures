#include <iostream>

template<class T>
class AVLNode{

    private:
        T val;
        int height;
        AVLNode<T> *left;
        AVLNode<T> *right;
    public:
        AVLNode(T val)
        {
            this->val=val;
            this->height=1;
            this->left=nullptr;
            this->right=nullptr;
        }

        T GetVal()
        {
            return this->val;
        }
        int GetHeight()
        {
            return this->height;
        }
        AVLNode<T>* GetLeft()
        {
            return this->left;
        }
        AVLNode<T> * GetRight()
        {
            return this->right;
        }

        void SetVal(T val)
        {
            this->val=val;
        } 
        void SetHeight(int height)
        {
            this->height=height;
        }
        void SetLeft(AVLNode<T>* left)
        {
            this->left=left;
        }
        void SetRight(AVLNode<T> *right)
        {
            this->right=right;
        }
};