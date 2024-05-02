#include "UBS.hpp"

UBS_TREE::UBS_TREE()
{
    this->root = NULL;
}

int UBS_TREE::findmax( UBStree root)
{
    while ( root->right != NULL )
    {
        root = root->right;
    }
    return root->num;
}

int UBS_TREE::findmin( UBStree root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->num;
}

UBStree UBS_TREE::insert( UBStree root, int num)
{
    //cout <<"ok" << endl;
    if (!root)
    {
        root = (UBStree) malloc ( sizeof(node));
        //cout <<"ok" << endl;
        root->num = num;
        root->height = 0;
        root->left = root->right = NULL;
    }
    else if ( num > root->num )
    {
        root->right = insert( root->right, num);
    }
    else
    {
        root->left = insert( root->left, num);
    }

    return root;
}

UBStree UBS_TREE::deletenode( UBStree root, int num)
{
    if ( !root )
    {
        return NULL;
    }
    else if ( num > root->num )
    {
        root->right = deletenode( root->right, num);
    }
    else if ( num < root->num )
    {
        root->left = deletenode( root->left, num);
    }
    else
    {
        UBStree tmp;
        if( !root->left && !root->right )
        {
            delete root;
            return NULL;
        }
        else if ( root->left == NULL )
        {
            tmp = root->right;
            delete root;
            return tmp;
        }
        else if ( root->right == NULL )
        {
            tmp = root->left;
            delete root;
            return tmp;
        }
        else
        {
            root->num = findmax(root->left);
            root->left = deletenode( root->left, root->num);
        }
    }

    return root;
}
