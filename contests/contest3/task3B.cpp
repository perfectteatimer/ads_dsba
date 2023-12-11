#include <iostream>
#include <string>
#include <vector>

// na4erpal vse shto mozno

std::vector<long long> hashes;
std::vector<long long> prime_pow;
const long long prime = 1e9+9;

long long getHash(int begin, int end)
{
    return hashes[end + 1] - hashes[begin] * prime_pow[end - begin + 1];
}

bool equalSubstr(int a, int b, int c, int d)
{
    return getHash(a, b) == getHash(c, d);
}


void hashing(std::string& s, size_t m)
{
    prime_pow.resize(s.length() + 1);
    hashes.resize(s.length() + 1);
    hashes[0] = 0, prime_pow[0] = 1;
    for (size_t i = 0; i < s.length()  ; ++i)
    {
        hashes[i + 1] = (hashes[i] * prime + s[i]);
        prime_pow[i + 1] = (prime_pow[i] * prime);
    }
    for (size_t i = 0; i < m; ++i)
    {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        std::cout << (equalSubstr(a, b, c, d) ? "Yes" : "No") << "\n";
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
    hashing(s, m);
}