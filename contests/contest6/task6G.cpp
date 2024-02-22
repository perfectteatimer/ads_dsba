#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

#define input std::cin >>
#define output std::cout <<
// e maxx
using Graph = std::unordered_map<int, std::unordered_map<int, int>>;

void floyd(Graph& g, int n)
{
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
        for (int j = 0; j < n; ++j)
        {
            if (g[i][j] == INT_MAX)
                output -1 << " ";
            else
                output g[i][j] << " ";
        }
        output "\n";
    }
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
            if (i != j)
                graph[i][j] = edge;
        }
    }
    floyd(graph, numbOfVertices);
}