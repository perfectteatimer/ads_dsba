#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <algorithm>

#define input std::cin >>
#define output std::cout <<

bool bfs_horse(std::queue<std::pair<int, int>>& q, std::vector<std::vector<int>>& board, int k, int n, int m, int s)
{
    int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}; // possible moves for a horse in x direction
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1}; // possible moves for a horse in y direction

    while (!q.empty())
    {
        std::pair<int, int> cell = q.front(); // current cell
        q.pop();

        for (int i = 0; i < 8; ++i)
        {
            int nx = cell.first + dx[i]; // new x coordinate
            int ny = cell.second + dy[i]; // new y coordinate

            if (nx >= 0 && nx < k && ny >= 0 && ny < n &&
                board[nx][ny] == -1)  // if the new cell is within the board and not visited
            {
                q.push({nx, ny}); // push the new cell to the queue
                board[nx][ny] = board[cell.first][cell.second] + 1; // set the distance to the new cell
            }
        }
    }

    return board[m][s] != -1;
}

int main()
{
    int k, n, j, i, m, s;
    input k >> n >> j >> i >> m >> s;
    --j, --i, --m, --s; // 0-based indexing

    std::vector<std::vector<int>> board(k, std::vector<int>(n, -1));
    std::queue<std::pair<int, int>> q;

    q.push({j, i}); // start position
    board[j][i] = 0; // distance to start position

    if (bfs_horse(q, board, k, n, m, s))
        output "YES\n";
    else
        output "NO\n";
}