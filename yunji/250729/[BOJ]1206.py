from collections import deque

n, m, v = map(int, input().split())
graph = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(v, visited, graph):
    visited[v] = True
    print(v, end=' ')
    for i in graph[v]:
        if not visited[i]:
            dfs(i, visited, graph)

def bfs(start, visited, graph):
    queue = deque([start])
    visited[start] = True
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True


# 정점 번호가 작은 순으로 탐색하도록 정렬
for i in range(1, n + 1):
    graph[i].sort()

visited_dfs = [False] * (n + 1)
dfs(v, visited_dfs, graph)
print()

visited_bfs = [False] * (n + 1)
bfs(v, visited_bfs, graph)
print()
