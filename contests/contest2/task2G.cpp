#include <iostream>
#include <vector>
#include <string>


struct TNode
{
    int x, y, sz;
    TNode* left, * right;

    TNode(int val) : x(val), y(rand()), sz(1), left(nullptr), right(nullptr) // констркутор для значений дерева
    {}
};

int safe_size(TNode* node) // возвращает размер поддерева
{
    if (node != nullptr)
        return node->sz;
    else
        return 0;
}


void relax(TNode* root)
{
    if (!root) return;
    root->sz = safe_size(root->left) + safe_size(root->right) + 1;
}

TNode* merge(TNode* left, TNode* right)
{
    if (!left) return right;
    if (!right) return left;
    if (left->y < right->y)
    {
        left->right = merge(left->right, right);
        relax(left);
        return left;
    }
    else
    {
        right->left = merge(left, right->left);
        relax(right);
        return right;
    }
}

std::pair<TNode*, TNode*> split(TNode* root, int sz)
{
    if (!root) return {nullptr, nullptr};
    int lsz = safe_size(root->left);
    if (lsz >= sz)
    {
        auto t = split(root->left, sz);
        root->left = t.second;
        relax(root);
        return {t.first, root};
    }
    else
    {
        auto t = split(root->right, sz - lsz - 1);
        root->right = t.first;
        relax(root);
        return {root, t.second};
    }
}

TNode* insert(TNode* root, int x, int pos)
{
    auto t = split(root, pos);
    return merge(merge(t.first, new TNode(x)), t.second);
}

TNode* remove(TNode* root, int pos)
{
    auto t1 = split(root, pos - 1);
    auto t2 = split(t1.second, 1);
    delete t2.first;
    return merge(t1.first, t2.second);
}

void print(TNode* root)
{
    if (!root) return;
    print(root->left);
    std::cout << root->x << ' ';
    print(root->right);
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    TNode* root = nullptr;
    for (int i = 0, x; i < n; ++i)
    {
        std::cin >> x;
        root = insert(root, x, i);
    }
    for (int i = 0; i < m; ++i)
    {
        std::string op;
        int pos;
        std::cin >> op >> pos;
        if (op == "add")
        {
            int x;
            std::cin >> x;
            root = insert(root, x, pos);
        }
        else if (op == "del")
            root = remove(root, pos);
    }
    std::cout << safe_size(root) << '\n';
    print(root);

}
