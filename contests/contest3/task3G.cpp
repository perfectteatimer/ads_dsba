#include <iostream>
#include <string>
#include <set>

long long calcSub(std::string& s)
{
    std::set<std::string> uniqueSubstrings;
    for (size_t i = 0; i < s.length(); ++i)
    {
        for (size_t j = i + 1; j < s.length() + 1; ++j)
        {
            uniqueSubstrings.insert(s.substr(i, j - i));
        }
    }
    return uniqueSubstrings.size();
}


int main()
{
    std::ios_base::sync_with_stdio(false); //ускоряет код
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    std::cout <<  calcSub(s);
}
