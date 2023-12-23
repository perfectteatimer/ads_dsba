if __name__ == '__main__':
    n = int(input())
    if n == 1:
        print(0)
        print(1)
    operations = [0] * (n + 1)  # arr to store minimum operations for each number up to n
    path = [0] * (n + 1)  # arr to reconstruct the path
    for i in range(2, n + 1):
        min_ops = operations[i - 1] + 1
        path[i] = i - 1
        # check if divisible by 2 and if this path takes fewer operations
        if i % 2 == 0 and operations[i // 2] + 1 < min_ops:
            min_ops = operations[i // 2] + 1
            path[i] = i // 2
        # check if divisible by 3 and if this path takes fewer operations
        if i % 3 == 0 and operations[i // 3] + 1 < min_ops:
            min_ops = operations[i // 3] + 1
            path[i] = i // 3
        operations[i] = min_ops
    # reconstruct the path
    sequence = []
    while n:
        sequence.append(n)
        n = path[n]
    sequence.reverse()
    print(operations[-1])
    print(*sequence)
