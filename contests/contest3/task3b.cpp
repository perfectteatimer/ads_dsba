#include <iostream>
#include <string>

bool areSubstrEqual(const std::string& s, int a, int b, int c, int d)
{
    if (b -  a != d - c) return false; // if sizes are not equal => false
    else
    {
        for (size_t i = 0; i <= b - a; ++i) // compare characters for their entire length
        {
            if (s[a + i - 1] != s[c + i - 1]) return false; // comparing each charact of each substr
        }
        return true;
    }

}

void compareSubstring(std::string &s, size_t m)
{
    for (size_t i = 0; i < m; ++i)
    {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        std::cout << (areSubstrEqual(s, a, b, c, d) ? "Yes": "No") << "\n";
    }
}

int main()
{
    std::string s;
    std::cin >> s;
    size_t m;
    std::cin >> m;
    compareSubstring(s, m);
}