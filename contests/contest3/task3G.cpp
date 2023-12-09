#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// using emaxx

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


int calSubStrings(const std::string& input)
{
    std::string s;
    int count = 0; // считать уникальные подстроки

    for (char c: input)
    {
        s = c + s;
        std::vector<int> z = zFunction(s);
        int zMax = *std::max_element(z.begin(), z.end());
        count += s.size() - zMax;
    }
    return count;
}

int main()
{
    std::string input;
    std::cin >> input;
    std::cout << calSubStrings(input);
}
