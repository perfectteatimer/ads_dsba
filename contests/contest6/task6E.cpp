#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

#define input std::cin >>
#define output std::cout <<
// aлгоритимка
using Graph = std::unordered_map<int, std::unordered_map<int, int>>;

void dijkstra(Graph& g, int start, int finish)
{
    std::vector<int> dist(g.size(), INT_MAX);
    std::vector<bool> visited(g.size(), false);
    dist[start] = 0;
    for (int i = 0; i < g.size(); ++i)
    {
        int v = -1;
        for (int j = 0; j < g.size(); ++j)
        {
            if (!visited[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        }
        if (dist[v] == INT_MAX)
            break;
        visited[v] = true;
        for (auto& u: g[v])
        {
            if (dist[v] + u.second < dist[u.first])
                dist[u.first] = dist[v] + u.second;
        }
    }
    if (dist[finish] == INT_MAX)
        output -1;
    else
        output dist[finish];
}

int main()
{
    Graph graph;
    int numbOfVertices, start, finish;
    input numbOfVertices >> start >> finish;
    --start;
    --finish; // 0-based indexing
    for (int i = 0; i < numbOfVertices; ++i)
    {
        for (int j = 0; j < numbOfVertices; ++j)
        {
            int edge;
            input edge;
            if (edge != -1)
                graph[i][j] = edge;
        }
    }
    dijkstra(graph, start, finish);
}