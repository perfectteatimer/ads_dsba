#include <vector>
#include <iostream>

void graphs(std::vector<std::vector<int>>& matrix1, std::vector<std::vector<int>>& matrix2, int n, int m)
{
    for (size_t route  = 0; route < m; ++route)
    {
        int k;
        std::cin >> k;
        std::vector<int> stops(k);
        for (size_t i = 0; i < k; ++i)
            std::cin >> stops[i];
        // for first graph -- просто попарно
        for (size_t i = 0; i < k - 1; ++i)
        {
            matrix1[stops[i] - 1][stops[i + 1] - 1] = 1;
            matrix1[stops[i + 1] - 1][stops[i] - 1] = 1;
        }

        // second graph -- идти вдоль всех остановок
        for (size_t i = 0; i < k; ++i)
        {
            for (size_t j = i + 1; j < k; ++j)
            {
                matrix2[stops[i] - 1][stops[j] - 1] = 1;
                matrix2[stops[j] - 1][stops[i] - 1] = 1;
            }
        }
    }
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
            if (j != n - 1)
                std::cout<< matrix1[i][j] << " ";
            else
                std::cout<< matrix1[i][j];
        std::cout<< '\n';
    }
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            if (j != n - 1)
                std::cout<< matrix2[i][j] << " ";
            else
                std::cout<< matrix2[i][j];
        }
        std::cout<< '\n';
    }
}

int main()
{
   int n, m;
   std::cin >> n >> m;
   std::vector<std::vector<int>> matrix1(n, std::vector<int>(n, 0));
   std::vector<std::vector<int>> matrix2(n, std::vector<int>(n, 0));
   graphs(matrix1, matrix2, n, m);
}

