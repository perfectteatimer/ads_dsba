#include <iostream>
#include <vector>
#include <unordered_set>

using Graph = std::vector<std::unordered_set<int>>;

bool hasCycle(const Graph& g, int v, int parent, std::vector<bool>& visited)
{
    visited[v] = true;
    for (int u : g[v])
    {
        if (!visited[u])
        {
            if (hasCycle(g, u, v, visited))
                return true;
        }
        else if (u != parent)
            return true;
    }
    return false;
}

bool isTree(const Graph& g, int N, int M)
{
    if (N != M + 1)
        return false;

    std::vector<bool> visited(N, false);
    if (hasCycle(g, 0, -1, visited))
        return false;

    for (bool v : visited)
        if (!v)
            return false;

    return true;
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    Graph graph(N);

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    std::cout << (isTree(graph, N, M) ? "YES" : "NO");

    return 0;
}
