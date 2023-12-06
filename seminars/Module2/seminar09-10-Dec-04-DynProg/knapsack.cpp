#include <iostream>
#include <vector>
#include <algorithm>

void knapsack(int w, std::vector<int>& weights, std::vector<int>& values)
{
    std::vector<int> k(w + 1, 0);

    for(size_t i = 1; i <= w; ++i)
    {
        for (size_t j = 0; j < weights.size(); ++j)
        {
            if (weights[j] <= i)
                k[i] = std::max(k[i], k[i - weights[j]] + values[j]);
        }
    }
    for(int val: k)
        std::cout<< val << " ";
}


int main()
{
    std::vector<int> weights = {1, 2, 3};
    std::vector<int> values = {1, 4, 6};
    knapsack(6, weights, values);
}

