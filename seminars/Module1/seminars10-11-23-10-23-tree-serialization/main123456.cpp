#include <iostream>
#include "bstree.h"
#include "solution.h"

// Check if two trees, with roots r1 and r2 respectively, are equal
bool cmp(Node* r1, Node* r2)
{
	if(!r1 && !r2)
		return true;

	if((!r1 && r2) || (r1 && !r2) || r1->key != r2->key)
		return false;

	return cmp(r1->left,r2->left) && cmp(r1->right,r2->right);
}

void test(std::initializer_list<int> keys, int testNumber)
{
	BSTree t1;
	for(int x : keys)
		t1.insert(x);

	std::string s = serialize(t1.root);

	BSTree t2;
	t2.root = deserialize(s);

	std::cout << "Test #" << testNumber << ": " << (cmp(t1.root,t2.root) ? "OK" : "WA") << std::endl;
}

int main()
{
	test({5,3,6,1,4,7}, 1);
	test({25,20,36,10,22,30,40,5,12,28,38,48,1,8,15,45,50}, 2);
	return 0;
}
