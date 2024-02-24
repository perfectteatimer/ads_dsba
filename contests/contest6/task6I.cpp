#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#define input std::cin >>
#define output std::cout <<
// я все что можно нашел в интернете
using Graph = std::unordered_map<int, std::unordered_map<int, int>>;

const int INF = 1e9 + 7;

std::vector<int> dist;
std::vector<bool> used;

void bellmanFord(int s, int n, Graph& graph)
{
    dist[s] = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int u = 0; u < n; ++u)
        {
            for (auto& edge: graph[u])
            {
                int v = edge.first;
                long long w = edge.second;
                // если текущее расстояние до вершины v больше, чем расстояние до u + вес ребра, обновляем его
                if (dist[u] < INF && dist[v] > dist[u] + w)
                    dist[v] = std::max(-INF, (int) (dist[u] + w));
            }
        }
    }
}
// функция для обхода графа в глубину и отметки посещенных вершин
void dfs(int v, Graph& graph)
{
    used[v] = true;
    for (auto& edge: graph[v])
    {
        int to = edge.first;
        if (!used[to])
            dfs(to, graph);
    }
}

void printres(int numbOfVertices)
{
    for (int i = 0; i < numbOfVertices; ++i)
    {
        if (dist[i] == INF)
         std::cout << "*\n";
        else if (used[i])
         std::cout << "-\n";
        else
         std::cout << dist[i] << "\n";
    }
}

int main()
{
    int numbOfVertices, numbOfEdges, s;
    input numbOfVertices >> numbOfEdges >> s;
    --s;
    Graph graph;
    dist.resize(numbOfVertices, INF);
    used.resize(numbOfVertices, false);
    for (int i = 0; i < numbOfEdges; ++i)
    {
        int u, v, w;
        input u >> v >> w;
        --u;
        --v;
        graph[u][v] = w;
    }
    bellmanFord(s, numbOfVertices, graph);

    // проверка на наличие циклов отрицательного веса
    for (int u = 0; u < numbOfVertices; ++u)
    {
        for (auto& edge: graph[u])
        {
            int v = edge.first;
            long long w = edge.second;
            if (dist[u] < INF && dist[u] + w < dist[v])
                if (!used[v]) dfs(v, graph);
        }
    }
    printres(numbOfVertices);
}