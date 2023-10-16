#include <iostream>
#include <vector>
#include <climits>

struct Node
{
    int key;
    Node* left;
    Node* right;

    Node()
    {}

    Node(int x) : key(x), left(nullptr), right(nullptr)
    {}
};

struct BSTree
{
    BSTree() : root(nullptr)
    {}

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

    while (cur != nullptr)
    {
        parent = cur;
        cur = key < cur->key ? cur->left : cur->right;
    }

    if (!parent)
    {
        root = newNode;
    }
    else if (key < parent->key)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
}

BSTree::~BSTree()
{
    eraseAll(root);
}

void BSTree::eraseAll(Node* curNode)
{
    if (!curNode)
    {
        return;
    }

    eraseAll(curNode->left);
    eraseAll(curNode->right);
    delete curNode;
}


bool valid(Node* root, long long lower_bound = LLONG_MIN, long long upper_bound = LLONG_MAX)
{
    if (!root)
    {
        return true;
    }

    if (root->key <= lower_bound || root->key >= upper_bound)
    {
        return false;
    }

    return valid(root->left, lower_bound, root->key) && valid(root->right, root->key, upper_bound);
}

bool isValidBST(Node* root)
{
    return valid(root);
}

int main()
{
    BSTree t1;
    std::vector<int> keys1 = {2, 1, 4, 3, 6};
    for (int x: keys1)
    {
        t1.insert(x);
    }
    t1.root->key = 5;

    bool test1 = isValidBST(t1.root); // must be false (comment previous change of key to 5 to check for true)
    std::cout << test1 << ' ';

    BSTree t2;
    std::vector<int> keys2 = {5, 4, 8, 3, 7, 10};
    for (int x: keys2)
    {
        t2.insert(x);
    }
    t2.root->right->left->key = 2;

    bool test2 = isValidBST(t2.root); // must be false (comment previous insert of key to 2 to check for true)
    std::cout << test2;

    return 0;
}
