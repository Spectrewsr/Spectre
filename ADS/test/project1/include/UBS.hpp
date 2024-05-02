#ifndef _UBS_HPP_
#define _UBS_HPP_
#include "node.hpp"
#include <iostream>
using namespace std;
typedef AVLtree UBStree;
class UBS_TREE
{
private:
    int findmax( UBStree root);
    int findmin( UBStree root);

public:
    UBStree root;
    UBS_TREE();
    UBStree insert( UBStree root, int num);
    UBStree deletenode( UBStree root, int num);

};

#endif