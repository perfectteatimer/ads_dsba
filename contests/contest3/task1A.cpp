#include <iostream>
#include <vector>

void printPrefixFunction(const std::vector<int>& preffArr)
{
    for (const int& val : preffArr)
        std::cout << val << " ";
}

void calculatePrefixFunction(const std::string& text)
{
    std::vector<int> prefArr(text.size(), 0);
    for (size_t i = 1; i < text.length(); ++i)
    {
        // initialize len to the value of the prefix function at the previous position
        size_t lenOfLongestPref = prefArr[i - 1];
        // backtrack if mismatch btw curChar and char at text[len],
        // backtrack until 0 or match
        while (lenOfLongestPref > 0 && text[i] != text[lenOfLongestPref])
            lenOfLongestPref = prefArr[lenOfLongestPref - 1];

        // match case
        if (text[i] == text[lenOfLongestPref])
            lenOfLongestPref++;

        // update the prefix function value at the current position to lenOfLong
        prefArr[i] = lenOfLongestPref;
    }
    printPrefixFunction(prefArr);
}

int main()
{
    std::string text;
    std::cin >> text;
    calculatePrefixFunction(text);
}
