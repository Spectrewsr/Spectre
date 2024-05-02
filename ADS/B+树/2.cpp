#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
 const int M = 4; // B+树的阶数
const int MM = 2 * M;
const int L = 5; // 叶节点能容纳的最大键值对数
 struct Node {
    bool leaf; // 是否为叶节点
    Node* parent; // 父节点
    Node* children[MM + 1]; // 子节点
    int values[MM]; // 记录值
    int cnt; // 子节点数或者键值对数
};
 class BPlusTree {
public:
    BPlusTree();
    ~BPlusTree();
     void insert(int value); // 插入记录
    void show(); // 显示整棵B+树
 private:
    void split(Node* x, int idx); // 对满节点分裂
    void insertNonfull(Node* x, int value); // 插入到非满节点
    void show(Node* x, int num); // 递归显示某个节点及其子树
     Node* root; // 根节点
};
 BPlusTree::BPlusTree() {
    root = NULL;
}
 BPlusTree::~BPlusTree() {
    // TODO
}
 void BPlusTree::split(Node* x, int idx) {
    Node* y = new Node();
    Node* z = x->children[idx];
    y->leaf = z->leaf;
    y->cnt = L;
    z->cnt = L;
     // 将z节点的后L个值移动到y节点
    memcpy(y->values, z->values + L, sizeof(int) * L);
    if(!y->leaf) {
        memcpy(y->children, z->children + L, sizeof(Node*) * (L + 1));
        for(int i = L; i < MM; i++) {
            z->children[i] = NULL;
        }
    }
    z->cnt = L;
     // 为父节点x插入键值，并将y节点加入到x的子节点中
    for(int i = x->cnt + 1; i > idx + 1; i--) {
        x->children[i] = x->children[i - 1];
    }
    x->children[idx + 1] = y;
    for(int i = x->cnt; i > idx; i--) {
        x->values[i] = x->values[i - 1];
    }
    x->values[idx] = z->values[L];
    x->cnt++;
}
 void BPlusTree::insertNonfull(Node* x, int value) {
    int i = x->cnt - 1;
     if(x->leaf) {
        while(i >= 0 && value < x->values[i]) {
            x->values[i + 1] = x->values[i];
            i--;
        }
        x->values[i + 1] = value;
        x->cnt++;
    }
    else {
        while(i >= 0 && value < x->values[i]) {
            i--;
        }
        i++;
        if(x->children[i]->cnt == MM) {
            split(x, i);
            if(value > x->values[i]) {
                i++;
            }
        }
        insertNonfull(x->children[i], value);
    }
}
 void BPlusTree::insert(int value) {
    if(root == NULL) {
        root = new Node();
        root->leaf = true;
        root->cnt = 1;
        root->values[0] = value;
    }
    else {
        if(root->cnt == MM) {
            Node* s = new Node();
            s->leaf = false;
            s->children[0] = root;
            split(s, 0);
            root = s;
            if(value > root->values[0]) {
                insertNonfull(root->children[1], value);
            }
            else {
                insertNonfull(root->children[0], value);
            }
        }
        else {
            insertNonfull(root, value);
        }
    }
}
 void BPlusTree::show() {
    if(root != NULL) {
        show(root, 0);
    }
}
 void BPlusTree::show(Node* x, int num) {
    cout << "(" << num << ")";
    for(int i = 0; i < x->cnt; i++) {
        cout << x->values[i] << " ";
    }
    cout << endl;
    if(!x->leaf) {
        for(int i = 0; i <= x->cnt; i++) {
            if(x->children[i] != NULL) {
                show(x->children[i], num + 1);
            }
        }
    }
}
 int main() {
    BPlusTree tree;
    for(int i = 0; i < 20; i++) {
        tree.insert(i);
    }
    tree.show();
     return 0;
}