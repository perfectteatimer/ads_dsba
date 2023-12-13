#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// using emaxx and itmo

void lcp(int size, const std::vector<int>& suff_arr, std::string& text)
{
    std::vector<int> lcp(size, 0);
    std::vector<int> lcp_reversed(size, 0); // array to store the rank(index) of each suffix in the sorted order of suffixes

    for (size_t i = 0; i < size; ++i)
        lcp_reversed[suff_arr[i]] = i; // assign ranks(indexes) to suffixes based on their position in the suffix array

    size_t k = 0; // length of the common prefix found
    for (size_t i = 0; i < size; ++i)  // iterate over each suffix in the original string
    {
        if (k > 0) --k;
        if (lcp_reversed[i] == size - 1) // if the current suffix is the last one in the sorted order set k = 0 (means cant add more)
        {
            k = 0;
            continue;
        }
         else
         {
            int j = suff_arr[lcp_reversed[i] + 1]; // index of the next suffix in the sorted order.
            while (i + k < size && j + k < size && text[i + k] == text[j + k]) // calculate the lcp of the current suffix and the next suffix in the sorted order
                ++k;
            lcp[lcp_reversed[i]] = k; // assign the lcp len to the current suffixs position in the lcp arr
        }
    }
    for (size_t i = 0; i < size - 1; ++i)
        std::cout << lcp[i] << " ";
}

int main() {
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
        suff_arr[i] = val - 1; // to 0 based indexing
    }
    lcp(n, suff_arr, text);
}
