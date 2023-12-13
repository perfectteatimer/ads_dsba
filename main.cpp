#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Function to calculate the Longest Common Prefix (LCP) array given a suffix array and the original text.
void lcp(int size, const std::vector<int>& suff_arr, std::string& text) {
    // lcp: Array to store the length of the longest common prefix between consecutive suffixes.
    std::vector<int> lcp(size, 0);

    // lcp_reversed: Array to store the rank of each suffix in the sorted order of suffixes.
    std::vector<int> lcp_reversed(size, 0);

    // Assign ranks to suffixes based on their position in the suffix array.
    for (size_t i = 0; i < size; ++i)
        lcp_reversed[suff_arr[i]] = i;

    // k: Length of the common prefix found so far.
    size_t k = 0;

    // Iterate over each suffix in the original string.
    for (size_t i = 0; i < size; ++i) {
        if (k > 0) --k;

        // If the current suffix is the last one in the sorted order, set LCP to -1 and reset k.
        if (lcp_reversed[i] == size - 1)
        {
            k = 0;
            continue;
        } else {
            // j: Index of the next suffix in the sorted order.
            int j = suff_arr[lcp_reversed[i] + 1];

            // Calculate the LCP of the current suffix and the next suffix in the sorted order.
            while (i + k < size && j + k < size && text[i + k] == text[j + k]) {
                ++k;
            }

            // Assign the LCP length to the current suffix's position in the LCP array.
            lcp[lcp_reversed[i]] = k;
        }
    }

    // Print the LCP array.
    for (size_t i = 0; i < size - 1; ++i) {
        std::cout << lcp[i] << " ";
    }
}

// The main function to read input and call the LCP calculation function.
int main() {
    int n;  // The length of the string.
    std::string text;  // The input text.

    // Read the length and the text.
    std::cin >> n;
    std::cin >> text;
    text += "$";  // Append the end-of-string marker.

    // suff_arr: Vector to store the suffix array.
    std::vector<int> suff_arr(n, 0);

    // Read the suffix array.
    int val;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> val;
        suff_arr[i] = val - 1;  // Adjust for 0-based indexing.
    }

    // Call the LCP calculation function.
    lcp(n, suff_arr, text);
}
