#include <iostream>
#include "bstree.h"

// Task 1. Given a tree, return the pointer to the node that has a given key "target". If such node does not exist, return nullptr
Node* search(BSTree& tree, int target)
{
    Node* curParent = tree.root;
    Node* targetNode = nullptr;

    while(curParent != nullptr)
    {
        if (target == curParent->key)
        {
            targetNode = curParent;
            break;
        }

        else if (target < curParent->key)
            curParent = curParent->left;
        else
            curParent = curParent->right;
    }
    return targetNode;
}

// Task 2. Given a tree, calculate its height (number of "levels")
int height(BSTree& tree)
{

}

// Task 3. Given a tree, calculate the sum of the leaves (leaves = nodes without children)
int sumLeaves(BSTree& tree)
{

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

	if(search(tree, 8) != nullptr)
		std::cout << "8 was found in the tree!" << std::endl;

	if(search(tree, 9) == nullptr)
		std::cout << "9 was not found in the tree!" << std::endl;

	std::cout << height(tree) << std::endl; // must print 3

	std::cout << sumLeaves(tree) << std::endl; // must print 19

	return 0;
}