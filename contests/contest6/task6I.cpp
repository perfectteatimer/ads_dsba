#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define input std::cin >>
#define output std::cout <<
#include <numeric>

// Кароч я очень силньо устал и нашел идею реализации, и вот она тут

// Структура для ребра графа
struct Edge{
    int from, to; // Переменные для хранения начала и конца ребра
    long long weight; // ПЕРЕменная для хранения веса ребра

    Edge(int f, int t, int64_t w) : from(f), to(t), weight(w) {} // Конструктор для удобства создания рёбер
};

std::vector<bool> used; // Вектор для отметки посещенных вершин
std::vector<std::vector<int>> graph;
std::set<int> answerSet;
std::vector<long long> distance; // Вектор для хранения расстояний от начальной вершины до остальных
const long long INF = 9223372036854775807;


void inputEdges(int m, std::vector<Edge>& edges)
{
    int from, to; // Переменные для хранения начала и конца ребра
    long long weight; // Переменная для хранения веса ребра
    for (int i = 0; i < m; ++i)
    {
        input from >> to >> weight;
        edges.emplace_back(from, to, weight); // Добавление ребра в вектор
        graph[from].push_back(to); // Добавление вершины в список смежности
    }
}

// DFS для поиска достижимых вершин
void dfs(int vertex)
{
    used[vertex] = true; // Отмечаем вершину как посещенную
    for (int adj: graph[vertex]) // Проходим по всем смежным вершинам
    {
        if (!used[adj]) // Если вершина еще не была посещена
        {
            answerSet.insert(adj); // Добавляем ее в множество ответа
            dfs(adj); // Запускаем дфс от этой вершины
        }
    }
}

void updateDistancesAndFindNegativeCycles(const std::vector<Edge>& edges, int n, int m)
{
    for (int k = 0; k < n; ++k)
    { // Проходим по всем вершинам
        for (const auto& edge : edges) // Проходим по всем ребрам
        {
            if (distance[edge.from] < INF) // Если расстояние до начала ребра меньше бесконечности
            {
                if (distance[edge.to] > distance[edge.from] + edge.weight) // Если можно улучшить расстояние до конца ребра
                {
                    distance[edge.to] = distance[edge.from] + edge.weight; // Улучшаем расстояние
                    if (k == n - 1) // Если это последняя итерация
                    {
                        answerSet.insert(edge.from); // Добавляем начало и конец ребра в множество ответа
                        answerSet.insert(edge.to);
                    }
                }
            }
        }
    }
}


void printResults(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        if (distance[i] == INF) // Если расстояние до вершины равно бесконечности
            output "*\n"; // Выводим *
        else if (answerSet.find(i) != answerSet.end()) // Если вершина находится в множестве ответа
            output "-\n"; // Выводим -
        else // Иначе
            output distance[i] << '\n'; // Выводим расстояние до вершины
    }
}

int main()
{
    int n, m, s;
    input n >> m >> s;
    std::vector<Edge> edges;
    graph.resize(n + 1); // Изменение размера графа
    used.assign(n + 1, false); // Инициализация вектора used
    distance.assign(n + 1, INF); // Инициализация вектора distance

    inputEdges(m, edges);
    distance[s] = 0; // Устанавливаем расстояние до начальной вершины равным 0 (начальное)

    updateDistancesAndFindNegativeCycles(edges, n, m); // Обновляем расстояния и ищем отрицательные циклы

    for (int x: answerSet) // Проходим по всем вершинам в множестве ответов
        if (!used[x]) dfs(x); // Если вершина еще не была посещена, запускаем дфс

    printResults(n);
}
