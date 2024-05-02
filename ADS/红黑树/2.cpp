#include <utility>

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





