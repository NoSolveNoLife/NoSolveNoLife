# 동전 0

N, K = map(int, input().split())

money = []
for _ in range(N):
    money.append(int(input()))

answer = 0
i = -1

while K > 0:
    answer += K // money[i]
    K %= money[i]
    i -= 1

print(answer)