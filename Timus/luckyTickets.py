n, s = map(int, input().split())
n *= 2

if s % 2 == 1 or s > 9 * n:
    print(0)
    exit()

ways = [[0 for _ in range(n // 2 + 1)] for _ in range(s // 2 + 1)]
ways[0][0] = 1

for i in range(s // 2 + 1):
    for j in range(n // 2 + 1):
        for k in range(10):
            if i - k >= 0 and j - 1 >= 0:
                ways[i][j] += ways[i - k][j - 1]

print(ways[s // 2][n // 2] * ways[s // 2][n // 2])
