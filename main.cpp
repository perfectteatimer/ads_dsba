#include <iostream>
#include <vector>
#include <algorithm>

// manacher's algorithm for 100000000-d time
long long countPalindromicSubstrings(const std::string& s) {
    // Preprocess the input string to include special characters
    std::string processedString = "#";
    for (char c : s)
    {
        processedString += c;
        processedString += '#';
    }

    int n = processedString.size();
    std::vector<long long> palindromeLengths(n, 0);

    long long center = 0,  right = 0;
    long long totalPalindromes = 0;

    for (int i = 0; i < n; ++i)
    {
        long long mirror = 2 * center - i;

        if (i < right)
            palindromeLengths[i] = std::min(right - i, palindromeLengths[mirror]);

        // Attempt to expand palindrome centered at i
        int a = i + (1 + palindromeLengths[i]);
        int b = i - (1 + palindromeLengths[i]);

        while (a < n && b >= 0 && processedString[a] == processedString[b])
        {
            palindromeLengths[i]++;
            a++;
            b--;
        }

        // If palindrome centered at i expands past right,
        // adjust center and right based on current palindrome
        if (i + palindromeLengths[i] > right)
        {
            center = i;
            right = i + palindromeLengths[i];
        }

        // Count the palindromes at the current position
        totalPalindromes += (palindromeLengths[i] + 1) / 2;
    }

    return totalPalindromes;
}

int main() {
    std::string input(100000, 'a');


    long long result = countPalindromicSubstrings(input);

    std::cout << result - input.size();

    return 0;
}