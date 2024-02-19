#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <algorithm>

#define input std::cin >>
#define output std::cout <<

using Graph = std::unordered_map<int, std::unordered_set<int>>;

void bfs(Graph& g, int start, std::vector<int>& distance)
{
    std::queue<int> q;
    q.push(start);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(int y : g[x])
        {
            if(distance[y] == -1)
            {
                distance[y] = distance[x] + 1;
                q.push(y);
            }
        }
    }
}

int main()
{
    int n;
    input n;

    Graph g;
    std::vector<int> distance(n + 1, -1);
    distance[1] = 0;

    for(int i = 2; i <= n; ++i)
    {
        int parent;
        input parent;
        g[parent].insert(i);
        g[i].insert(parent);
    }

    bfs(g, 1, distance);

    int max_distance = *std::max_element(distance.begin(), distance.end());
    std::vector<int> farthest_nodes;
    for(int i = 1; i <= n; ++i)
    {
        if(distance[i] == max_distance)
            farthest_nodes.push_back(i);
    }

    output max_distance << "\n";
    output farthest_nodes.size() << "\n";
    for(int node : farthest_nodes)
        output node << " ";
    output "\n";

}