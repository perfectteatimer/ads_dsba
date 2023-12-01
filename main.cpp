#include <iostream>
#include <vector>

void zFunctionToPrefixFunction(const std::vector<int>& z) {
    int n = z.size();
    std::vector<int> pi(n, 0);

    for (int i = 1; i < n; ++i) {
        if (z[i] > 0) {
            // Directly assign the Z-value to the appropriate position in the prefix function.
            pi[i + z[i] - 1] = z[i];
        }
    }

    // Now we need to handle the fact that pi[i] may not be the maximum for each i.
    // If we find pi[i] > pi[i + 1] + 1, we need to reduce pi[i] to pi[i + 1] + 1.
    for (int i = n - 2; i > 0; --i) {
        if (pi[i] > pi[i + 1] + 1) {
            pi[i] = pi[i + 1] + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << pi[i] << " ";
    }
    std::cout << std::endl;
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