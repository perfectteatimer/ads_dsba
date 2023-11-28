#include <iostream>
#include "bstree.h"

// Given the root of a binary tree, determine if the tree is a Binary Search Tree
// Hints:
// - Is every node value in the root’s left subtree less than the root’s value?
// - Is every node value in the root’s right subtree greater than the root’s value?
// - Is the root’s left subtree also a binary search tree?
// - Is the root’s right subtree also of a binary search tree?


bool isValidBST(Node* root)
{
	//.....
}

int main()
{
	BSTree t1;
	std::vector<int> keys1 = {2,1,4,3,6};
	for(int x : keys1)
		t1.insert(x);
	t1.root->key = 5;

	bool test1 = isValidBST(t1.root); // must be false (comment previous change of key to 5 to check for true)

	BSTree t2;
	std::vector<int> keys2 = {5,4,8,3,7,10};
	for(int x : keys2)
		t2.insert(x);
	t2.root->right->left->key = 2;

	bool test2 = isValidBST(t2.root); // must be false (comment previous insert of key to 2 to check for true)

	return 0;
}