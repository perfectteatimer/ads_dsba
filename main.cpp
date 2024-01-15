#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>

class HuffmanNode {
public:
    char letter; // '\0' for non-leaf nodes
    int freq;
    HuffmanNode* leftChild;
    HuffmanNode* rightChild;

    HuffmanNode(char letter, int freq, HuffmanNode* leftChild = nullptr, HuffmanNode* rightChild = nullptr)
            : letter(letter), freq(freq), leftChild(leftChild), rightChild(rightChild) {}

    // Compare for priority queue
    bool operator>(const HuffmanNode& node) const {
        return this->freq > node.freq;
    }
};

void traverse(HuffmanNode* hfNode, std::unordered_map<char, std::string>& m, std::string code) {
    if (hfNode == nullptr) return;

    if (hfNode->letter != '\0') {
        m[hfNode->letter] = code;
    }

    traverse(hfNode->leftChild, m, code + "0");
    traverse(hfNode->rightChild, m, code + "1");
}

std::unordered_map<char, std::string> huffman(std::multiset<HuffmanNode>& s) {
    std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, std::greater<HuffmanNode>> pq;
    for (const auto& node : s) {
        pq.push(node);
    }

    while (pq.size() > 1) {
        HuffmanNode* left = new HuffmanNode(pq.top());
        pq.pop();
        HuffmanNode* right = new HuffmanNode(pq.top());
        pq.pop();

        HuffmanNode* combined = new HuffmanNode('\0', left->freq + right->freq, left, right);
        pq.push(*combined);
    }

    std::unordered_map<char, std::string> m;
    traverse(&pq.top(), m, "");
    return m;
}

int main() {
    std::multiset<HuffmanNode> s = { {'D',1}, {'C',1}, {'R',2}, {'B',2}, {'A',5} };
    std::unordered_map<char, std::string> huffmanTable = huffman(s);

    for (auto& [sym, code] : huffmanTable) {
        std::cout << sym << "===>" << code << std::endl;
    }

    std::string text = "ABRACADABRA";
    std::string encodedText;
    for (char c : text) {
        encodedText += huffmanTable[c];
    }

    std::cout << "Encoded: " << encodedText << std::endl;

    return 0;
}
