#ifndef _NODE_HPP_
#define _NODE_HPP_

typedef struct node{
    int height;
    int num;
    struct node* left;
    struct node* right;
    //struct node* father;
}Node;

typedef struct node *AVLtree;

#endif