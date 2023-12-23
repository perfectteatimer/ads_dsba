if __name__ == '__main__':
    N, M = map(int, input().split())
    board = []
    for i in range(N):
        row = []
        for j in range(M):
            row.append(0)
        board.append(row)
    # start
    board[0][0] = 1
    for i in range(N):
        for j in range(M):
            #  if the knight can move two steps down and one step right
            if i + 2 < N and j + 1 < M:
                board[i + 2][j + 1] += board[i][j]
            # if the knight can move two steps right and one step down
            if i + 1 < N and j + 2 < M:
                board[i + 1][j + 2] += board[i][j]
    print(board[N - 1][M - 1])
