#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// using emax + itmo

void lcp(int size, const std::vector<int>& suff_arr, std::string& text)
{
    std::vector<int> lcp(size, 0);
    std::vector<int> lcp_reversed(size, 0);

    for (size_t i = 0; i < size - 1; ++i)
        lcp_reversed[suff_arr[i]] = i;

    size_t k = 0;
    for (size_t i = 0; i < size - 1; ++i)
    {
        if (k > 0) --k;
        if (lcp_reversed[i] == size - 1)
        {
            lcp[size - 1] = - 1, k = 0;
            continue;
        }
        else
        {
            int j = suff_arr[lcp_reversed[i] + 1];
            int max = std::max(i + k, j + k);
            while (max < size - 1 && text[i + k] == text[j + k])
                ++k;
            lcp[lcp_reversed[i]] = k;
        }
    }
    for (const auto& el: lcp)
        std::cout << el <<  " " << 1;
}


int main()
{
    int n;
    std::string text;
    std::cin >> n;
    std::cin >> text;
    text += "$";
    std::vector<int> suff_arr(n, 0);
    int val;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> val;
        suff_arr.push_back(val);
    }
    lcp(n, suff_arr, text);
}
