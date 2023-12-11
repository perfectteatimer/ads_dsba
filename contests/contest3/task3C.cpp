#include <iostream>
#include <string>
#include <functional>
#include <set>
#include <algorithm>


// in the modified string positions corresponding to the original characters will have odd indexes
// and positions corresponding to the inserted # characters will have even indexes
// the function[i] + (i % 2) part of the code adjusts the count for these positions
// for even indices (original characters), (i % 2) is 0 so it just counts function[i] / 2.
// for odd indices (inserted # characters), (i % 2) is 1 so it counts (function[i] + 1) / 2
int64_t number_of_palindromes(const std::vector<int64_t>& function)
{
    int64_t counter = 0;
    for (size_t i = 0; i < function.size(); ++i) {
        counter += (function[i] + (i % 2)) / 2;
    }
    return counter;
}


void calculate_function(const std::string& p_s)
{
    std::vector<int64_t> function(p_s.length(), 0);
    int64_t center = 0, right = 0;

    for (int i = 1; i < p_s.length(); ++i)
    {
        int mirror = 2 * center - i; // mirror value

        if (i < right) // if i is within our current palindrome
            function[i] = std::min(static_cast<int64_t>(right - i), function[mirror]);

        // attempt to expand palindrome centered at i
        while (p_s[i + 1 + function[i]] == p_s[i - 1 - function[i]])
            function[i]++;

        // if the palindrome expanded past the right boundary,
        // update center and right
        if (i + function[i] > right)
        {
            center = i;
            right = i + function[i];
        }
    }

    std::cout << number_of_palindromes(function);
}


void construct_string(const std::string& s)
{
    std::string proper_string = "$";
    for (char c: s)
        proper_string += "#" + std::string(1, c);

    proper_string += "#@";
    calculate_function(proper_string);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    construct_string(s);
}
