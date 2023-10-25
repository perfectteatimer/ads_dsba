// код с семинара с хулио + интернет + все что можно загуглить
#include <iostream>
#include <string>

class AVLTree
{
public:
    class Node
    {
    public:
        int key;
        int height;
        Node* left;
        Node* right;

        Node(int k) : key(k), height(1), left(nullptr), right(nullptr)
        {}
    };

private:
    Node* root;

    Node* rotateRight(Node* y)
    {
        Node* x = y->left;        // x  левый потомок y
        Node* T2 = x->right;      // T2  правый потомок x

        // поворот
        x->right = y;            // y становится правым потомком x
        y->left = T2;            // T2 становится левым потомком y

        // новые значения долбанных высоты
        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        // развернули и вернули
        return x;
    }

    Node* rotateLeft(Node* x)
    {
        Node* y = x->right;       // y  правый потомок x
        Node* T2 = y->left;       // T2  левый потомок y

        // опять но уже влево поворот
        y->left = x;             // x становится левым потомком y
        x->right = T2;           // T2 становится правым потомком x

        // новые значения высот
        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        // развернули и вернули
        return y;
    }


    int height(Node* N)
    {
        if (N == nullptr)
            return 0;
        return N->height;
    }

    Node* insert(Node* node, int key)
    {

        if (node == nullptr)
            return (new Node(key));

        // если ключ меньше чем ключ узла то он будет вставлен в левое поддерево
        if (key < node->key)
            node->left = insert(node->left, key);
            // eсли ключ больше чем ключ узла то он будет вставлен в правое поддерево
        else if (key > node->key)
            node->right = insert(node->right, key);
            // eсли ключи равны  возвращаем текущий узел
        else
            return node;

        // обновление высоты текущего предка узла
        node->height = 1 + std::max(height(node->left), height(node->right));

        // проверка на сбалансироваослвстэялчлсДЭЖЛ
        int balance = getBalance(node);

        // если несбаласнвавршыэ то есть 4 случая

        //  left left rot
        if (balance > 1 && key < node->left->key)
            return rotateRight(node);

        // right right rot
        if (balance < -1 && key > node->right->key)
            return rotateLeft(node);

        // left right rot
        if (balance > 1 && key > node->left->key)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // right left rot
        if (balance < -1 && key < node->right->key)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }


    Node* minValueNode(Node* node)
    {
        Node* current = node;

        // найдем самый левый лист который является узлом с минимальным значением
        while (current->left != nullptr)
            current = current->left;

        return current;
    }


    Node* deleteNode(Node* root, int key)
    {
        if (root == nullptr)
            return root;

        //  спускаемся в дерево и ищем узел который нужно удалить
        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else
        {
            // eсли ключ равен ключу корневого узла то это узел  который нужно удалить
            if ((root->left == nullptr) || (root->right == nullptr))
            {
                Node* temp;
                if (root->left != nullptr)
                    temp = root->left;
                 else
                    temp = root->right;

                // у узла только один дочерний элемент или вообще нет
                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else // у узла два дочерних элемента
                    *root = *temp; // копирование содержимого не пустого дочернего узла
                delete temp;
            }
            else
            {
                // у узла два дочерних элемента получение самого маленького в  правом поддереве то есть наследника (succession сериал top)
                Node* temp = minValueNode(root->right);

                // копирование данных порядкового преемника в этот узел
                root->key = temp->key;

                // удаление порядкового преемника
                root->right = deleteNode(root->right, temp->key);
            }
        }

        // eсли дерево имело только один узел возвращаем его
        if (root == nullptr)
            return root;

        //  обновление высоты текущего предка узла
        root->height = 1 + std::max(height(root->left), height(root->right));

        //  проверка баланса этого предка узла после удаления
        int balance = getBalance(root);

        // если небаланс то есть 4 случая

        // left left rot
        if (balance > 1 && getBalance(root->left) >= 0)
            return rotateRight(root);

        // lef rigth rot
        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // right right rot
        if (balance < -1 && getBalance(root->right) <= 0)
            return rotateLeft(root);

        // right left
        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }


    int getBalance(Node* N)
    {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }

    bool exists(Node* root, int key)
    {
        if (root == nullptr)
            return false;

        if (key < root->key)
            return exists(root->left, key);

        else if (key > root->key)
            return exists(root->right, key);

        else
            return true;
    }

public:
    AVLTree() : root(nullptr)
    {}

    void insert(int key)
    {
        root = insert(root, key);
    }

    void deleteNode(int key)
    {
        root = deleteNode(root, key);
    }

    bool exists(int key)
    {
        return exists(root, key);
    }
};

int main()
{
    AVLTree tree;
    std::string op;
    int value;

    while (std::cin >> op)
    {
        if (op == "insert" || op == "delete" || op == "exists")
            std::cin >> value;
        if (op == "insert")
            tree.insert(value);
        else if (op == "delete")
            tree.deleteNode(value);
        else if (op == "exists")
        {
            if (tree.exists(value))
                std::cout << "true" << '\n';
            else
                std::cout << "false" << '\n';
        }
    }
}

