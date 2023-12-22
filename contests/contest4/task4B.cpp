#include <iostream>
#include <vector>
#include <algorithm>

int cheap(const std::vector<int>& v)
{
    int n = v.size();
    if (n == 1) return v[0];
    std::vector<int> ans;
    ans.push_back(v[0]), ans.push_back(v[1]);
    for (int i = 2; i < n; ++i)
        ans.push_back(std::min(ans[i - 1], ans[i - 2]) + v[i]);
    return ans[n - 1];
}

int main()
{
    int numbOfStairs;
    std::cin >> numbOfStairs;
    std::vector<int> pricesOfStairs(numbOfStairs);
    for (int i = 0; i < numbOfStairs; ++i)
        std::cin >> pricesOfStairs[i];
    std::cout << cheap(pricesOfStairs);
}
