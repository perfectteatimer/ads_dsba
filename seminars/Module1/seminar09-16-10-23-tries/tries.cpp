#include <vector>
#include <string>
#include <iostream>

class Trie
{
public:
	class Node
	{
	public:
		Node* children[26];
		bool endOfWord;
		Node()
		{
			endOfWord = false;
			for (int i = 0; i < 26; i++)
				children[i] = nullptr;
		}
	};

	Trie(): _root(new Node()){}

	// Task #1: Complete the class by coding the "Destructor" where you need to delete all the nodes (similar to BST, AVL,...)
	// ~Trie(){}

	// Task #2: Retrieve (check in the slides)
	
	void insert(std::string key) // key = "anna"
	{
		Node* nodePtr = _root;

		for (int i = 0; i < key.size(); i++)
		{
			int index = key[i] - 'a'; // 'n' - 'a' = index
			if (nodePtr->children[index] == nullptr)
				nodePtr->children[index] = new Node();

			// move the iterator
			nodePtr = nodePtr->children[index];
		}
		nodePtr->endOfWord = true;		
	}

	// returns true if the key exists in the trie
	// otherwise, it returns false.
	bool search(std::string key)
	{
		Node* nodePtr = _root;

		for (char letter : key)
		{
			// if a given letter of the key does not exist in the trie, return false
			if (nodePtr->children[letter - 'a'] == nullptr)
				return false;

			nodePtr = nodePtr->children[letter - 'a'];
		}

		// check that where we stopped it's actually an end of a word
		return nodePtr->endOfWord;
	}

private:
	Node* _root;
};

int main()
{
	Trie trie;

	std::vector<std::string> data = {"any", "ant", "anna", "anger", "angelina", "angie", "angry", "angel"};

	for (std::string& key : data)
		trie.insert(key);

	for (std::string& key : data)
		if(trie.search(key))
			std::cout << key << " is on the trie!" << std::endl;

	return 0;
}