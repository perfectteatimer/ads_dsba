if __name__ == '__main__':
    aaa = int(input())
    masivchik = []


for i in range(aaa):
    stroka = [1] * (i + 1)
    for j in range(i + 1):
        if j != 0 and j != i:
            stroka[j] = masivchik[i - 1][j - 1] + masivchik[i - 1][j]

    masivchik.append(stroka)

for something in masivchik:
    print (*something)


