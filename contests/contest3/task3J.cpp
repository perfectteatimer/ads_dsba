#include<iostream>
#include<vector>
#include<string>
#include <map>
#include <fstream>
#include <cstring>

std::vector<size_t> build_suff_arr(std::vector<size_t>& v)
{
    v.push_back(0);
    size_t cnt = 0;
    size_t num = 0;
    std::vector<size_t> p(v.size());
    std::vector<size_t> c(v.size());
    std::map<size_t, std::vector<size_t>> t;

    for (size_t i = 0; i < v.size(); ++i)
    {
        t[v[i]].push_back(i);
    }
    for (auto& [key, val]: t)
    {
        for (auto x: val)
        {
            c[x] = num;
            p[cnt] = x;
            ++cnt;
        }
        ++num;
    }

    size_t k = 1;
    while (num < v.size())
    {
        std::vector<std::vector<size_t>> s(num);
        std::vector<size_t> new_c(v.size());
        size_t x = (1 << k) / 2;
        size_t new_num = 0;
        cnt = 0;
        for (size_t i = 0; i < v.size(); ++i)
        {
            size_t y = (p[i] + v.size() - x) % v.size();
            s[c[y]].push_back(y);
        }
        for (size_t i = 0; i < num; ++i)
        {
            for (size_t j = 0; j < s[i].size(); ++j)
            {
                p[cnt] = s[i][j];
                ++cnt;
                if (j == 0)
                    ++new_num;
                else if (c[(s[i][j] + x) % v.size()] != c[(s[i][j - 1] + x) % v.size()])
                    ++new_num;
                new_c[s[i][j]] = new_num - 1;
            }
        }
        std::swap(c, new_c);
        std::swap(num, new_num);
        ++k;
    }
    return p;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    std::vector<size_t> ind;

    for (char c: s)
        ind.push_back(c);
    std::vector<size_t> ans = build_suff_arr(ind);
    for (size_t i = 1; i < ans.size(); ++i)
        std::cout << ans[i] + 1 << ' ';
}
