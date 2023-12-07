#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// using rucode

std::vector<int> zFunction(const std::string& s)
{
    int n = s.length();
    std::vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
        {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            ++z[i];
        }
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}


void calSubStrings(const std::string& t)
{
    std::vector<int> zF = zFunction(t);
    for (size_t i = 0; i < zF.size(); ++i)
    {
        std::cout << zF[i];
    }
}

int main()
{
    std::string s;
    std::cin >> s;
    std::string t = s + 's';
    std::reverse(t.begin(), t.end());
    calSubStrings(t);
}
