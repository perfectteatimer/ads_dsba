#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <array>

using MatrixGraph = std::vector<std::vector<int>>;

#define input std::cin >>
#define output std::cout <<

bool isValidMove(int x, int y, int N, int M, const MatrixGraph& maze, std::vector<std::vector<bool>>& visited) // Проверка на возможность хода
{
    return x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 0 && !visited[x][y];
}

int bfs(const MatrixGraph& maze, std::pair<int, int> start, std::pair<int, int> end) // Обычный bfs
{
    if (maze[start.first][start.second] == 1 || maze[end.first][end.second] == 1) return -1;

    int N = maze.size(); // Размеры лабиринта
    int M = maze[0].size(); // Размеры лабиринта
    std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false)); // Массив посещенных клеток
    std::deque<std::pair<std::pair<int, int>, int>> q; // Очередь для bfs
    q.push_back({start, 0}); // Добавляем стартовую позицию

    const std::array<int, 4> dirX = {-1, 1, 0, 0}; // Векторы для ходов в 4 стороны (влево, вправо, вверх, вниз) + в интернетах написано что так быстрее
    const std::array<int, 4> dirY = {0, 0, -1, 1}; // Векторы для ходов в 4 стороны (влево, вправо, вверх, вниз) + в интернетах написано что так быстрее

    while (!q.empty()) // Пока очередь не пуста
    {
        auto [current, dist] = q.front(); // Берем первый элемент из очереди
        q.pop_front();

        if (current == end) // Если дошли до конечной точки
            return dist;

        for (int i = 0; i < 4; ++i) // Проходимся по всем 4 направлениям
        {
            int newX = current.first + dirX[i];
            int newY = current.second + dirY[i];

            if (isValidMove(newX, newY, N, M, maze, visited)) // Если ход возможен
            {
                visited[newX][newY] = true; // Помечаем клетку как посещенную
                q.push_back({{newX, newY}, dist + 1}); // Добавляем в очередь
            }
        }
    }

    return -1; // Если путь не нашли
}

int main()
{
    int N, M;
    input N >> M;
    MatrixGraph maze(N, std::vector<int>(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            input maze[i][j];
    }

    std::pair<int, int> start, end; // в интернетах написано что так быстрее (чем стурктура)

    input start.second >> start.first >> end.second >> end.first;
    start.first--;
    start.second--;
    end.first--;
    end.second--;

    output bfs(maze, start, end);
}