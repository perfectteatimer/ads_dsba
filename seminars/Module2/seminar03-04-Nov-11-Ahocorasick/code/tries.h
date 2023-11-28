#ifndef TRIES_H
#define TRIES_H

#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <string>

class Trie
{
public:
	class Node
	{
		public:
			Node() : endOfWord(false)
			{
				for(int i = 0; i < 26; i++)
					children[i] = nullptr;
			}
			Node*   children[26];
			bool 	endOfWord;

			bool hasChildren()
			{
				bool flag = false;

				for(int i = 0; i < 26; i++)
				{
					if(children[i] != nullptr)
					{
						flag = true;
						break;
					}
				}

				return flag;
			}
	};
	
	Trie() : _root(new Node()){}

	~Trie()
	{
		destruct(_root);
	}

	void destruct(Node* currentNode)
	{
		if(currentNode)
		{
			for(int i = 0; i < 26; i++)
				destruct(currentNode->children[i]);
			delete currentNode;
		}
	}

	Node* insert(std::string key)
	{
		Node* it = _root;

		for(int i = 0; i < key.size(); i++)
		{
			int index = key[i] - 97;
			if(it->children[index] == nullptr)
				it->children[index] = new Node();
			it = it->children[index];
		}

		it->endOfWord = true;
		return it;
	}

protected:
	Node* _root;
};

#endif
