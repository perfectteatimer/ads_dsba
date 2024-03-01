#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    long long n;
    std::cin >> n;
    std::vector<long long> a(n);
    long long max_spaces = 0;
    for (long long& ai: a) {
        std::cin >> ai;
        max_spaces = std::max(max_spaces, ai);
    }

    const long long MAX_SPACES = 4294967295;
    std::vector<long long> dp(max_spaces + 5, MAX_SPACES);
    dp[0] = 0;
    for (long long i = 1; i <= max_spaces; ++i)
    {
        dp[i] = std::min(dp[i], dp[i - 1] + 1);
        if (i >= 4) dp[i] = std::min(dp[i], dp[i - 4] + 1);
        if (i > 0) dp[i + 1] = std::min(dp[i + 1], dp[i] + 1);
    }

    long long totalKeyPresses = 0;
    for (long long ai: a) totalKeyPresses += dp[ai];

    std::cout << totalKeyPresses;
}