# using informatics
if __name__ == '__main__':
    N = int(input())
    denominations = list(map(int, input().split()))
    S = int(input())
    INF = 10**9
    F = [0] + [INF] * S
    for m in range(1, S + 1):
        for a in denominations:
            if m >= a:
                F[m] = min(F[m], F[m - a] + 1)
    # reconstruct the sequence of bills
    sequence = []
    if F[S] != INF:
        current_amount = S
        while current_amount > 0:
            for a in denominations:
                if current_amount >= a and F[current_amount - a] == F[current_amount] - 1:
                    sequence.append(a)
                    current_amount -= a
                    break
    sequence.reverse()
    if F[S] == INF:
        print(-1)
    else:
        print(F[S])
        print(*sequence)
