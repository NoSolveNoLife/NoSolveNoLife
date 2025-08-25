# 회의실 배정 - 틀려서 풀이 봄

import sys
input = sys.stdin.readline

n = int(input())
meetings = [tuple(map(int, input().split())) for _ in range(n)]

# 종료 시간 우선, 같으면 시작 시간
meetings.sort(key=lambda x: (x[1], x[0]))

cnt = 0
end = 0
for s, e in meetings:
    if s >= end:
        cnt += 1
        end = e

print(cnt)
