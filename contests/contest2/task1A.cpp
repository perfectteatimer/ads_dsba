#include <iostream>
#include <vector>

struct Node
{
    int key;
    int leftIndex;
    int rightIndex;
};

void inOrder(const std::vector<Node>& tree, int currentIndex)
{
    if (currentIndex == -1)
        return;
    inOrder(tree, tree[currentIndex].leftIndex);
    std::cout << tree[currentIndex].key << " ";
    inOrder(tree, tree[currentIndex].rightIndex);
}

void preOrder(const std::vector<Node>& tree, int currentIndex)
{
    if (currentIndex == -1)
        return;
    std::cout << tree[currentIndex].key << " ";
    preOrder(tree, tree[currentIndex].leftIndex);
    preOrder(tree, tree[currentIndex].rightIndex);
}

void postOrder(const std::vector<Node>& tree, int currentIndex)
{
    if (currentIndex == -1)
        return;
    postOrder(tree, tree[currentIndex].leftIndex);
    postOrder(tree, tree[currentIndex].rightIndex);
    std::cout << tree[currentIndex].key << " ";
}


int main()
{
    int sizeOfVec;
    std::cin >> sizeOfVec;
    std::vector<Node> vec(sizeOfVec);
    for (size_t i = 0; i < sizeOfVec; ++i)
        std::cin >> vec[i].key >> vec[i].leftIndex >> vec[i].rightIndex;
    inOrder(vec, 0);
    std::cout << '\n';
    preOrder(vec, 0);
    std::cout << '\n';
    postOrder(vec, 0);
}