#include <iostream>
#include <vector>
#include <unordered_set>
// using интернет и семинар
using Graph = std::vector<std::unordered_set<int>>;

std::vector<int> component; // для хранения номера компоненты связности каждой вершины
std::vector<bool> visited;  // для отслеживания посещенных вершин

// дфс+компонент счетчик
void dfs(const Graph& graph, int vertex, int compNum)
{
    visited[vertex] = true;
    component[vertex] = compNum;

    for (int neighbor : graph[vertex])
    {
        if (!visited[neighbor])
            dfs(graph, neighbor, compNum);
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;
    Graph graph(N);

    visited.resize(N, false);
    component.resize(N, 0);

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    int compNum = 0; // счетчик компонент связности
    for (int i = 0; i < N; ++i)
    {
        if (!visited[i])
            dfs(graph, i, ++compNum); // если вершине не посещена запускаем обход в глубину
    }

    std::cout << compNum << "\n"; // количество компонент связности
    for (int i = 0; i < N; ++i)
        std::cout << component[i] << " "; // номер компоненты связности для каждой вершины


}
