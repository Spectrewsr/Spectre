#include <utility>
#include <iostream>
enum Colour
{
	RED,
	BLACK
};

template<class K, class V>
struct RBTreeNode
{
	//三叉链
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	//存储的键值对
	std::pair<K, V> _kv;

	//结点的颜色
	int _col; //红/黑

	//构造函数
	RBTreeNode(const std::pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};

typedef RBTreeNode<int, bool> Node;
typedef int K;
typedef bool V;

RBTreeNode<int, bool>* _root = nullptr;

void  RotateL( Node* parent)
{
    Node* subR = parent->_right;
    Node* subRL = subR->_left;
    Node* parentParent = parent->_parent;

    parent->_right = subRL;
    if(subRL)
    {
        subRL->_parent = parent;
    }

    subR->_left = parent;
    parent->_parent = subR;

    if (parentParent == nullptr)
    {
        _root = subR;
        _root->_parent = nullptr;
    }
    else
    {
        if (parent == parentParent->_left)
        {
            parentParent->_left = subR;
        }
        else
        {
            parentParent->_right = subR;
        }
        subR->_parent = parentParent;
    }
}

void RotateR( Node* parent)
{
    Node* subL = parent->_left;
    Node* subLR = subL -> _right;
    Node* parentParent = parent->_parent;

    parent ->_left = subLR;
    if (subLR)
    {
        subLR->_parent = parent;
    }

    subL->_right = parent;
    parent ->_parent = subL;

    if (parentParent == nullptr)
    {
        _root = subL;
        _root->_parent = nullptr;
    }

    else
    {
        if (parent == parentParent->_left)
        {
            parentParent->_left = subL;
        }
        else
        {
            parentParent->_right = subL;
        }
        subL->_parent = parentParent;
    }
}

void RotateLR(Node* parent)
{
    //std::cout <<parent->_left->_kv.first<<std::endl;
    RotateL(parent->_left);
    std::cout <<parent->_left->_kv.first<<std::endl;
    RotateR(parent);
}

void RotateRL(Node* parent)
{
    RotateR(parent->_right);
    RotateL(parent);
}

std::pair<Node*, bool> Insert( const std::pair<K,V>& kv)
{
    using namespace std;

    if ( _root == nullptr )
    {
        _root = new Node( kv );
        _root->_col = BLACK;
        return make_pair( _root, true);
    }

    Node* cur = _root;
    Node* parent = nullptr;
    while ( cur )
    {
        //std::cout <<"ok"<<endl;
        if ( kv.first > cur->_kv.first)
        {
            
            parent = cur;
            cur = cur->_right;
        }
        else if ( kv.first < cur->_kv.first)
        {  
            parent = cur;
            cur = cur->_left;
            
        }
        else
        {
            return make_pair(_root, false);
        }
    }

    cur = new Node(kv);
    Node* newnode = cur;
    std::cout <<"ok1"<<endl;
    if (kv.first < parent->_kv.first)
    {
        parent->_left = cur;
        cur->_parent = parent;
    }
    else
    {
        parent->_right = cur;
        cur->_parent = parent;
    }
    while (parent&&parent->_col == RED)
    {
        
        Node* grandfather = parent->_parent;
        if (parent == grandfather->_left)
        {
            
            Node* uncle = grandfather->_right;
            if (uncle && uncle->_col == RED)
            {
                parent->_col = uncle->_col = BLACK;
                grandfather->_col = RED;

                cur = grandfather;
                parent = cur->_parent;
            }
            else
            {
                if ( cur == parent->_left )
                {
                    RotateR(grandfather);

                    grandfather->_col = RED;
                    parent->_col = BLACK;
                }
                else
                {
                    if ( kv.first == 19 )
                    {
                        std::cout <<grandfather<<endl;
                        std::cout <<grandfather->_left->_kv.first<<endl;
                    }
                    RotateLR(grandfather);
                    if ( kv.first == 19 )
                    {
                        std::cout <<"ok"<<endl;
                    }
                    grandfather->_col = RED;
                    cur->_col = BLACK;
                    
                }
                break;
            }
        }
        
        else
        {
            Node* uncle = grandfather->_left;
            if (uncle&&uncle->_col == RED)
            {
                uncle->_col = parent->_col = BLACK;
                grandfather->_col = RED;

                cur = grandfather;
                parent = cur->_parent;
            }
            else
            {
                if (cur == parent->_left)
                {
                    RotateRL(grandfather);
                    cur->_col = BLACK;
                    grandfather->_col = RED;
                }
                else
                {
                    RotateL(grandfather);
                    grandfather->_col = RED;
                    parent->_col = BLACK;
                }
                break;
            }
        }
    }
    //cout <<"ok3"<<endl;
    _root->_col = BLACK;
    return make_pair(newnode,true);
}

bool Erase( const K& key)
{
    Node* parent = nullptr;
    Node* cur = _root;
    Node* delParentPos = nullptr;
    Node* delPos = nullptr;
    while (cur)
    {
        if (key < cur->_kv.first)
        {
            parent = cur;
            cur = cur->_left;
        }
        else if ( key > cur->_kv.first )
        {
            parent = cur;
            cur = cur->_right;
        }
        else
        {
            if (cur->_left == nullptr)
            {
                if (cur == _root)
                {
                    _root = _root->_right;
                    if ( _root)
                    {
                        _root->_parent = nullptr;
                        _root->_col = BLACK;
                    }
                    delete cur;
                    return true;
                }
                else
                {
                    delParentPos = parent;
                    delPos = cur;
                }
                break;
            }
            else  if (cur->_right == nullptr)
            {
                if (cur == _root)
                {
                    _root = _root->_left;
                    if(_root)
                    {
                        _root->_parent = nullptr;
                        _root->_col = BLACK;
                    }
                    delete cur;
                    return true;
                }
                else
                {
                    delParentPos = parent;
                    delPos = cur;
                }
                break;
            }
            else
            {
                Node* minParent = cur;
                Node* minRight = cur->_right;
                while (minRight->_left)
                {
                    minParent = minRight;
                    minRight = minRight->_left;
                }
                cur->_kv.first = minRight->_kv.first;
                cur->_kv.second = minRight->_kv.second;
                delParentPos = minParent;
                delPos = minRight;
                break;
            }
        }
    }

    if (delPos == nullptr)
    {
        return false;
    }

    Node* del = delPos;
    Node* delP = delParentPos;

    if (delPos->_col == BLACK)
    {
        if (delPos->_left)
        {
            delPos->_left->_col = BLACK;
        }
        else if(del->_right)
        {
            delPos->_right->_col = BLACK;
        }
        else
        {
            while (delPos != _root)
            {
                if (delPos == delParentPos->_left)
                {
                    Node* brother = delParentPos->_right;
                    if (brother->_col == RED)
                    {
                        delParentPos->_col = RED;
                        brother->_col = BLACK;
                        RotateL(delParentPos);
                        brother = delParentPos->_right;
                    }

                    if (((brother->_left == nullptr)||(brother->_left->_col == BLACK)) &&((brother->_right == nullptr)||(brother->_right->_col == BLACK)))
                    {
                        brother->_col = RED;
                        if (delParentPos->_col == RED)
                        {
                            delParentPos->_col = BLACK;
                            break;
                        }
                        delPos = delParentPos;
                        delParentPos = delPos->_parent;
                    }
                    else
                    {
                        if ((brother->_right == nullptr) || (brother->_right->_col == BLACK))
                        {
                            brother->_left->_col = BLACK;
                            brother->_col = RED;
                            RotateR(brother);
                            brother = delParentPos->_right;
                        }

                        brother->_col = delParentPos->_col;
                        delParentPos->_col = BLACK;
                        brother->_right->_col = BLACK;
                        RotateL(delParentPos);
                        break;
                    }
                }
                else
                {
                    Node* brother = delParentPos->_left;
                    
                    if( brother->_col == RED )
                    {
                        delParentPos->_col == RED;
                        brother->_col = BLACK;
                        RotateR(delParentPos);
                        brother = delParentPos->_left;
                    }

                    if (((brother->_left == nullptr) || (brother->_left->_col == BLACK))
						&& ((brother->_right == nullptr) || (brother->_right->_col == BLACK)))
                    {
                        brother->_col = RED;
                        if (delParentPos->_col == RED)
                        {
                            delParentPos->_col == BLACK;
                            break;
                        }
                        delPos = delParentPos;
                        delParentPos = delPos->_parent;
                    }
                    else
                    {
                        if ((brother->_left == nullptr) || (brother->_left->_col == BLACK))
                        {
                            brother->_right->_col = BLACK;
                            brother->_col = RED;
                            RotateL(brother);
                            brother = delParentPos->_left;
                        }
                        brother->_col = delParentPos->_col;
                        delParentPos->_col = BLACK;
                        brother->_left->_col = BLACK;
                        RotateR(delParentPos);
                        break;
                    }
                }
            }
        }
    }

    if (del->_left == nullptr)
    {
        if (del == delP->_left)
        {
            delP->_left = del->_right;
            if(del->_right)
            {
                del->_right->_parent = delP;
            }
        }
        else
        {
            delP->_right = del->_right;
            if (del->_right)
                del->_right->_parent = delP;
        }
    }
    else
    {
        if (del == delP->_left)
        {
            delP->_left = del->_left;
            if (del->_left)
                del->_left->_parent = delP;
        }
        else
        {
            delP->_right = del->_left;
            if (del->_left)
                del->_left->_parent = delP;
        }
    }
    delete del;
    return true;
}



