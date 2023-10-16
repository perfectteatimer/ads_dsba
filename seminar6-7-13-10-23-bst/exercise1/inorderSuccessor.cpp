#include <iostream>
#include <vector>



struct Node
{
    int key;
    Node* left;
    Node* right;
    Node(){}
    Node(int x) : key(x), left(nullptr), right(nullptr){}
};

struct BSTree
{
    BSTree() : root(nullptr){}
    ~BSTree();
    void insert(int key);
    void eraseAll(Node* curNode); // erase all tree starting from a curNode
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

    if (!parent)
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

/* In a BST, the inorder successor of a node X is the next node that would be visited after X,
if we were performing an inorder traversal of the BST */

// Given node x of a BST (and the root of the tree), find the inorder successor of x. If it does not exist, return nullptr
Node* inorderSuccessor(Node* x, Node* root)
{
    // Case 1: If the right subtree is not null
    if (x->right != nullptr)
    {
        x = x->right;
        while (x->left != nullptr)
        {
            x = x->left;
        }
        return x;
    }

    // Case 2: If the right subtree is null
    Node* successor = nullptr;
    while (root != nullptr)
    {
        if (x->key < root->key)
        {
            successor = root;
            root = root->left;
        }
        else if (x->key > root->key)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }
    return successor;
}


int main()
{
	BSTree t;
	std::vector<int> keys = {20,8,22,4,12,10,14};
	for(int x : keys)
		t.insert(x);

	Node* node1 = t.root->left;
	Node* test1 = inorderSuccessor(node1,t.root);
	std::cout << test1->key << std::endl; // must print 10 (inorder successor of 8 is 10)

	Node* node2 = t.root->left->right->left;
	Node* test2 = inorderSuccessor(node2,t.root);
	std::cout << test2->key << std::endl; // must print 12 (inorder successor of 10 is 12)

	Node* node3 = t.root->left->right->right;
	Node* test3 = inorderSuccessor(node3,t.root);
	std::cout << test3->key << std::endl; // must print 20 (inorder successor of 14 is 20)

	Node* node4 = t.root->right;
	Node* test4 = inorderSuccessor(node4,t.root);
	if(!test4)
		std::cout << "inorder successor of 22 does not exist in the tree" << std::endl;

	return 0;
}