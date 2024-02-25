#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define input std::cin >>
#define output std::cout <<

// гугл
using Graph = std::vector<std::vector<int>>; // список смежности решил через вектор

void bfs(int start, const Graph& g, std::vector<bool>& visited)
{
    std::queue<int> q;
    q.push(start);
    std::vector<int> ans;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (!visited[u])
        {
            visited[u] = true;
            ans.push_back(u);
            for (int v : g[u])
            {
                if (!visited[v])
                    q.push(v);
            }
        }
    }
    output  ans.size() << "\n"; // выводим размер
    for (int i = 0; i < ans.size(); ++i) // выводим вершины
    {
        output ans[i] << " ";
    }
}

int main()
{
    int n, m, v;
    input n >> m >> v;
    Graph g(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        input u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) // сортируем список смежности для каждой вершины в порядке убывания
        sort(g[i].rbegin(), g[i].rend());
    std::vector<bool> visited(n + 1, false);
    bfs(v, g, visited);
}