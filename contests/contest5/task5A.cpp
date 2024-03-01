#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
// code from seminar
using Graph = std::unordered_map<int, std::unordered_set<int>>;

// bfs algorithm 
void traverse(Graph& g, int start)
{
    std::vector<bool> visited(g.size(), false);
    std::queue<int> q; // change queue to stack for dfs
    q.push(start);
    visited[start] = true;
    int count = 0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        ++count;
        for (auto& i : g[x])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }

    }
    std::cout << count;
}

int main()
{
    int n, start;
    std::cin >> n >> start;
    Graph graph(n);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int edge;
            std::cin >> edge;
            if(edge == 1)
            {
                graph[i].insert(j);
                graph[j].insert(i); // Since the graph is undirected
            }
        }
    }

    traverse(graph, start-1);

    return 0;
}



