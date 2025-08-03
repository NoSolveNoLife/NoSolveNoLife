from collections import deque
import sys
input = sys.stdin.readline
n, m = map(int, input().split())

graph = [[] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[b].append(a)

def bfs(start):
    q = deque([start])
    visited = [False]*(n+1)
    visited[start] = True
    cnt = 1
    while q:
        v = q.popleft()
        for nv in graph[v]:
            if not visited[nv]:
                visited[nv] = True
                cnt += 1
                q.append(nv)
    return cnt

visited_bfs = [0]*(n+1)
maxv = 0
for v in range(1, n+1):
    visited_bfs[v] = bfs(v)
    if visited_bfs[v] > maxv:
        maxv = visited_bfs[v]

ans = [str(i) for i in range(1, n+1) if visited_bfs[i] == maxv]
print(" ".join(ans))
