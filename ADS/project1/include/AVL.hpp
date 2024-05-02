#ifndef _AVL_HPP_
#define _AVL_HPP_

#include <iostream>
#include <algorithm>
#include <math.h>
#include "Node.hpp"

using namespace std;


class AVL_TREE
{
private:
    AVLtree RL(AVLtree a);
    AVLtree LR(AVLtree a);
    AVLtree LL(AVLtree a);
    AVLtree RR(AVLtree a);

public:
    AVLtree root;
    AVL_TREE();
    int get_root_height( AVLtree root);
    AVLtree insert( AVLtree root, int num);
    int findmax( AVLtree root);
    int findmin( AVLtree root);
    AVLtree deletenode( int num, AVLtree root);
};

#endif