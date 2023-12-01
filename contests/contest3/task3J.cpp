#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> buildSuffixArray(const std::string& s)
{
    std::vector<int> suffixes(s.length());

    for (int i = 0; i < s.length(); ++i)
        suffixes[i] = i;

    sort(suffixes.begin(), suffixes.end(), [&](int i, int j)
    {
        return s.substr(i) < s.substr(j);
    });

    return suffixes;
}

int main()
{
    std::string s;
    std::cin >> s;
    std::vector<int> suffixArray = buildSuffixArray(s);
    for (int idx : suffixArray)
        std::cout << idx + 1 << " ";

}
