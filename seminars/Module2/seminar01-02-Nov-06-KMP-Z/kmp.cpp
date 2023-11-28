#include <iostream>
#include <vector>
#include <string>

std::vector<int> calcLPS(std::string& pattern)
{
	std::vector<int> lps(pattern.size(), 0);

	for(int len = 0, i = 1; i < pattern.size();  )
	{
		if(pattern[len] == pattern[i])
			lps[i++] = ++len;
		else
		{
			if(len == 0)
				lps[i++] = 0;
			else
				len = lps[len - 1];
		}
	}

	return lps;
}

void strstr(std::string& text, std::string& pattern)
{
	std::vector<int> lps = calcLPS(pattern);

	// i - index for text, j - index for pattern
	for(int j = 0, i = 0; i < text.size() ; )
	{
		if(text[i] == pattern[j])
			i++, j++;

		if(j == pattern.size()){
			std::cout << i - j << std::endl;
			j = lps[j - 1];
		}
		else if(i < text.size() && pattern[j] != text[i])
		{
			if(j != 0) 
				j = lps[j - 1];
			else
				i++;
		}
	}
}

int main()
{
	std::string text = "I don’t much care where said Alice, Then it doesn’t matter which way you go said the Cat";
	
	std::string pattern = "Alice";

	strstr(text, pattern);

	return 0;
}