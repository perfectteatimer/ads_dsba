#include <iostream>
#include <vector>
#include <set>
#include <string>

const long long prime = 1e9 + 9;
std::vector<long long> hashes;
std::vector<long long> reverseHashes;
std::vector<long long> primePowers;

long long computeHash(const std::string& s)
{
    long long hash = 0;
    for (char ch: s)
    {
        hash = (hash * prime + ch) % prime;
    }
    return hash;
}

void precomputeHashes(const std::string& s)
{
    int n = s.length();
    hashes.resize(n + 1, 0);
    reverseHashes.resize(n + 1, 0);
    primePowers.resize(n + 1, 1);

    for (int i = 0; i < n; ++i)
    {
        hashes[i + 1] = (hashes[i] * prime + s[i]) % prime;
        primePowers[i + 1] = (primePowers[i] * prime) % prime;
    }

    for (int i = n - 1; i >= 0; --i)
    {
        reverseHashes[i] = (reverseHashes[i + 1] * prime + s[i]) % prime;
    }
}

bool isPalindrome(int i, int j)
{
    long long forwardHash = (hashes[j + 1] - hashes[i] * primePowers[j - i + 1] + prime * prime) % prime;
    long long reverseHash = (reverseHashes[i] - reverseHashes[j + 1] * primePowers[j - i + 1] + prime * prime) % prime;
    return forwardHash == reverseHash;
}

int countUniquePalindromes(const std::string& s)
{
    precomputeHashes(s);
    std::vector<long long> uniquePalindromes;

    for (int i = 0; i < s.length(); ++i)
    {
        for (int j = i; j < s.length(); ++j)
        {
            if (isPalindrome(i, j))
            {
                uniquePalindromes.push_back(computeHash(s.substr(i, j - i + 1)));
            }
        }
    }

    return uniquePalindromes.size();
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    std::cout << countUniquePalindromes(s) << std::endl;

    return 0;
}
