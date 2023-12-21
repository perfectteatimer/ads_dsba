#include <iostream>
#include <vector>
#include <algorithm>

int cheap(std::vector<int>& v)
{
    if (v.size() < 2) return v.empty() ? 0 : v[0];

    for (int i = v.size() - 3; i >= 0; --i)
        v[i] += std::min(v[i + 1], v[i + 2]);

    return std::min(v[0], v[1]);
}

int main()
{
    int numbOfStairs, val;
    std::cin >> numbOfStairs;
    std::vector<int> pricesOfStairs;
    std::reverse(pricesOfStairs.begin(), pricesOfStairs.end());
    for (int i = 0; i < numbOfStairs; ++i)
    {
        std::cin >> val;
        pricesOfStairs.push_back(val);
    }
    std::cout << cheap(pricesOfStairs);
}
