# 테트로미노

N, M = map(int, input().split())

paper = []

for _ in range(N):
    paper.append(list(map(int, input().split())))
visited = [[False] * M for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

max_sum = 0

def dfs(x, y, tmp, cnt):
    global max_sum

    if cnt == 4:
        max_sum = max(max_sum, tmp)
        return

    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if nx < 0 or nx >= N or ny < 0 or ny >= M:
            continue
        if not visited[nx][ny]:
            visited[nx][ny] = True
            dfs(nx, ny, tmp + paper[nx][ny], cnt + 1)
            visited[nx][ny] = False

def find_t(x, y):
    global max_sum
    arr = []

    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if nx < 0 or nx >= N or ny < 0 or ny >= M:
            continue
        arr.append(paper[nx][ny])

    if len(arr) == 4:
        arr.sort(reverse=True)
        arr.pop()
        max_sum = max(max_sum, sum(arr) + paper[x][y])
    elif len(arr) == 3:
        max_sum = max(max_sum, sum(arr) + paper[x][y])
    return

for x in range(N):
    for y in range(M):
        visited[x][y] = True
        dfs(x, y, paper[x][y], 1)
        find_t(x, y)
        visited[x][y] = False

print(max_sum)