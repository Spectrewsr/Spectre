#include <iostream>
#include <cmath>
using namespace std;
typedef struct node{
    int height;
    int num;
    struct node* left;
    struct node* right;
    struct node* father;
}Node, *pointn;

int HEI( pointn head)
{
    if ( !head)
    {
        return -1;
    }
    else
    {
        return head-> height;
    }
}

pointn RL(pointn a)
{
    pointn b = a->right;
    pointn c = b->left;
    //std::cout<<"ok"<<std::endl;
    a->right = c->left;
    if (c->left!=NULL)
    {
        c->left->father = a;
    }
    
    b->left = c->right;
    if (c->right!=NULL)
    {
        b->left->father = b;
    }
    //std::cout<<"ok"<<std::endl;
    a->father = b->father = c;
    c->left = a;
    c->right = b;
    a->height = std::max( HEI(a->left), HEI(a->right)) +1;
    b->height = std::max( HEI(b->left), HEI(b->right)) +1;
    c->height = std::max( HEI(a), HEI(b)) +1;
    return c;
}

pointn LR(pointn a)
{
    pointn b = a->left;
    pointn c = b->right;

    c->father = a->father;
    b->right = c->left;
    if (c->left)
    {
        b->right->father = b;
    }
    a->left = c->right;
    if(c->right)
    {
        c->right->father = a;
    }

    c->right = a;
    c->left = b;
    a->height = std::max( HEI(a->left), HEI(a->right)) +1;
    b->height = std::max( HEI(b->left), HEI(b->right)) +1;
    c->height = std::max( HEI(a), HEI(b)) +1;
    return c;
}

pointn LL(pointn a)
{
    pointn  b=a->left ;

    b->father = a->father;
    a->left = b->right;
    if (b->right != NULL)
    {
        b->right->father = a;
    }
    b->right = a;
    a->height = std::max( HEI(a->left), HEI(a->right))+1;
    b->height = std::max( HEI(a), HEI(b->right))+1;
    return b;
}

pointn RR(pointn a)
{
    //std::cout<<"ok"<<std::endl;
    pointn b = a -> right;
    a->right = b->left;
    //std::cout<<"ok"<<std::endl;
    if ( b->left != NULL)
    {
        //cout << b->left->father->num<<endl;
        b->left->father = a;
    }
    
    //std::cout<<"ok"<<std::endl;
    b->father = a->father;
    //std::cout<<"ok"<<std::endl;
    a->father = b;
    b->left = a;
    //std::cout<<"ok"<<std::endl;
    a->height = std::max( HEI(a->left), HEI(a->right))+1;
    b->height = std::max( HEI(a), HEI(b->right))+1;
    return b;
}

pointn insert( pointn father, pointn head, int num)
{
    if (!head)
    {
        head = (pointn)malloc(sizeof(node));
        
        head->num = num;
        head->height = 0;
        head->left = head -> right = NULL;
        head-> father = father;
        
    }

    else if ( num > head -> num)
    {
        //std::cout<<"RR?"<<std::endl;
        head->right = insert( head, head-> right, num);
        if ( HEI(head->left) - HEI(head->right) == -2)
        {
            if ( num > head->right->num)
            {
                //std::cout<<"RR"<<std::endl;
                head = RR(head); 
            }
            else
            {
                //std::cout<<"RL"<<std::endl;
                head = RL(head);
            }
        }
    }

    else if( num <= head->num)
    {
        head->left = insert( head, head->left, num);
        if (HEI(head->left) - HEI(head->right) == 2)
        {
            if (num < head->left->num)
            {
                head = LL(head);
            }
            else
            {
                head = LR(head);
            }
        }
    }

    head->height = std::max( HEI(head->left), HEI(head->right))+1;
    return head;
}

int main()
{
    int num, N;
    std::cin >> num;

    pointn head = NULL;
    
    while(num--)
    {
        std::cin>>N;
        
        //printf("%d\n",num);
        head = insert( NULL, head, N);

    }
    if (head!=NULL)
    {
        std::cout <<head->num;
        // cout <<endl;
        // cout <<head->left->num<<endl;
        // cout <<head->right->num<<endl;
        // cout <<head->left->left->num<<endl;
    }
    return 0;
}