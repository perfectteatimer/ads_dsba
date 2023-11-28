#include "ahocorasick.h"

int main()
{
	std::vector<std::string> patterns = { "i", "in", "tin", "sting" };

	AhoCorasickTrie myTrie(patterns);

	myTrie.find("sting");

	return 0;
}