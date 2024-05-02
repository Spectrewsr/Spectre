#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    bool isLeaf;
    int cnt;
    vector<int> val;
    Node* left;
    Node* brother;
    Node* father;
    Node():isLeaf(false), left(NULL), brother(NULL), father(NULL){}
};

class BTree
{
private:
    int conN;
    Node* BTroot;
    Node* BTNull;
    void Insert(Node*, int);
    void Update(Node*, int, int);
public:
    BTree(int x): conN(x){ BTroot = NULL;}
    ~BTree(){};
    void Insert(int);
    void Print();
};
void BTree::Update(Node* now, int ori, int brand)
{
    if(now == NULL) return;
    //printf("tt%d %d\n", ori, brand);
    for(int i = 0; i < now->cnt; ++i)
        if(now->val[i] == ori)
        {
            now->val[i] = brand;
            Update(now->father, ori, brand);
        }
    return;
}
void BTree::Insert(Node* now, int val)
{
    if(now->isLeaf == true)
    {
        for(int i = 0; i < now->cnt; ++i)
            if(now->val[i] == val)
            {
                printf("Key %d is duplicated\n", val);
                return;
            }
        now->val.push_back(val);
        ++now->cnt;
        int x = val, y = now->val[0];
        sort(now->val.begin(), now->val.end());
        if(x < y) Update(now->father, y, x);
    }
    else
    {
        Node* next = now->left;
        for(int i = 1; i < now->cnt; ++i)
        {
            if(val < now->val[i]) break;
            next = next->brother;
        }
        Insert(next, val);
    }
    if(now->cnt > conN)
    {
        Node* x = new Node();
        x->isLeaf = now->isLeaf;
        x->father = now->father;
        for(int i = now->cnt / 2; i < now->cnt; ++i) x->val.push_back(now->val[i]);
        now->val.resize(now->cnt / 2);
        x->cnt = (now->cnt + 1) / 2;
        now->cnt = now->cnt / 2;
        x->brother = now->brother;
        now->brother = x;
        if(now->isLeaf == false)
        {
            Node* t = now->left;
            for(int i = 1; i < now->cnt; ++i) t = t->brother;
            Node* p = t->brother;
            t->brother = NULL;
            x->left = p;
            while(p) { p->father = x; p = p->brother; }
        }
        if(now == BTroot)
        {
            Node* t = new Node();
            t->left = now;
            BTroot = t;
            now->father = t; x->father = t;
            t->cnt ++;
            t->val.push_back(now->val[0]);
        }
        now->father->cnt ++;
        now->father->val.push_back(x->val[0]);
        sort(now->father->val.begin(), now->father->val.end());
    }
    return;
}
void BTree::Insert(int val)
{
    if(BTroot == NULL)
    {
        BTroot = new Node();
        BTroot->isLeaf = true;
        BTroot->cnt = 1;
        BTroot->val.push_back(val);
    }
    else
    {
        Insert(BTroot, val);
    }
}
void BTree::Print()
{
    queue<Node*> Q;
    Q.push(BTroot);
    Q.push(NULL);
    while(!Q.empty())
    {
        Node* now = Q.front();
        Q.pop();
        if(now == NULL)
        {
            if(!Q.empty()) Q.push(NULL);
            printf("\n");
            continue;
        }
        if(now->isLeaf)
        {
            printf("[%d", now->val[0]);
            for(int i = 1; i < now->cnt; ++i) printf(",%d", now->val[i]);
            printf("]");
        }
        else
        {
            printf("[%d", now->val[1]);
            for(int i = 2; i < now->cnt; ++i) printf(",%d", now->val[i]);
            printf("]");
        }
        for(Node* t = now->left; t; t = t->brother) Q.push(t);
    }
    return;
}
int main()
{
    BTree tree(3);
    int T;
    int x;
    int cc = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &x);
        //x = cc++;
        tree.Insert(x);
        // tree.Print();
        // printf("\n");
    }
    tree.Print();
    return 0;
}
