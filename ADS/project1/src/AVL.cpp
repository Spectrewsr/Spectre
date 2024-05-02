#include "AVL.hpp"

using namespace std;
// typedef struct node{
//     int height;
//     int num;
//     struct node* left;
//     struct node* right;
//     //struct node* father;
// }Node;

// typedef struct node *AVLtree;

// class AVL_TREE
// {
// private:
//     AVLtree RL(AVLtree a);
//     AVLtree LR(AVLtree a);
//     AVLtree LL(AVLtree a);
//     AVLtree RR(AVLtree a);

// public:
//     AVLtree root;
//     AVL_TREE();
//     int get_root_height( AVLtree root);
//     AVLtree insert( AVLtree father, AVLtree root, int num);
//     int findmax( AVLtree root);
//     int findmin( AVLtree root);
//     AVLtree deletenode( int num, AVLtree root);
// };


// RL旋转
AVLtree AVL_TREE::RL(AVLtree a)
{
    AVLtree b = a->right;
    AVLtree c = b->left;

    // 进行旋转操作
    a->right = c->left;
    b->left = c->right;
    c->left = a;
    c->right = b;

    // 更新节点高度
    a->height = std::max(get_root_height(a->left), get_root_height(a->right)) + 1;
    b->height = std::max(get_root_height(b->left), get_root_height(b->right)) + 1;
    c->height = std::max(get_root_height(a), get_root_height(b)) + 1;

    // 返回旋转后的根节点
    return c;
}

// LR旋转
AVLtree AVL_TREE::LR(AVLtree a)
{
    AVLtree b = a->left;
    AVLtree c = b->right;

    // 进行旋转操作
    a->left = c->right;
    b->right = c->left;
    c->right = a;
    c->left = b;

    // 更新节点高度
    a->height = std::max(get_root_height(a->left), get_root_height(a->right)) + 1;
    b->height = std::max(get_root_height(b->left), get_root_height(b->right)) + 1;
    c->height = std::max(get_root_height(a), get_root_height(b)) + 1;

    // 返回旋转后的根节点
    return c;
}


// LL旋转
AVLtree AVL_TREE::LL(AVLtree a)
{
    AVLtree b = a->left;

    // 进行旋转操作
    a->left = b->right;
    b->right = a;

    // 更新节点高度
    a->height = std::max(get_root_height(a->left), get_root_height(a->right)) + 1;
    b->height = std::max(get_root_height(a), get_root_height(b->right)) + 1;

    // 返回旋转后的根节点
    return b;
}

// RR旋转
AVLtree AVL_TREE::RR(AVLtree a)
{
    AVLtree b = a->right;

    // 进行旋转操作
    a->right = b->left;
    b->left = a;

    // 更新节点高度
    a->height = std::max(get_root_height(a->left), get_root_height(a->right)) + 1;
    b->height = std::max(get_root_height(a), get_root_height(b->right)) + 1;

    // 返回旋转后的根节点
    return b;
}


AVL_TREE::AVL_TREE()
    {
        this->root = NULL;
    }

int AVL_TREE::get_root_height( AVLtree root)
    {
        if (!root)
        {
            return -1;
        }
        else
        {
            return root->height;
        }
    }

// 向AVL树中插入节点
AVLtree AVL_TREE::insert(AVLtree root, int num)
{
    // 如果根节点为空，创建新节点作为根节点
    if (!root)
    {
        root = (AVLtree)malloc(sizeof(node));
        root->num = num;
        root->height = 0;
        root->left = root->right = NULL;
        //root->father = father;
    }
    // 如果要插入的值大于根节点值，递归插入右子树，并进行平衡性检查
    else if (num > root->num)
    {
        root->right = insert(root->right, num);
        if (get_root_height(root->left) - get_root_height(root->right) == -2)
        {
            if (num > root->right->num)
            {
                root = RR(root);
            }
            else
            {
                root = RL(root);
            }
        }
    }
    // 如果要插入的值小于等于根节点值，递归插入左子树，并进行平衡性检查
    else if (num <= root->num)
    {
        root->left = insert(root->left, num);
        if (get_root_height(root->left) - get_root_height(root->right) == 2)
        {
            if (num < root->left->num)
            {
                root = LL(root);
            }
            else
            {
                root = LR(root);
            }
        }
    }
    // 更新节点的高度
    root->height = std::max(get_root_height(root->left), get_root_height(root->right)) + 1;
    return root;
}


// 在AVL树中查找最大值
int AVL_TREE::findmax(AVLtree root)
{
    // 循环找到右子树中的最右节点
    while (root->right != NULL)
    {
        root = root->right;
    }
    // 返回找到的最大值
    return root->num;
}

// 在AVL树中查找最小值
int AVL_TREE::findmin(AVLtree root)
{
    // 循环找到左子树中的最左节点
    while (root->left != NULL)
    {
        root = root->left;
    }
    // 返回找到的最小值
    return root->num;
}


AVLtree AVL_TREE::deletenode(int num, AVLtree T)
{
    AVLtree tmp;
    if (T == NULL)
    {
        return NULL;
    }
    // 如果要删除的值比当前节点小，递归删除左子树中的对应节点
    else if (num < T->num)
    {
        T->left = deletenode(num, T->left);
        // 平衡性检查
        if (get_root_height(T->right) - get_root_height(T->left) >= 2)
        {
            tmp = T->right;
            // 右子树的右子树比右子树的左子树高
            if (get_root_height(tmp->right) > get_root_height(tmp->left))
            {
                T = RR(T);
            }
            // 否则执行RL旋转
            else
            {
                T = RL(T);
            }
        }
    }
    // 如果要删除的值比当前节点大，递归删除右子树中的对应节点
    else if (num > T->num)
    {
        T->right = deletenode(num, T->right);
        // 平衡性检查
        if (get_root_height(T->left) - get_root_height(T->right) >= 2)
        {
            tmp = T->left;
            // 左子树的左子树比左子树的右子树高
            if (get_root_height(tmp->left) > get_root_height(tmp->right))
            {
                T = LL(T);
            }
            // 否则执行LR旋转
            else
            {
                T = LR(T);
            }
        }
    }
    // 找到要删除的节点
    else
    {
        // 如果要删除的节点是叶子节点，直接删除
        if (!T->left && !T->right)
        {
            delete T;
            return NULL;
        }
        // 如果要删除的节点只有一个孩子节点，将该节点删除并返回其孩子节点
        else if (T->left == NULL)
        {
            tmp = T->right;
            delete T;
            return tmp;
        }
        else if (T->right == NULL)
        {
            tmp = T->left;
            delete T;
            return tmp;
        }
        // 如果要删除的节点有两个孩子节点，将其替换为左子树的最大节点或右子树的最小节点
        else
        {
            // 如果左子树高度大于右子树，将其替换为左子树的最大节点
            if (get_root_height(T->left) > get_root_height(T->right))
            {
                T->num = findmax(T->left);
                T->left = deletenode(T->num, T->left);
            }
            // 否则替换为右子树的最小节点
            else
            {
                T->num = findmin(T->right);
                T->right = deletenode(T->num, T->right);
            }
        }
    }
    // 更新节点的高度
    T->height = max(get_root_height(T->left), get_root_height(T->right)) + 1;
    return T;
}
