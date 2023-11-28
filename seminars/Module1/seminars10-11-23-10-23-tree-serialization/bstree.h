#ifndef BSTREE_H
#define BSTREE_H

struct Node
{
	int key;
	Node* left;
	Node* right;
	Node() : left(nullptr), right(nullptr) {}
	Node(int x) : key(x), left(nullptr), right(nullptr){}
};

struct BSTree
{
	BSTree() : root(nullptr){}
	~BSTree();
	void insert(int key);
	void eraseAll(Node* curNode);
	Node* root;
};

void BSTree::insert(int key)
{
	Node* cur = root;

	Node* newNode = new Node(key);
	Node* parent = nullptr;

	while(cur != nullptr)
	{	
		parent = cur;
		cur = key < cur->key ? cur->left : cur->right;
	}

	if(!parent)
		root = newNode;
	else if(key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
}

BSTree::~BSTree()
{
	eraseAll(root);
}

void BSTree::eraseAll(Node* curNode)
{
	if(!curNode)
		return;

	eraseAll(curNode->left);
	eraseAll(curNode->right);
	delete curNode;
}

#endif