#include <vector>
#include <queue>
#include <stack>
#include <iostream>

class AVLTree
{
	public:

		class Node
		{
			public:
				Node(){}
				Node(int key) : key(key), height(1), right(nullptr), left(nullptr){}
				int   	key;
				int 	height;
				Node* 	right;
				Node* 	left;

		};
		
		AVLTree() : _root(nullptr)
		{}

		~AVLTree()
		{
			destruct(_root);
		}

		void destruct(Node* currentNode)
		{
			if(currentNode)
			{
				destruct(currentNode->left);
				destruct(currentNode->right);
				delete currentNode;
			}
		}

		Node* getRoot()
		{
			return _root;
		}

		void insert(int key)
		{
			_root = insert(_root, key);
		}

		// insert a key in the subtree rooted with "node"
		// returns the new root of the subtree
		Node* insert(Node* node, int key)
		{
			// Step 1. Perform the insertion like in simple Binary Search Trees.
			if(node == nullptr)
			{
				return new Node(key);
			}

			if(key < node->key)
			{
				node->left = insert(node->left, key);
			}
			else if(key > node->key)
			{
				node->right = insert(node->right, key);
			}
			else
			{
				return node;
			}

			// Step 2. Update height of this ancestor
			node->height = 1 + maxHeight(node->left,node->right);

			// Step 3. Check the balance factor of this ancestor
			int bf = getBalanceFactor(node);

			// Step 4. If the subtree is unbalanced, check in which case we are, and balance!

			// Case 1. LEFT LEFT CASE
			if(bf > 1 && key < node->left->key)
			{
				//....
				
				return rightRotate(node);
			}

			// Case 2. LEFT RIGHT CASE
			if(bf > 1 && key > node->left->key)
			{
				//....

				node->left = leftRotate(node->left);
				return rightRotate(node);
			}

			// Case 3. RIGHT RIGHT CASE
			if(bf < -1 && key > node->right->key)
			{
				//....
				
				return leftRotate(node);
			}

			// Case 4. RIGHT LEFT CASE
			if(bf < -1 && key < node->right->key)
			{
				//....
				
				node->right = rightRotate(node->right);
				return leftRotate(node);
			}

			return node; // case when the node did not change
		}

	private:

		int maxHeight(Node* left, Node* right)
		{
			int l = left == nullptr ? 0 : left->height;
			int r = right == nullptr ? 0 : right->height;

			return l > r ? l : r;
		}

		int getBalanceFactor(Node* node)
		{
			if(node == nullptr)
				return 0;

			int l = node->left == nullptr ? 0 : node->left->height;
			int r = node->right == nullptr ? 0 : node->right->height;

			return l - r;
		}

		Node* rightRotate(Node* y)
		{		
			//return x;
		}

		Node* leftRotate(Node* x)
		{
			//return y;
		}

		Node* _root;
};

// Level Order: Prints the tree floor-by-floor

void levelorder(AVLTree& myTree)
{
	AVLTree::Node* root = myTree.getRoot();

	if(!root)
		return;

	std::queue<AVLTree::Node*> queue;

	queue.push(root);

	while(!queue.empty())
	{
		AVLTree::Node* node = queue.front();
		std::cout << node->key << " ";
		queue.pop();

        if (node->left)
            queue.push(node->left);
 
        if (node->right)
            queue.push(node->right);
	}

	std::cout<<std::endl;
}

int main()
{
	AVLTree avlTree;

	std::vector<int> data = {90, 80, 70, 60, 50, 75};

	for(int i = 0; i < data.size(); i++)
	{

	}

	return 0;
}