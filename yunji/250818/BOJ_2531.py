# 회전초밥 - 투포인터
import sys

input = sys.stdin.readline
N, d, k, c = map(int, input().split())
a = [int(input()) for _ in range(N)]

cnt = [0] * (d + 1)
distinct = 0
left = 0
right = 0
ans = 0

while left < N:
    while right - left < k:
        v = a[right % N]
        if cnt[v] == 0:
            distinct += 1
        cnt[v] += 1
        right += 1

    cur = distinct + (1 if cnt[c] == 0 else 0)
    if cur > ans:
        ans = cur

    lv = a[left % N]
    cnt[lv] -= 1
    if cnt[lv] == 0:
        distinct -= 1
    left += 1

print(ans)


