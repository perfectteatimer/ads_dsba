#include <vector>
#include <iostream>

void countVisitedCells(std::vector<std::vector<int>>& room, int n, int m)
{
    char ch;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> ch;
            if (ch == '#')
                room[i][j] = 1;
        }
    }
    int q, counter = 0;
    std::cin >> q;
    std::string str;
    std::cin >> str;
    for (size_t i = 0; i < q; ++i)
    {
        if (str[i] == )
    }

}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> room(n, std::vector<int>(m, 0));
    countVisitedCells(room, n, m);
}

