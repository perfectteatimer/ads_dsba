#include <iostream>
#include <vector>

struct Node
{
    int key;
    int left;
    int right;
};

bool isBST(const std::vector<Node>& tree, int nodeIndex, long long min, long long max)
{
    if (nodeIndex == -1) // если дерево без детей значит норм
        return true;

    if (tree[nodeIndex].key < min || tree[nodeIndex].key >= max) // Все ключи в правом поддереве данной вершины больше либо равны ключу самой вершины.
        return false;

    // тут подаю в рекурсию левое поддерево(шде все мин) и правое поддерево(где все макс) и если хотя бы одно не норм то уже плохо
    return isBST(tree, tree[nodeIndex].left, min, tree[nodeIndex].key) &&
           isBST(tree, tree[nodeIndex].right, tree[nodeIndex].key, max);
}


int main()
{
    int n;
    std::cin >> n;
    std::vector<Node> tree(n);
    for (int i = 0; i < n; ++i)
        std::cin >> tree[i].key >> tree[i].left >> tree[i].right;

    if (isBST(tree, 0, -2147483648, 2147483648))
        std::cout << "CORRECT";
    else
        std::cout << "INCORRECT";
}