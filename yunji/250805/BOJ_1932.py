import sys

input = sys.stdin.readline
n = int(input().strip())
tri = [list(map(int, input().split())) for _ in range(n)]

dp = [0] * n
for i in range(n):
    for j in range(i, -1, -1):
        if j == 0:
            dp[j] = dp[j] + tri[i][j]
        elif j == i:
            dp[j] = dp[j-1] + tri[i][j]
        else:
            dp[j] = max(dp[j-1], dp[j]) + tri[i][j]

print(max(dp))
