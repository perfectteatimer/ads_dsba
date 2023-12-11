#include<iostream>
#include<vector>
#include<string>

void FindOdd(std::vector<int64_t> &v, std::string &s) {
    int64_t left = 0;
    int64_t right = -1;
    for (int64_t i = 0; i < s.size(); ++i) {
        int64_t k = 0;
        if (i > right) {
            k = 1;
        } else {
            k = std::min(right - i + 1, v[left + right - i]);
        }
        while (i + k < s.size() && i - k >= 0 && s[i + k] == s[i - k]) {
            ++k;
        }
        v[i] = k;
        if (i + k - 1 > right) {
            left = i - k + 1;
            right = i + k - 1;
        }
    }
}

void FindEven(std::vector<int64_t> &v, std::string &s) {
    int64_t left = 0;
    int64_t right = -1;
    for (int64_t i = 0; i < s.size(); ++i) {
        int64_t k = 0;
        if (i > right) {
            k = 0;
        } else {
            k = std::min(right - i + 1, v[left + right - i + 1]);
        }
        while (i + k < s.size() && i - k - 1 >= 0 && s[i + k] == s[i - k - 1]) {
            ++k;
        }
        v[i] = k;
        if (i + k - 1 > right) {
            left = i - k;
            right = i + k - 1;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s(100000, 'a');
    std::vector<int64_t> odd(s.size(), 0);
    std::vector<int64_t> even(s.size(), 0);
    FindOdd(odd, s);
    FindEven(even, s);
    size_t cnt = 0;
    for (auto x: odd) {
        cnt += x - 1;
    }
    for (auto x: even) {
        cnt += x;
    }
    std::cout << cnt;
    return 0;
}
