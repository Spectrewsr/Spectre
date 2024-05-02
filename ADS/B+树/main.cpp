#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
//B+tree   240312

struct Node
{
    int data[4] = {0};
    Node* parent = nullptr;
    int cnt = 0;//自身数据数量
    int num_of_child = 0;//子节点数
    Node* child[4] ;
    bool is_leaf = true;
    Node* before = nullptr;
    Node* next = nullptr;
    Node() 
    {for (int i = 0; i < 4; ++i) {
        child[i] = nullptr;
    }}
};

class BBtree
{
private:
   

public:
    BBtree()
    {
        Root = new Node();
    }
    ~BBtree()
    {

    }

    bool cmp (Node *p1, Node *p2)
    {
        return p1->data[0] < p2->data[0];
    }
    Node* Root;

    void insert( Node* root, int num)
    {
        if (root == nullptr)
        {
            root = new Node();
            root->data[root->cnt++] = num;
            root->is_leaf = true;   
            std::sort(root->data, root->data + root->cnt);
            split(root);        
        }
        else if(root->is_leaf)
        {
            root->data[root->cnt++] = num;
            std::sort(root->data, root->data + root->cnt);
            split(root); 
        }
    }

    void split(Node* root)
    {
        int ndata = root->cnt;
        int nchild = root->num_of_child;
        bool is_leaf = root->is_leaf;
        int *data = root->data;

        if ((is_leaf && ndata <= 3) || (!is_leaf && ndata < 3))
        {
            return;
        }

        
        if (root->parent == NULL)
        {
            //printf("newRoot   %d\n",root->data[0]);
            Node* newRoot;
            newRoot = new Node();
            newRoot ->parent = nullptr;
            root->parent = newRoot;
            newRoot->is_leaf = false;
            Root = newRoot;
        }

        int mid;
        Node* left = new Node(); Node* right = new Node();
        Node* grandparent = root->parent;
        if (root->before)
        {
            root->before->next = left;
            left->before = root->before;
        }
        if (root->next)
        {
            right->next = root->next;
            root->next->before = right;
        }
        left->next = right;right->before = left;
        left->parent = right->parent = grandparent;

        if (is_leaf)
        {
            //printf("is_leaf    %d\n",root->cnt);
            mid = 2;
            left->data[left->cnt++] = data[0]; left->data[left->cnt++] = data[1];
            right->data[right->cnt++] = data[2]; right->data[right->cnt++] = data[3];
            //printf("leaf: %d   %d\n", left->cnt, right->cnt);
        }
        else
        {
            //printf("!is_leaf\n");
            mid = 1;
            left->is_leaf = right->is_leaf = false;
            

            left->child[left->num_of_child++] = root->child[0]; left->child[left->num_of_child++] = root->child[1];
            root->child[0]->parent = root->child[1]->parent = left;
            left->data[left->cnt++] = upload(left->child[1]);
            right->child[right->num_of_child++] = root->child[2]; right->child[right->num_of_child++] = root->child[3];
            root->child[2]->parent = root->child[3]->parent = right;
            right->data[right->cnt++] = upload(right->child[1]);
        }
        root->is_leaf = false;
        grandparent->data[grandparent->cnt++] = data[mid];
        if (grandparent->num_of_child > 0)
        {
            for ( int i = 0; i < grandparent->num_of_child; ++i )
            {
                if (grandparent->child[i] == root)
                {
                    grandparent->child[i] = left;
                    break;
                }
            }
        }
        else
        {
            grandparent->child[grandparent->num_of_child++] = left;
        }

        grandparent->child[grandparent->num_of_child++] = right;

        std::sort( grandparent->data, grandparent->data + grandparent->cnt);
        std::sort(grandparent->child, grandparent->child + grandparent->num_of_child,
            [this](Node* a, Node* b) { return this->cmp(a, b); });
        delete root;
        split(grandparent);
    }

    Node* find_leaf(Node* root, int value)
    {
        if (root->is_leaf)
            return root;
        
        int i = std::upper_bound(root->data, root->data + root->cnt, value) - root->data;
        return find_leaf(root->child[i], value);
    }
    // bool check_if_exist(Node* root, int value)
    // {
    //     if (root == nullptr)
    //     {
    //         return false;
    //     }
    //     else if (root->is_leaf)
    //     {
    //         return std::binary_search(root->data, root->data + root->cnt, value);
    //     }
    //     else
    //     {
    //         int i;
    //         for (i = 0; i < root->cnt; ++i )
    //         {
    //             if (value > root->data[i])
    //             {
    //                 break;
    //             }
    //         }
    //         return check_if_exist(root->child[i], value);
    //     }
    // }

    int upload(Node* root)
    {
        while (!root->is_leaf)
        {
            root = root->child[0];
        }
        return root->data[0];
    }
};

int main()
{
    int num, key, cc = 0;
    std::cin >> num;
    BBtree btree;
    Node* leaf;
    std::map<int,int> mp;
    Node* i; Node* j;
    while(num--)
    {
        std::cin >> key;
        cc++;
        // key = cc;
        Node* leaf = btree.find_leaf(btree.Root,key);
        if (mp[key] == 0)
        {
            //std::cout <<"ok0"<<std::endl;
            //std::cout <<"ok0"<<std::endl;
            
            btree.insert( leaf, key);
            mp[key] = 1;
            //sumarry.push_back(key);
            //std::sort(sumarry.begin(), sumarry.end());
            // for ( i = btree.Root; i; i = i->child[0])
            // {
            //     j = i;
            //     while (j)
            //     {
            //         //printf("%d",j->cnt);
            //         std::cout <<"[";
            //         //printf("%d,%d",j->cnt,j->data[j->cnt-1]);
            //             for ( int ii = 0; ii < j->cnt-1; ++ii)
            //             {
            //                 printf("%d,",j->data[ii]);
            //             }
            //             printf("%d",j->data[j->cnt-1]);
            //         std::cout<<"]";
            //         //std ::cout<<j->next<<std::endl;
            //         j = j->next;
            //     }
            //     //std::cout<<i->child[0];
            //     printf("\n")  ;
            // }
            //std::cout<<btree.Root->cnt<<std::endl;
            //std::cout<<btree.Root->child[0]<<btree.Root->child[1]<<btree.Root->child[2]<<btree.Root->child[3]<<std::endl;
        }
        else
        {
            std::cout <<"Key "<<key<<" is duplicated"<<std::endl;
        }
        //std::cout <<"ok1"<<std::endl;
    }

    
    for ( i = btree.Root; i; i = i->child[0])
    {
        j = i;
        while (j)
        {
            //printf("%d",j->cnt);
            std::cout <<"[";
            //printf("%d,%d",j->cnt,j->data[j->cnt-1]);
                for ( int ii = 0; ii < j->cnt-1; ++ii)
                {
                    printf("%d,",j->data[ii]);
                }
                printf("%d",j->data[j->cnt-1]);
            std::cout<<"]";
            //std ::cout<<j->next<<std::endl;
            j = j->next;
        }
        //std::cout<<i->child[0];
        printf("\n")  ;
    }
    
    return 0;
}