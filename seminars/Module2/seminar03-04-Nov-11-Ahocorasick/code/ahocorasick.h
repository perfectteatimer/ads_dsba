
#ifndef AHOCORASICK_H
#define AHOCORASICK_H

#include "tries.h"
#include <map>
#include <queue>

class AhoCorasickTrie : public Trie
{
public:

	AhoCorasickTrie(std::vector<std::string> patterns)
	{
		for(int i = 0; i < patterns.size(); i++)
		{
			Node* endNode = this->insert(patterns[i]);
			this->patterns[endNode] = patterns[i];
		}

		buildSuffixLinks();
	}

	// given a text, print in the terminal all occurrences of patterns (stored in the trie)
	void find(std::string text)
	{

	}
private:

	void buildSuffixLinks()
	{

	}

	std::map<Node*,std::string> patterns;

	std::map<Node*,Node*> suffixLink; // from a node w, suffixLink[w] is a pointer to a node x

	std::map<Node*,Node*> outputLink; // output links can be built when building suffix links
};

#endif
