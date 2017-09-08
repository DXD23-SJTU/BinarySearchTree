//
// Created by 徐达丁 on 2017/9/8.
//

#ifndef BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_BINARYSEARCHTREE_H

#include <cstdlib>

template <class Type>
class BinarySearchTree{
private:
    struct BinaryNode{
        Type data;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Type &thedata,BinaryNode* lt,BinaryNode* rt):data(thedata),left(lt),right(rt){}
    };

    BinaryNode* root;

    void  insert(const Type &x,BinaryNode* &t);
    void  remove(const Type &x,BinaryNode* &t);
    bool  find(const Type &x,BinaryNode* t) const;
    void makeEmpty(BinaryNode* &t);

public:
    BinarySearchTree(BinaryNode* t = NULL){root = t;}
    ~BinarySearchTree(){makeEmpty(root);}
    bool find(const Type &x) const;
    void insert(const Type &x);
    void remove(const Type &x);
};

template <class Type>
bool BinarySearchTree<Type>::find(const Type &x) const {
    return find(x,root);
}
template <class Type>
bool BinarySearchTree<Type>::find(const Type &x, BinaryNode *t) const {
    if(t == NULL) return false;
    else if(x<t->data) return find(x,t->left);
    else if(x>t->data) return find(x,t->right);
    else return true;
}

template <class Type>
void BinarySearchTree<Type>::insert(const Type &x) {
    insert(x,root);
}
template <class Type>
void BinarySearchTree<Type>::insert(const Type &x,BinaryNode* &t) {
    if(t == NULL) t = new BinaryNode(x,NULL,NULL);
    else if(x<t->data) insert(x,t->left);
    else if(x>t->data) insert(x,t->right);
}

template <class Type>
void BinarySearchTree<Type>::remove(const Type &x) {
    remove(x,root);
}
template <class Type>
void BinarySearchTree<Type>::remove(const Type &x,BinaryNode* &t) {
    if(t == NULL) return;
    else if(x<t->data) remove(x,t->left);
    else if(x>t->data) remove(x,t->right);
    else if(t->left!=NULL && t->right!=NULL){
        BinaryNode* tmp = t->right;
        while(tmp->left !=NULL ) tmp = tmp->left;
        t->data = tmp->data;
        remove(t->data,t->right);
    }
    else{
        BinaryNode* oldNode = t;
        t = (t->left != NULL)? t->left:t->right;
        delete oldNode;
    }
}

template <class Type>
void BinarySearchTree<Type>::makeEmpty(BinaryNode *&t) {
    if(t->left!= NULL) makeEmpty(t->left);
    if(t->right!= NULL) makeEmpty(t->right);
    delete t;
}
#endif //BINARYSEARCHTREE_BINARYSEARCHTREE_H
