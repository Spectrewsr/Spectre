#ifndef SPLAY_H
#define SPLAY_H
#include <iostream>
#include "node.hpp"
using namespace std;
template <class T>
class SplayTree
{
private:
    SplayTreeNode<T>* root;

public:
    SplayTree();
    ~SplayTree();
    void Splay(T);
    void Insert(T);
    void Delete(T);
    void Destroy();

private:
    SplayTreeNode<T>* Splay(SplayTreeNode<T>*, T);
    SplayTreeNode<T>* Search(SplayTreeNode<T>*, T) const;
    SplayTreeNode<T>* Insert(SplayTreeNode<T>*&, SplayTreeNode<T>*);
    SplayTreeNode<T>* Delete(SplayTreeNode<T>*&, T);
    void Destroy(SplayTreeNode<T>* &);
};

template <class T>
SplayTree<T>::SplayTree():root(NULL)
{
}

template <class T>
SplayTree<T>::~SplayTree()
{
    Destroy(root);
}
template <class T>
SplayTreeNode<T>* SplayTree<T>::Search(SplayTreeNode<T>* x, T key) const
{
    if(x == NULL || x->key ==key)
        return x;
    if(key < x->key) return Search(x->left, key);
    else             return Search(x->right, key);
}
template <class T>
SplayTreeNode<T>* SplayTree<T>::Splay(SplayTreeNode<T>* tree, T key)
{
    SplayTreeNode<T> N, *l, *r, *c;

    if (tree == NULL)
        return tree;

    N.left = N.right = NULL;
    l = r = &N;

    for (;;)
    {
        if (key < tree->key)
        {
            if (tree->left == NULL)
                break;
            if (key < tree->left->key)
            {
                c = tree->left;
                tree->left = c->right;
                c->right = tree;
                tree = c;
                if (tree->left == NULL)
                    break;
            }
            r->left = tree;
            r = tree;
            tree = tree->left;
        }
        else if (key > tree->key)
        {
            if (tree->right == NULL)
                break;
            if (key > tree->right->key)
            {
                c = tree->right;
                tree->right = c->left;
                c->left = tree;
                tree = c;
                if (tree->right == NULL)
                    break;
            }
            l->right = tree;
            l = tree;
            tree = tree->right;
        }
        else
        {
            break;
        }
    }

    l->right = tree->left;
    r->left = tree->right;
    tree->left = N.right;
    tree->right = N.left;

    return tree;
}

template <class T>
void SplayTree<T>::Splay(T key)
{
    root = Splay(root, key);
}

template <class T>
SplayTreeNode<T>* SplayTree<T>::Insert(SplayTreeNode<T>* &tree, SplayTreeNode<T>* z)
{
    SplayTreeNode<T> *y = NULL;
    SplayTreeNode<T> *x = tree;
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else if (z->key > x->key)
            x = x->right;
        else
        {
            
            delete z;
            return tree;
        }
    }

    if (y==NULL)
        tree = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;

    return tree;
}

//插入节点
template <class T>
void SplayTree<T>::Insert(T key)
{
    SplayTreeNode<T> *z=NULL;
    if ((z=new SplayTreeNode<T>(key,NULL,NULL)) == NULL)
        return ;
    root = Insert(root, z);
    root = Splay(root, key);
}

template <class T>
SplayTreeNode<T>* SplayTree<T>::Delete(SplayTreeNode<T>* &tree, T key)
{
    SplayTreeNode<T> *x;

    if (tree == NULL)
        return NULL;
    if (Search(tree, key) == NULL)
        return tree;
    tree = Splay(tree, key);

    if (tree->left != NULL)
    {
        x = Splay(tree->left, key);
        x->right = tree->right;
    }
    else
        x = tree->right;

    delete tree;

    return x;

}

template <class T>
void SplayTree<T>::Delete(T key)
{
    root = Delete(root, key);
}

template <class T>
void SplayTree<T>::Destroy(SplayTreeNode<T>* &tree)
{
    if (tree==NULL)
        return ;

    if (tree->left != NULL)
        Destroy(tree->left);
    if (tree->right != NULL)
        Destroy(tree->right);

    delete tree;
}

template <class T>
void SplayTree<T>::Destroy()
{
    Destroy(root);
}

#endif // SPLAY_H