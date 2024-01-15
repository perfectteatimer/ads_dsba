#include <iostream>
#include <unordered_map>
#include <set>

class HuffmanNode
{
public:

    char letter; // '\0' for non-leaf nodes
    int freq;

    HuffmanNode* leftChild;
    HuffmanNode* rightChild;

    HuffmanNode(char letter, int freq, HuffmanNode* leftChild = nullptr, HuffmanNode* rightChild = nullptr)
            : letter(letter), freq(freq), leftChild(leftChild), rightChild(rightChild)
    {}

    HuffmanNode(const HuffmanNode& node)
            : letter(node.letter), freq(node.freq), leftChild(node.leftChild), rightChild(node.rightChild)
    {}

    bool operator<(const HuffmanNode& node) const
    {
        return this->freq <= node.freq;
    }
};

void traverse(HuffmanNode* hfNode, std::unordered_map<char, std::string>& m, std::string code)
{
    if (!hfNode)
    {
        return;
    }

    // Check if it is a leaf node
    if (hfNode->letter != '\0')
    {
        m[hfNode->letter] = code;
    }

    // Traverse left
    traverse(hfNode->leftChild, m, code + "0");
    // Traverse right
    traverse(hfNode->rightChild, m, code + "1");
}


std::unordered_map<char, std::string> huffman(std::multiset<HuffmanNode>& s)
{
    std::unordered_map<char, std::string> m; // Map for the codes

    // Building the Huffman Tree
    while (s.size() > 1)
    {
        auto first = *s.begin();
        s.erase(s.begin());

        auto second = *s.begin();
        s.erase(s.begin());

        auto* left = new HuffmanNode(first);
        auto* right = new HuffmanNode(second);
        auto* parent = new HuffmanNode('\0', first.freq + second.freq, left, right);

        s.insert(*parent);
    }
    if (!s.empty())
    {
        HuffmanNode* root = const_cast<HuffmanNode*>(&(*s.begin()));
        traverse(root, m, "");
    }
    return m;
}

int main()
{
    // Assume we already found distinct symbols for the string ABRACADABRA and their frequency
    std::multiset<HuffmanNode> s = {{'D', 1},
                                    {'C', 1},
                                    {'R', 2},
                                    {'B', 2},
                                    {'A', 5}};

    // Task 1. Return the Huffman encoding for ABRACADABRA
    std::unordered_map<char, std::string> huffmanTable = huffman(s);

    for (auto& [sym, code]: huffmanTable)
    {
        std::cout << sym << "===>" << code << std::endl;
    }

    // Task 2. Print the whole Huffman code for the string ABRACADABRA using the huffman table
    std::string text = "ABRACADABRA";

    return 0;
}