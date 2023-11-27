#include <iostream>
#include "bstree.h"
#include <queue>
#include <stack>

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
// Task 2[v2]. Given a tree, calculate its height (number of "levels") [using Level-order]
int height(BSTree& tree)
{
    Node* currParent = tree.root;
    int maxHeight = 0;

    std::queue<Node*> nodesToVisit;
    nodesToVisit.push(currParent);
    nodesToVisit.push(nullptr);

    while (!nodesToVisit.empty())
    {
        currParent = nodesToVisit.front();
        nodesToVisit.pop();

        if (!currParent)
            maxHeight++;

        if (currParent)
        {
            if (currParent->left)
                nodesToVisit.push(currParent->left);
            if (currParent->right)
                nodesToVisit.push(currParent->right);
        }
        else if (!nodesToVisit.empty())
            nodesToVisit.push(nullptr);
    }
    return maxHeight;
}
// Task 3. Given a tree, calculate the sum of the leaves (leaves = nodes without children)
int sumLeaves(BSTree& tree)
{
    Node* currParent = tree.root;
    if (!currParent)
        return 0;

    int sumLeaves = 0;
    std::stack<Node*> nodesToVisit;
    nodesToVisit.push(currParent);
    while(!nodesToVisit.empty())
    {
        currParent = nodesToVisit.top();
        nodesToVisit.pop();

        if (currParent->left)
            nodesToVisit.push(currParent->left);
        if (currParent->right)
            nodesToVisit.push(currParent->right);

        if (!currParent->left and !currParent->right)
            sumLeaves += currParent->key;
    }
    return sumLeaves;
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