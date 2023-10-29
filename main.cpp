#include <iostream>
#include <map>

struct TNode {
    int x; // значение
    int y; // приоритет (random number)
    int sz; // размер поддерева
    TNode *left, *right;
    TNode(int val) : x(val), y(rand()), sz(1), left(nullptr), right(nullptr) {}
};

int safe_size(TNode* node) {
    return node ? node->sz : 0;
}

TNode* new_node(int x) {
    return new TNode(x);
}

void relax(TNode* root) {
    if (!root) return;
    root->sz = safe_size(root->left) + safe_size(root->right) + 1;
}

TNode* merge(TNode* left, TNode* right) {
    if (!left) return right;
    if (!right) return left;
    if (left->y < right->y) {
        left->right = merge(left->right, right);
        relax(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        relax(right);
        return right;
    }
}

std::pair<TNode*, TNode*> split(TNode* root, int sz) {
    if (!root || !sz) return {nullptr, root};
    int lsz = safe_size(root->left);
    if (lsz >= sz) {
        auto t = split(root->left, sz);
        root->left = t.second;
        relax(root);
        return {t.first, root};
    } else {
        auto t = split(root->right, sz - lsz - 1);
        root->right = t.first;
        relax(root);
        return {root, t.second};
    }
}

TNode* insert(TNode* root, int x, int sz) {
    auto t = split(root, sz);
    return merge(t.first, merge(new_node(x), t.second));
}

int main() {
    TNode* root = nullptr;
    // Здесь можно добавить код для вставки, удаления, поиска элементов в дереве и т.д.

    // Пример вставки элементов
    root = insert(root, 5, 1);
    root = insert(root, 2, 1);
    root = insert(root, 9, 3);

    // Пример извлечения поддерева
    auto t = split(root, 1);
    auto tt = split(t.second, 2);

    TNode* extractedSubtree = tt.first;
    root = merge(tt.first, merge(t.first, tt.second));

    // Здесь можно добавить код для работы с extractedSubtree и root
    return 0;
}
