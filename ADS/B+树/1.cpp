#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

#define ORDER 3

using namespace std;

class Node
{
public:
    int cnt_data = 0;  // 该节点所保存的数据量
    int cnt_child = 0;  // 子节点数
    int data[ORDER + 1];   // 该节点所保存的具体数据（非叶子节点为索引，叶子节点为数据）
    Node *child[ORDER + 2]; // 子节点
    Node *parent = NULL; // 父节点，节点分裂时使用，根节点为NULL
    Node *next; // 作为叶子节点时的相邻节点，实际上并没有用到这个
    Node ()
    {}

    /**
     * 通过给定的数据进行初始化
     * @param pra 父节点
     * @param data_src 用来赋值data的数据源
     * @param data_interval [first,second)左闭右开的区间，表示data_src具体传入的数据区间
     * @param child_src 用来赋值child的数据源
     * @param child_interval 同data_interval
     */
    Node (Node *pra, int data_src[], pair<int, int> data_interval, Node *child_src[], pair<int, int> child_interval)
    {
        this->parent = pra;
        this->cnt_data = data_interval.second - data_interval.first;
        memcpy(this->data, data_src + data_interval.first, this->cnt_data * sizeof(data_src[0]));
        this->cnt_child = child_interval.second - child_interval.first;
        memcpy(this->child, child_src + child_interval.first, this->cnt_child * sizeof(child_src[0]));
        // 将子节点的父节点指针指向该节点
        for (int i = 0; i < cnt_child; ++i)
        {
            child[i]->parent = this;
        }
    }

    void print ()
    {
        printf("[");
        for (int i = 0; i < cnt_data; ++i)
        {
            if (i)
                printf(",");
            printf("%d", data[i]);
        }
        printf("]");
    }
};

int n;
Node *Root = new Node();

// DEBUG
int split_time = 0;

/**
 * 后续再插入新的子节点后，为某一个节点的子节点属性排序时用到
 * 排序依据为节点第一个数据项的大小
 * @param p1
 * @param p2
 * @return
 */
bool cmp (Node *p1, Node *p2)
{
    return p1->data[0] < p2->data[0];
}

/**
 * 层序遍历并打印
 */
void print_tree ()
{
    Node *BlankLine = NULL; // 换行标记，标记一层节点
    queue<Node *> que;
    que.push(Root);
    que.push(BlankLine);
    while (!que.empty())
    {
        Node *t = que.front();
        que.pop();
        if (t == BlankLine)
        {
            printf("\n");
            if (!que.empty())
                que.push(BlankLine);
            continue;
        }
        t->print();
        for (int i = 0; i < t->cnt_child; ++i)
        {
            que.push(t->child[i]);
        }

    }
}

/**
 * 检查并分裂当前节点，当前节点分裂完成后递归检查父节点是否需要分裂。
 * @param node 待分裂的节点
 */
void split (Node *node)
{
    // 用node指针获取变量太长，用局部变量简化
    int cntData = node->cnt_data;
    int cntChild = node->cnt_child;
    bool is_leaf = cntChild == 0;
    Node **child = node->child;
    int *data = node->data;

    // 不需要分裂
    if ((is_leaf && cntData <= ORDER) ||
        (!is_leaf && cntData < ORDER))
    {
        return;
    }

    // 当前节点为根节点，则生成新的根节点
    if (node->parent == NULL)
    {
        Root = node->parent = new Node();
    }

    Node *pra = node->parent;

    int mid ;

    // 分裂为左右两个节点
    Node *l ;
    Node *r ;

    // 对于叶子节点和非叶子节点分别处理
    if (is_leaf)
    {
        // mid = 2; // 等效
        mid = ceil(1.0*ORDER/2);
        
        l = new Node(pra, data, make_pair(0, mid), child, make_pair(0, 0));
        r = new Node(pra, data, make_pair(mid, cntData), child, make_pair(0, 0));
    } else
    {
        // mid = 1; // 等效
        mid = ceil(1.0*(ORDER-1)/2);
        
        l = new Node(pra, data, make_pair(0, mid), child, make_pair(0, mid+1));
        r = new Node(pra, data, make_pair(mid+1, cntData), child, make_pair(mid+1, cntChild));
    }
    
    // 更新父节点的索引
    pra->data[pra->cnt_data++] = data[mid];

    // 替换父节点的子节点列表中保存的当前节点（当前节点已经分裂为2个子节点）
    if (pra->cnt_child > 0)
        for (int i = 0; i < pra->cnt_child; ++i)
        {
            if (pra->child[i] == node)
            {
                pra->child[i] = l;
                break;
            }
        }
    else
        pra->child[pra->cnt_child++] = l;

    pra->child[pra->cnt_child++] = r;

    // 排序，上一步直接插入可能会导致乱序
    sort(pra->data, pra->data + pra->cnt_data);
    sort(pra->child, pra->child + pra->cnt_child, cmp);

    // 释放当前节点的所占的空间
    delete node;

    // 递归检查父节点是否需要分裂
    split(pra);
}


/**
 * 插入数据
 * @param node
 * @param n
 */
void insert (Node *node, int n)
{
    if (node == NULL)
    {
        node = new Node();
    }
    node->data[node->cnt_data++] = n;
    sort(node->data, node->data + node->cnt_data);
    split(node);
}

/**
 * 查找n应在的Node对象，实际上n不一定存在B+树中
 * 数据被m个索引分成了m+1段，即子树的数量比索引的数量多1，所以用upper_bound找到的第一个大于n的索引下标，放到其孩子列表中恰好为n所在的子树的下标
 * @param root
 * @param n
 * @return 返回n应在的叶子节点的指针
 */
Node *find (Node *root, int n)
{
    if (root == NULL)
        return root;
    // 叶子节点
    if (root->cnt_child == 0)
        return root;
    
    int i = upper_bound(root->data, root->data + root->cnt_data, n) - root->data;
    return find(root->child[i], n);

}


/**
 * 判断n是否存在
 * @param node 用find方法找到的n应在的叶子节点
 * @param n
 * @return
 */
bool exist (Node *node, int n)
{
    if (node == NULL)
        return false;
    return binary_search(node->data, node->data + node->cnt_data, n);
}

int main ()
{
    int cc = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int num;
        //scanf("%d", &num);
        num = cc++;
        Node *leaf = find(Root, num);
        if (!exist(leaf, num))
            insert(leaf, num);
        else
        {
            printf("Key %d is duplicated\n", num);
        }
    }

    print_tree();

    return 0;
}
