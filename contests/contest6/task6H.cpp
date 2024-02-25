#include <iostream>
#include <unordered_map>
#include <climits>
#define input std::cin >>
#define output std::cout <<
// гуггл
using Graph = std::unordered_map<int, std::unordered_map<int, int>>;

void floyd(Graph& g, int n)
{
    int diameter = 0;
    int radius = INT_MAX;

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (g[i][k] < INT_MAX && g[k][j] < INT_MAX)
                    g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        int max_distance = 0;
        for (int j = 0; j < n; ++j)
        {
            if (i != j && g[i][j] != INT_MAX)
                max_distance = std::max(max_distance, g[i][j]);
        }
        diameter = std::max(diameter, max_distance);
        radius = std::min(radius, max_distance);
    }

    output diameter << '\n' << radius << "\n";
}

int main()
{
    int numbOfVertices;
    input numbOfVertices;
    Graph graph(numbOfVertices);
    for (int i = 0; i < numbOfVertices; ++i)
    {
        for (int j = 0; j < numbOfVertices; ++j)
        {
            int edge;
            input edge;
            if (edge == -1)
                graph[i][j] = INT_MAX;
            else
                graph[i][j] = edge;
        }
    }
    floyd(graph, numbOfVertices);
}