# 회전 초밥

import sys

input = sys.stdin.readline

N, d, k, c = map(int, input().split())

sushi = []

for _ in range(N):
    sushi.append(int(input()))

sushi = sushi + sushi[:k-1]

max_s = 0

for i in range(N):
    ks = set(sushi[i:i+k])
    cur_s = len(ks)
    if c not in ks:
        cur_s += 1
    max_s = max(max_s, cur_s)

print(max_s)