#include <iostream>
#include <string>

// reference https://www.geeksforgeeks.org/string-hashing-using-polynomial-rolling-hash-function/

bool hashPolynomial(const std::string& substr1, const std::string& substr2)
{
    long long p = 31;
    long long m = 1e9 + 7;
    long long hash1 = 0;
    long long hash2 = 0;
    long long p_pow = 1;
    for (size_t i = 0; i < substr1.size(); ++i)
    {
        hash1 = ((hash1 + (substr1[i] - 'a' + 1) * p_pow) % m);
        p_pow = (p_pow * p) % m;
    }
    p_pow = 1;
    for (size_t i = 0; i < substr2.size(); ++i)
    {
        hash2 = ((hash2 + (substr2[i] - 'a' + 1) * p_pow) % m);
        p_pow = (p_pow * p) % m;
    }

    return hash1== hash2;
}

void compareSubstring(std::string& s, size_t m) {
    for (size_t i = 0; i < m; ++i)
    {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        std::string substr1 = s.substr(a - 1, b - a + 1);
        std::string substr2 = s.substr(c - 1, d - c + 1);
        std::cout << (hashPolynomial(substr1, substr2) ? "Yes" : "No") << '\n';
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false); //ускоряет код
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    size_t m;
    std::cin >> m;
    compareSubstring(s, m);
}