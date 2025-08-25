# 테트로미노

import sys
sys.setrecursionlimit(1 << 25)
input = sys.stdin.readline

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

visited = [[False]*M for _ in range(N)]
dirs = [(1,0),(-1,0),(0,1),(0,-1)]
best = 0
max_cell = max(map(max, board))

def dfs(x, y, depth, total):
    global best
    if total + (4 - depth) * max_cell <= best:
        return
    if depth == 4:
        best = max(best, total)
        return
    for dx, dy in dirs:
        nx, ny = x + dx, y + dy
        if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny]:
            visited[nx][ny] = True
            dfs(nx, ny, depth + 1, total + board[nx][ny])
            if depth == 2:  # 'ㅗ' 모양 처리
                dfs(x, y, depth + 1, total + board[nx][ny])
            visited[nx][ny] = False

for i in range(N):
    for j in range(M):
        visited[i][j] = True
        dfs(i, j, 1, board[i][j])
        visited[i][j] = False

print(best)
