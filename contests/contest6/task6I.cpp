#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

#define input std::cin >>
#define output std::cout <<
// e maxx
using Graph = std::unordered_map<int, std::unordered_map<int, int>>;

void bellmanford(Graph& g, int n, int s)
{
    std::vector<long long> dist(n, INT_MAX);
    dist[s] = 0;
    for (int i = 0; i < n; ++i)
        for (auto& u : g)
            for (auto& v : u.second)
                if (dist[u.first] < INT_MAX)
                    dist[v.first] = std::min(dist[v.first], dist[u.first] + v.second);
    std::vector<bool> inCycle(n, false);
    for (int i = 0; i < n; ++i)
        for (auto& u : g)
            for (auto& v : u.second)
                if (dist[u.first] < INT_MAX && dist[u.first] + v.second < dist[v.first])
                    inCycle[v.first] = true;
    for (int i = 0; i < n; ++i) // additional loop to detect negative cycles
        for (auto& u : g)
            for (auto& v : u.second)
                if (!inCycle[u.first] && dist[u.first] < INT_MAX && dist[u.first] + v.second < dist[v.first])
                    inCycle[v.first] = true;
    for (int u = 0; u < n; ++u)
        if (dist[u] == INT_MAX)
            output "*\n";
        else if (inCycle[u])
            output "-\n";
        else
            output dist[u] << "\n";
}

int main()
{
    int numbOfVertices, numbOfEdges, s;
    input numbOfVertices >> numbOfEdges >> s;
    --s;
    Graph graph;
    for (int i = 0; i < numbOfEdges; ++i)
    {
        int u, v, w;
        input u >> v >> w;
        --u;
        --v;
        graph[u][v] = w;
    }
    bellmanford(graph, numbOfVertices, s);
}