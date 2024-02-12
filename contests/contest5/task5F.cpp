#include <iostream>
#include <vector>
#include <unordered_map>
 // using интернет и семинар

 // идея просто сделать дфс от начальной вершины, найти самую дальнюю вершину, и от нее сделать еще один дфс и найти максимальное расстояние
using Graph = std::unordered_map<int, std::vector<int>>;


void dfs(const Graph& g, int v, std::vector<bool>& visited, int& furthestNode, int& maxLength, int length = 0)
{
    visited[v] = true;
    if(length > maxLength)
    {
        maxLength = length;
        furthestNode = v;
    }
    for(auto& u : g.at(v))
    {
        if(!visited[u])
            dfs(g, u, visited, furthestNode, maxLength, length + 1);

    }
}

int main() {
    int n;
    std::cin >> n;
    Graph graph;
    for(int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int start = 0;
    std::vector<bool> visited(n, false);
    int furthestNode = 0;
    int maxLength = 0;
    // первый DFS для нахождения самой дальней вершины от начальной точки
    dfs(graph, start, visited, furthestNode, maxLength);
    std::fill(visited.begin(), visited.end(), false);
    maxLength = 0;
    // второй DFS для определения максимального расстояния в графе
    dfs(graph, furthestNode, visited, furthestNode, maxLength);
    std::cout << maxLength + 1;

}
