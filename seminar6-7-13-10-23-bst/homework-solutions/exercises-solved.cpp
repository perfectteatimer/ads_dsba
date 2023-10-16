
#include "bstree.h"

#include <iostream>
#include <algorithm>

// Task 1. Given a tree, return the pointer to the node that has a given key "target". If such node does not exist, return nullptr
Node* search(BSTree& tree, int target)
{
	Node* cur = tree.root;

	while (cur)
	{
		if (cur->key == target)
			return cur;

		cur = target < cur->key ? cur->left : cur->right;
	}

	return nullptr;
}

// Task 2. Given a tree, calculate its height (number of "levels")
int height(Node* cur)
{
	return cur ? 1 + std::max(height(cur->left),height(cur->right)) : 0;
}

int height(BSTree& tree)
{
	return height(tree.root);
}

void lookUp(Node* cur, int& sum)
{
	if (!cur)
		return;

	if (!cur->left && !cur->right)
	{
		sum += cur->key;
	}
	else
	{
		lookUp(cur->left, sum);
		lookUp(cur->right, sum);
	}
}

// Task 3. Given a tree, calculate the sum of the leaves (leaves = nodes without children)
int sumLeaves(BSTree& tree)
{
	int sum = 0;
	lookUp(tree.root, sum);
	return sum;
}


int main()
{
	BSTree tree;
	tree.insert(5);
	tree.insert(3);
	tree.insert(7);
	tree.insert(1);
	tree.insert(4);
	tree.insert(6);
	tree.insert(8);

	if (search(tree, 8) != nullptr)
		std::cout << "8 was found in the tree!" << std::endl;

	if (search(tree, 9) == nullptr)
		std::cout << "9 was not found in the tree!" << std::endl;

	std::cout << height(tree) << std::endl; // must print 3

	std::cout << sumLeaves(tree) << std::endl; // must print 19

	return 0;
}