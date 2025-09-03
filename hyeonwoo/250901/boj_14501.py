# 퇴사

N = int(input())

counsel = []
for _ in range(N):
    counsel.append(tuple(map(int, input().split())))

dp = [0] * (N + 1)

for i in range(N):
    for j in range(i + counsel[i][0], N + 1):
        if dp[j] < dp[i] + counsel[i][1]:
            dp[j] = dp[i] + counsel[i][1]

print(dp[-1])