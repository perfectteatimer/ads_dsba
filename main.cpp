#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <boost>

typedef long long ll;
const ll P = 31;
const ll M = 1e9 + 7;

// Function to compute the hash of a string
ll computeHash(const std::string& s) {
    ll hash_value = 0;
    ll p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % M;
        p_pow = (p_pow * P) % M;
    }
    return hash_value;
}

void compareSubstring(const std::string& s, size_t m) {
    // An unordered_map to store the precomputed hashes of substrings
    std::unordered_map<std::pair<int, int>, ll, boost::hash<std::pair<int, int>>> hash_cache;

    for (size_t i = 0; i < m; ++i) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        a--; b--; c--; d--; // Convert to zero-based indexing

        // Check if the hashes are already computed
        std::pair<int, int> substr1_indices = {a, b};
        std::pair<int, int> substr2_indices = {c, d};

        if (hash_cache.find(substr1_indices) == hash_cache.end()) {
            hash_cache[substr1_indices] = computeHash(s.substr(a, b - a + 1));
        }
        if (hash_cache.find(substr2_indices) == hash_cache.end()) {
            hash_cache[substr2_indices] = computeHash(s.substr(c, d - c + 1));
        }

        std::cout << (hash_cache[substr1_indices] == hash_cache[substr2_indices] ? "Yes" : "No") << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    size_t m;
    std::cin >> m;
    compareSubstring(s, m);
}
