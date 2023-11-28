#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

#define NUM_SYM 256

// Pre-processing function for bad character
std::vector<int> calcBadChar(std::string& pattern) 
{ 
    std::vector<int> badChar(NUM_SYM, -1);

    // each character is associated with its last occurrence in the pattern
    for (int i = 0; i < pattern.size(); i++)
        badChar[(int) pattern[i]] = i;

    return badChar;
}

void boyerMoore(std::string& text, std::string& pattern)
{
    std::vector<int> badChar = calcBadChar(pattern);

    // left-to-right alignment check between text and pattern
    int shift = 0;

    while (shift <= text.size() - pattern.size())
    {
        
        int j = pattern.size() - 1;

        // right-to-left comparison between pattern and text
        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0)
        {
            std::cout << "pattern found at position: " << shift << std::endl;
            
            // pattern shifting - next character in the text will align with last of occurrence of it in the pattern
            shift += shift + pattern.size() < text.size() ? pattern.size() - badChar[text[shift + pattern.size()]]
                                                          : 1;
        }
        else
        {
            shift += std::max(1, j - badChar[text[shift + j]]);
        }
    }

}

int main()
{
    std::string text = "ABAAABCD";

    std::string pattern = "ABC";

    boyerMoore(text, pattern);

    return 0;
}

