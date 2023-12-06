#include <iostream>
#include <vector>
#include <climits>

int minCoins(int target, const std::vector<int>& coins)
{
    std::vector<int> K(target + 1, INT_MAX);
    K[0] = 0;
    for (int x = 1; x <= target; ++x)
    {
        for (int c: coins)
        {
            if (c <= x && K[x - c] != INT_MAX)
            {
                K[x] = std::min(K[x], 1 + K[x - c]);
            }
        }
    }

    return K[target] == INT_MAX ? -1 : K[target];
}

int main()
{
    std::vector<int> coins = {1, 2, 5};
    std::cout<< minCoins(6, coins);
}
