#include <iostream>
#include <vector>
#include <algorithm>
// using интернет много и семинар

using Graph = std::vector<std::vector<int>>;

bool storeCyclesIfExist(const Graph& g, int v, std::vector<int>& parent, std::vector<bool>& visited, std::vector<bool>& recStack, std::vector<int>& cycle)
{
    visited[v] = true;
    recStack[v] = true;

    for (int u: g[v])
    {
        if (!visited[u])
        {
            parent[u] = v; // сохраняем предка для восстановления пути
            if (storeCyclesIfExist(g, u, parent, visited, recStack, cycle)) return true;
        }
        else if (recStack[u])
        {
            // восстанавливаем цикл
            int cur = v;
            cycle.push_back(cur);
            while (cur != u)
            {
                cur = parent[cur];
                cycle.push_back(cur);
            }
            return true;
        }
    }

    recStack[v] = false;
    return false;
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    Graph graph(N);
    std::vector<int> parent(N, -1);
    std::vector<bool> visited(N, false), recStack(N, false);
    std::vector<int> cycle;

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
    }

    bool cycleFound = false;
    for (int i = 0; i < N && !cycleFound; ++i)
    {
        if (!visited[i] && storeCyclesIfExist(graph, i, parent, visited, recStack, cycle))
        {
            cycleFound = true;
            std::cout << "YES\n";
            for (auto it = cycle.rbegin(); it != cycle.rend(); ++it)
                std::cout << *it + 1 << " ";
            std::cout << "\n";
        }
    }

    if (!cycleFound)
        std::cout << "NO";
}
