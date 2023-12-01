#include <iostream>
#include <vector>

void zFunctionToPrefixFunction(const std::vector<int>& z)
{
    int n = z.size();
    std::vector<int> pi(n, 0);
    for (size_t i = 1; i < n; ++i)
    {
        if (z[i] > 0)
        {
            for (int j = z[i] - 1; j >= 0; --j)// если не вставляли значение
            {
                if (pi[i + j] != 0)
                    continue;
                else
                    pi[i + j] = j + 1;
            }
        }
    }
    for (const int& v: pi)
        std::cout << v << " ";
}

int main()
{
    std::ios_base::sync_with_stdio(false); //ускоряет код
    std::cin.tie(nullptr);
    int n, val;
    std::cin >> n;
    std::vector<int> z;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> val;
        z.push_back(val);
    }
    zFunctionToPrefixFunction(z);
}