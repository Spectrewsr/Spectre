#ifndef NODE_H
#define NODE_H
#include<iostream>
typedef struct node{
    int height;
    int num;
    struct node* left;
    struct node* right;
    //struct node* father;
}Node;
typedef struct node *AVLtree;
template <class T>
class SplayTreeNode
{
    public:
        T key;
        SplayTreeNode *left;
        SplayTreeNode *right;

        SplayTreeNode():left(NULL), right(NULL){};
        SplayTreeNode(T value, SplayTreeNode* l, SplayTreeNode* r):key(value), left(l), right(r){};
};

#endif // NODE_H