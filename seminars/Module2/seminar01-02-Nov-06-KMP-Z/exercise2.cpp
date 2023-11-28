// Exercise #2: Create a class "ZFinder" with a constructor that receives the pattern to search in a text
// An integer function "find" in class "ZFinder" must return the index of the next occurrence of the pattern in the text.
// A function "freq" that returns the number of occurrences of the pattern in the text.
// The ZFinder must implement the Z-Algorithm

#include <vector>
#include <iostream>
#include <string>

class ZFinder
{
public:

	ZFinder(std::string text, std::string pattern)
	{
		// What we could do here?
	}

	// Complete...

private:

	int _cur; // position of the next occurrence
};	

int main()
{
	std::string text = "If a dog chews shoes, whose shoes does he choose?";

	std::string pattern = "oes";

	ZFinder zFinder(text,pattern);

	std::cout << "Number of occurrences: " << zFinder.freq() << std::endl;

	int pos = zFinder.find();

	while(pos != -1)
	{
		std::cout << pos << std::endl; // 17 30 35
		pos = zFinder.find();
	}

	return 0; 
}